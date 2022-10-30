这个文件夹描述了如何在ros2里构建 node。分为python和c++

功能：
python 节点定时提供货物 C++结点接收货物并付钱 python结点收钱并结算。  
c++结点定时向python结点索取货物 python结点接收并打印接收信息。  

ros2中的话题名字很关键，话题是以名字作为区分的，话题并不是一个实际存在的实体，而是作为每一个publisher或者subscriber 的一个属性存在的，隶属于同一个topic的node能够互相通信。

创建中的非编写逻辑代码流程
**python**
首先创建工作空间和底下src目录 并进入src目录  
创建包 ros2 pkg create --build-type ament_python --dependencies rclpy  
其次编写python 文件，头文件和运行文件分开编写。 
在setup.py中 的 entry_point 添加  
```
entry_points={
        'console_scripts': [
            'li5 = li4.li4:main' # ros2 run <package_name> <executable_name> 这里的package name在上面 exe 就是这里定义的名字 li5，
                                 # 这里第一个li4 表示与setup.py同级文件夹li4, .li4 表示该文件夹下的 li4.py 文件，省略.py ：main 表示入口
        ],
    },
```
之后回到 src同级目录 colcon build 再 source install/local_setup.bash  
运行的时候 我们设置的入口变量名为li5，包名为li4 所以就是 `ros2 run li4 li5`
**c++**
c++ 过程大同小异。区别在于我们使用的是CMakeList文件。
一样是在src目录下创建包，包会生成一个文件夹和包名相同，该文件夹下有 /include ,/src ,CMakeList.txt 和 package.xml。我们的头文件会放在include下，源文件放在src下，这一点和普通c++工程是
一致的。问题在于编译器不如那些IDE里面的那么智能，我们需要加上
```
INCLUDE_DIRECTORIES(include/wu5) #将头文件包括进路径
add_executable(wu5_node src/wu5.cpp) # 创建可执行文件
ament_target_dependencies(wu5_node rclcpp) # 设置dependency
install(  #要手动设置安装路径 否则 ros的install里找不到这个包 无法使用ros run
  TARGETS
  wu5_node
  DESTINATION lib/${PROJECT_NAME}
)
```
运行的时候 我们设置的入口变量名为wu5_node，包名为wu5 所以就是 `ros2 run wu5 wu5_node`

