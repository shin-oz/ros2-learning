from setuptools import find_packages, setup

package_name = 'hello_10hz_tandl'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='shinnosuke',
    maintainer_email='purishin1215@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'talker = hello_10hz_tandl.talker:main',
            'listner = hello_10hz_tandl.listner:main',
        ],
    },
)
