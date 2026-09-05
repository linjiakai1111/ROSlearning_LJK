from setuptools import find_packages, setup
from glob import glob
import os

package_name = 'village_li'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share',package_name,'launch'),glob('launch/*.launch.py'))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='line',
    maintainer_email='line@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            "li4_node=village_li.li4:main",#设置两个节点之间需要加一个“,”，否则会和下一行识别为同一个节点
            "li3_node=village_li.li3_free:main"
        ],
    },
)
