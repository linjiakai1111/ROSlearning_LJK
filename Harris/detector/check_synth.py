#!/usr/bin/env python3
# =============================================================================
#  check_synth.py —— 用合成真值严格检验 cube_pose 的输出（含符号/平面偏移检查）
#  用法: python3 check_synth.py <prefix> [cube_pose 额外参数...]
#  检查项:
#    1) 是否检出 6 个轮廓顶点
#    2) 6 个顶点与真值顶点的最小权匹配误差（均值/最大, px）
#    3) 立方体中心误差 (mm)
#    4) 三个可见面：法向**有向**夹角(度) + 平面偏移 |d - d_gt| (mm)
#    5) 重投影 RMS (px)
#  退出码 0 = 通过
# =============================================================================
import subprocess, sys, math, re, os, itertools

def parse_gt(path):
    gt = {'hex': [], 'face': [], 'corner3d': []}
    for line in open(path):
        t = line.split()
        if not t: continue
        k = t[0]
        if k == 'hex':    gt['hex'].append((float(t[1]), float(t[2])))
        elif k == 'faceN': gt['face'].append(((float(t[1]), float(t[2]), float(t[3])), float(t[5])))
        elif k == 'corner3d': gt['corner3d'].append((float(t[1]), float(t[2]), float(t[3])))
        else: gt[k] = [float(x) for x in t[1:]]
    return gt

def parse_out(out):
    r = {'v': [], 'planes': [], 'center': None, 'rms': None, 'topN': None,
         'corners': [], 'v3d': [], 'vcid': [], 'near': None, 'hidden': None}
    for line in out.splitlines():
        m = re.match(r'\s+v(\d+)=\(([-\d.]+),([-\d.]+)\)', line)
        if m: r['v'].append((float(m.group(2)), float(m.group(3))))
        m = re.search(r'中心 t=\[([-\d.e+]+), ([-\d.e+]+), ([-\d.e+]+)\]', line)
        if m: r['center'] = tuple(float(x) for x in m.groups())
        m = re.search(r'重投影RMS=([\d.]+)px', line)
        if m: r['rms'] = float(m.group(1))
        m = re.search(r'平面\[(\S+?)\] n=\[([-\d.e+]+), ([-\d.e+]+), ([-\d.e+]+)\]  n·X=([-\d.e+]+)', line)
        if m: r['planes'].append((m.group(1), (float(m.group(2)), float(m.group(3)), float(m.group(4))), float(m.group(5))))
        m = re.match(r'\s+corner#(\d+) = \[([-\d.e+]+), ([-\d.e+]+), ([-\d.e+]+)\]', line)
        if m: r['corners'].append((float(m.group(2)), float(m.group(3)), float(m.group(4))))
        m = re.search(r'近角=\[([-\d.e+]+), ([-\d.e+]+), ([-\d.e+]+)\]', line)
        if m: r['near'] = (float(m.group(1)), float(m.group(2)), float(m.group(3)))
        m = re.search(r'被遮挡角=\[([-\d.e+]+), ([-\d.e+]+), ([-\d.e+]+)\]', line)
        if m: r['hidden'] = (float(m.group(1)), float(m.group(2)), float(m.group(3)))
        m = re.match(r'\s+v(\d+)=\(([-\d.]+),([-\d.]+)\)\s+-> 角点#(\d+)', line)
        if m: r['vcid'].append(int(m.group(4)))
    return r

def ang(u, v):
    # 先归一化：打印出来的向量可能只有 3~6 位有效数字，不归一化会让 acos 在 0 度附近爆掉
    nu = math.sqrt(sum(x*x for x in u)); nv = math.sqrt(sum(x*x for x in v))
    if nu == 0 or nv == 0: return 180.0
    d = max(-1.0, min(1.0, sum(a*b for a, b in zip(u, v)) / (nu*nv)))
    return math.degrees(math.acos(d))

def main():
    prefix = sys.argv[1]
    extra  = sys.argv[2:]
    gt = parse_gt(prefix + '.txt')
    img = prefix + '.png' if os.path.exists(prefix + '.png') else prefix + '.jpg'
    args = list(extra)
    if '--with-roi' in args:                      # 模拟 YOLO：用真值外接框 + 20% 外扩
        args.remove('--with-roi')
        xs = [p[0] for p in gt['hex']]; ys = [p[1] for p in gt['hex']]
        x0, y0, x1, y1 = min(xs), min(ys), max(xs), max(ys)
        w, h = x1-x0, y1-y0
        x0 -= 0.2*w; y0 -= 0.2*h; w *= 1.4; h *= 1.4
        args += ['--roi', f'{x0:.0f},{y0:.0f},{w:.0f},{h:.0f}', '--pad', '0.05']
        print(f"[ROI] {x0:.0f},{y0:.0f},{w:.0f},{h:.0f}")
    out = subprocess.run(['./cube_pose', img, '--nogui'] + args,
                         capture_output=True, text=True).stdout
    r = parse_out(out)
    print(f"=== {prefix} ===")

    if len(r['v']) != 6:
        print(f"[失败] 检出顶点数 = {len(r['v'])}（期望 6）")
        return 1

    best = min((max(math.dist(r['v'][i], gt['hex'][p[i]]) for i in range(6)),
                [math.dist(r['v'][i], gt['hex'][p[i]]) for i in range(6)])
               for p in itertools.permutations(range(6)))
    vmax, verr = best
    print(f"顶点误差: 均值={sum(verr)/6:.3f}px 最大={vmax:.3f}px")

    ce = math.dist(r['center'], gt['tvec']) * 1000
    print(f"中心误差: {ce:.2f} mm")

    # 逐个可见面：找有向夹角最小的真值面
    worst_ang, worst_d = 0, 0
    for name, n, d in r['planes']:
        j = min(range(len(gt['face'])), key=lambda k: ang(n, gt['face'][k][0]))
        a = ang(n, gt['face'][j][0])
        dd = abs(d - gt['face'][j][1]) * 1000
        worst_ang = max(worst_ang, a); worst_d = max(worst_d, dd)
        print(f"  面[{name}]: 有向法向误差={a:.2f}°  平面偏移误差={dd:.2f}mm")
    print(f"面最大: 法向={worst_ang:.2f}° 偏移={worst_d:.2f}mm")
    # 角点物理位置：与真值 8 个角点做集合匹配（编号约定不同，比集合即可）
    e_corner = -1
    if gt.get('corner3d') and len(r['corners']) == 8:
        import itertools as it2
        best2 = min(max(math.dist(r['corners'][i], gt['corner3d'][p[i]]) for i in range(8))
                    for p in it2.permutations(range(8)))
        e_corner = best2 * 1000
        print(f"角点物理位置误差(8 个角点集合匹配): 最大 {best2*1000:.2f} mm")
    else:
        print("[警告] 未取到 8 个角点物理位置")
    # 编号约定：j>=4 应是顶面四角（在朝上方一侧）
    conv_ok = True
    if len(r['corners']) == 8 and r['topN']:
        hs = gt['cubeSize'] / 2
        for j, c in enumerate(r['corners']):
            d = sum((c[k] - r['center'][k]) * r['topN'][k] for k in range(3))
            if (j >= 4 and d < 0.5*hs) or (j < 4 and d > -0.5*hs):
                conv_ok = False
    print("角点编号约定(j>=4 为顶面):", "正确" if conv_ok else "错误")
    # 自洽检查：把"角点物理位置"按内参投影回去，应当落在检测到的那个像素上
    intr = {}
    for i, a in enumerate(extra):
        if a in ('--fx', '--fy', '--cx', '--cy') and i + 1 < len(extra):
            intr[a[2:]] = float(extra[i+1])
    v3d_err = -1
    if len(intr) == 4 and len(r['vcid']) == len(r['v']) and len(r['corners']) == 8:
        fx, fy, cx, cy = intr['fx'], intr['fy'], intr['cx'], intr['cy']
        v3d_err = 0.0
        for i, cid in enumerate(r['vcid']):
            p = r['corners'][cid]
            if p[2] <= 0: v3d_err = 1e6; break
            u = fx * p[0] / p[2] + cx
            v = fy * p[1] / p[2] + cy
            v3d_err = max(v3d_err, math.dist((u, v), r['v'][i]))
        print(f"角点3D->像素重投影自洽误差: 最大 {v3d_err:.2f} px")
    print(f"重投影RMS: {r['rms']} px")

    ok = (vmax < 1.5) and (worst_ang < 1.0) and (worst_d < 3.0) and \
         (r['rms'] is not None and r['rms'] < 0.8) and (ce < 3.0) and \
         (e_corner >= 0 and e_corner < 3.0) and conv_ok and \
         (0 <= v3d_err < 2.0)
    print("结论:", "通过" if ok else "未通过")
    return 0 if ok else 1

sys.exit(main())
