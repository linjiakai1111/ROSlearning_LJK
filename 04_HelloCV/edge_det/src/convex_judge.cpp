#include"convex_judge.hpp"

std::vector<Mat> edge_extract(Mat& ori_img_src,int height,int width){
  if(ori_img_src.empty()){
      cout << "图片为空\n" << endl;
      return {};
  }
  std::vector<Mat> img_container;
  Mat img_src;
  Mat edge_img;
  std::vector<Point2f> con_pts;
  Mat convex_back(Size(width,height),0,CV_8UC1);
  Mat corner_img = convex_back.clone();
  std::vector<Vec4i> Hough_line;
  auto start = std::chrono::steady_clock::now();
    //高斯滤波
    convex_back.setTo(Scalar(0));
    corner_img.setTo(Scalar(0));
    con_pts.clear();
    GaussianBlur(ori_img_src, img_src, Size(0,0), 1.5);
    // Canny边缘检测
    Canny(
      img_src,
      edge_img,
      150,
      200
    );
    if(USING_HARRIS){
      cv::goodFeaturesToTrack(
        edge_img,
        con_pts,
        100,
        0.01,
        10
      );
      for(auto& pt:con_pts){
      circle(corner_img,pt,1,255,-1);
      img_container.emplace_back(edge_img);
      img_container.emplace_back(corner_img);
    }
    }
    if(USING_HOUGH){
      HoughLinesP(edge_img,Hough_line,1,CV_PI/180,40,20,30);
      for(auto& l:Hough_line){
        Point pt1,pt2;
        pt1.x = l[0];
        pt1.y = l[1];
        pt2.x = l[2];
        pt2.y = l[3];
        circle(corner_img,pt1,3,255,-1);
        circle(corner_img,pt2,3,255,-1);
        con_pts.emplace_back(pt1);
        con_pts.emplace_back(pt2);
        line(
          corner_img,
          pt1,
          pt2,
          Scalar(255),
          1,
          LINE_AA,
          0
        );
      }
      img_container.emplace_back(edge_img);
      img_container.emplace_back(corner_img);
    }
    cout << "角点数：" << con_pts.size() << endl;
    if(USING_CONVEX){
      if(con_pts.empty()){
        return img_container;
      }
      convex_back = Find_ConvexHull(convex_back,height,width,con_pts);
      img_container.emplace_back(convex_back);
    }
  auto end = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
  cout << "性能：" << duration.count() << " ms" <<endl;
  cout << "--------" << endl;
  return img_container;
}

int GRN(int min,int max){
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution dist(min,max);
  return dist(gen);
}

double line_pt_dist(double k,double b,Point pt){
  return abs(k*pt.x-pt.y+b)/sqrt(pow(k,2)+1);
}

Mat Find_ConvexHull(Mat& convex_back,int height,int width,const std::vector<Point2f>& con_pts){
  std::vector<Point2f> out_pts;
  convexHull(con_pts,out_pts);
  int count = 0;
  for(auto &pt:out_pts){
    circle(convex_back,pt,3,255,-1);
    count++;
  }
  std::cout << "凸包点数：" << count << endl;
  for(int i=0;i<out_pts.size();i++){
    Point2f start = out_pts.at(i);
    Point2f termination = (i==out_pts.size()-1) ? out_pts.front() : out_pts.at(i+1);
    line(
      convex_back,
      start,
      termination,
      Scalar(255),
      1,
      LINE_AA,
      0
    );
  }
  return convex_back;
}