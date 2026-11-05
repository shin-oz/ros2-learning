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
    description='Minimal rclpy talker / listener exchanging std_msgs/String on /chatter',
    license='Apache-2.0',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'talker = hello_10hz_tandl.talker:main',
            'listener = hello_10hz_tandl.listener:main',
        ],
    },
)
