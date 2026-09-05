from setuptools import find_packages
from setuptools import setup

setup(
    name='community_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('community_interfaces', 'community_interfaces.*')),
)
