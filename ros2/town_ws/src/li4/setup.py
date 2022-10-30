from setuptools import setup

package_name = 'li4'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='wuhao',
    maintainer_email='wuhao@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'li5 = li4.li4:main' # ros2 run <package_name> <executable_name> 这里的package name在上面 exe 就是这里定义的名字 li5，
                                 # 这里第一个li4 表示与setup.py同级文件夹li4, .li4 表示该文件夹下的 li4.py 文件，省略.py ：main 表示入口
        ],
    },
)
