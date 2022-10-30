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

class writerclass(Node):
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info('i am '+name)
