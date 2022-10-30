"""
编写ROS2节点的5个步骤
1 导入库文件
2 初始化客户端库
3 新建节点对象
4 spin循环节点
5 关闭客户端
"""

"""
编写ROS2publisher的3个步骤
1 导入消息类型
2 声明并创建发布者
3 编写发布逻辑
"""

"""
编写ROS2publisher的3个步骤
1 导入订阅的话题接口类型
2 创建订阅回调函数
2 声明并创建订阅者
3 编写订阅回调处理函数
"""
# 导入库文件
from ast import arg
import rclpy as rc# 这个是python的 ros client library python
from rclpy.node import Node
from std_msgs.msg import String,UInt32

class writerclass(Node):
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info('i am '+name)
        self.pub_novel = self.create_publisher(msg_type=String,topic='items_from_li4',qos_profile=10)# 这个qos参数是大小 
        self.sub = self.create_subscription(msg_type=UInt32,topic='money_from_wu5',qos_profile=10,callback=self.sub_time_callback)
        self.sub_want_more = self.create_subscription(msg_type=String,topic='want_more_items_from_li4',qos_profile=10,callback=self.sub_want_more_callback)
        self.timer = self.create_timer(timer_period_sec=5,callback=self.pub_time_callback)
        self.i =0
        self.account=0
    def pub_time_callback(self):
        msg = String()
        msg.data =  'li4_pub {}'.format(self.i)
        self.pub_novel.publish(msg)
        self.get_logger().info('li4 has published' + msg.data)
        self.i +=1

    def sub_time_callback(self,money):
        self.account += money.data
        self.get_logger().info('receive {} money and intotal {}'.format(money.data,self.account))
    
    def sub_want_more_callback(self,info):
        self.get_logger().info('receive'+info.data)