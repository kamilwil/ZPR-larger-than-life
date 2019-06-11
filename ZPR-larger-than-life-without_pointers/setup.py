from setuptools import setup
from setuptools import find_packages

setup(
	name='ZPR-larger-than-life',
	description='Larger than Life game implementation',
	license='MIT',
	zip_safe=False,
	packages=find_packages('src'),
	package_dir={'':'src'}
)