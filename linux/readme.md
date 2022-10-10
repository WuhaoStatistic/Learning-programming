安装Linux第一步  
sudo apt update  
sudo apt build-ennential  
老版Linux中使用的g++之类的工具包build-essential  
编译命令 g++ -o [target file name] [source file name] 例如`g++ -o res.out helloSLAM.cpp`  

cmake
```
# 声明要求的 cmake 最低版本
cmake_minimum_required( VERSION 2.8 )

# 声明一个 cmake 工程
project( HelloSLAM )

# 设置编译模式
set( CMAKE_BUILD_TYPE "Debug" )

# 添加一个可执行程序
# 语法：add_executable( 程序名 源代码文件 ）
add_executable( helloSLAM helloSLAM.cpp )

# 添加一个库
add_library( hello libHelloSLAM.cpp )
# 共享库
add_library( hello_shared SHARED libHelloSLAM.cpp )

add_executable( useHello useHello.cpp )
# 将库文件链接到可执行程序上
target_link_libraries( useHello hello_shared )
```
