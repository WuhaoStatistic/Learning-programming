#include "rclcpp/rclcpp.hpp"
#include "wu5.h"

int main(int argc,char ** argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<Wu5>("wuhao");
    rclcpp::spin(node);
    rclcpp::shutdown();
}