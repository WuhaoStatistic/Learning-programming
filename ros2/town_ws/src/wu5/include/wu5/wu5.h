#pragma once
#include "rclcpp/rclcpp.hpp"
#include <string>
using namespace rclcpp;
using namespace std;
class Wu5 : public Node
{
private:
    /* data */
public:
    Wu5(string name);
    ~Wu5();
};

Wu5::Wu5(string name):Node(name)
{
    RCLCPP_INFO(this->get_logger(),"i am"+name);
}

Wu5::~Wu5()
{
}


