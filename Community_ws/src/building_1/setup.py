from setuptools import find_packages, setup
import os
import glob

package_name = 'building_1'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob.glob('launch/*.launch.py'))
    ],
    install_requires=['setuptools', 'community_interfaces'],
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
            "constructor_node=building_1.constructor:main",
            "resident1_node=building_1.resident1:main",
            "management_node=building_1.management:main",
            "tenant_node=building_1.tenant:main"
        ],
    },
)
