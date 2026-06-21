from setuptools import find_packages, setup

package_name = '1hz_hello'

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
        # <!-- 実行名 = モジュール名.ファイル名:関数 -->
        'hello1hz = 1hz_hello.hello:main',
        ],
    },
)
