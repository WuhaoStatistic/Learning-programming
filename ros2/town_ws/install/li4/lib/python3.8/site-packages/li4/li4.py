"""
编写ROS2节点的5个步骤
1 导入库文件
2 初始化客户端库
3 新建节点对象
4 spin循环节点
5 关闭客户端
"""

# 导入库文件
import rclpy as rc# 这个是python的 ros client library python
from rclpy.node import Node
from .li4_oop import writerclass # 引用同级目录
#入口函数
def main(args=None):

    rc.init(args=args) # 初始化客户端库
    li4 = writerclass('li4') # 新建节点对象 ros2 nodelist 显示的就是这个名字
    rc.spin(li4)
    rc.shutdown()
