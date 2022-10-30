#pragma once
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <string>
#include "std_msgs/msg/u_int32.hpp"
#include <chrono>
using namespace rclcpp;
using namespace std;
using placeholders::_1;
class Wu5 : public Node
{
private:
    Subscription<std_msgs::msg::String>::SharedPtr sub_novel;
    Publisher<std_msgs::msg::UInt32>::SharedPtr pub_money;
    Publisher<std_msgs::msg::String>::SharedPtr pub_want_more;
    TimerBase::SharedPtr pub_want_more_timer;
    
    void novel_receive_callback(const std_msgs::msg::String::SharedPtr novels)
    {
        RCLCPP_INFO(this->get_logger(),"received from li4:%s. ",novels->data.c_str());
        std_msgs::msg::UInt32 money;
        money.data=10;
        pub_money ->publish(money);
    }

    void pub_want_more_callback()
    {
        RCLCPP_INFO(this->get_logger(),"start to ask for more");
        std_msgs::msg::String msg;
        msg.data = "give me more pls";
        pub_want_more->publish(msg);
    }
    
public:
    Wu5(string name);
    ~Wu5();
    
};

Wu5::Wu5(string name):Node(name)
{
    RCLCPP_INFO(this->get_logger(),"i am"+name);
    // topic 的名字是运行中的ros系统通用的 数据发布接收是通过相同的topic名字联系在一起的，
    // 也就是说 node之间通过topic的名字绑定在一起
    sub_novel = this->create_subscription<std_msgs::msg::String>("items_from_li4",10,bind(&Wu5::novel_receive_callback,this,_1));
    pub_money = this->create_publisher<std_msgs::msg::UInt32>("money_from_wu5",10);
    pub_want_more = this->create_publisher<std_msgs::msg::String>("want_more_items_from_li4",10);
    pub_want_more_timer = this->create_wall_timer(std::chrono::seconds(2),bind(&Wu5::pub_want_more_callback,this));
}

Wu5::~Wu5()
{
}


