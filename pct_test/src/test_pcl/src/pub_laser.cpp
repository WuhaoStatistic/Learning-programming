#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include "math.h"
#include <random>
#include <chrono>
#define DEG2RAD(x) ((x)*M_PI/180.)
using namespace std;
class Pub_laser :public rclcpp::Node
{
public:
    Pub_laser():Node("laser_pub")
    {
       scan_pub = this->create_publisher<sensor_msgs::msg::LaserScan>("scan", rclcpp::QoS(rclcpp::KeepLast(10))); 
       timer_ = this->create_wall_timer(1000ms, std::bind(&Pub_laser::timer_callback, this));
    }
    
    void timer_callback()
    {
       auto scan_msg = std::make_shared<sensor_msgs::msg::LaserScan>();
       scan_msg->header.stamp = this->now();
       scan_msg->header.frame_id = "laser_scan"; 
       scan_msg->angle_min = DEG2RAD(0.0f);
       scan_msg->angle_max = DEG2RAD(359.0f);
       scan_msg->angle_increment = (scan_msg->angle_max - scan_msg->angle_min) / (double)(this->node_count-1);
       scan_msg->scan_time = 0.12351252;
       scan_msg->time_increment = scan_msg->scan_time / (double)(this->node_count-1);
       scan_msg->range_min = 0.15;
       scan_msg->range_max = 8;
       scan_msg->intensities.resize(this->node_count);
       scan_msg->ranges.resize(this->node_count);
       default_random_engine e;
       uniform_real_distribution<float> r(0.2, 7.5);
       uniform_real_distribution<float> ii(30, 60);
       for(int i=0; i<this->node_count; i++)
        {
          scan_msg->intensities[i] = r(e);
          scan_msg->ranges[i] = ii(e);
        }
       scan_pub->publish(*scan_msg);
    }
    ~Pub_laser(){}
private:
    rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr scan_pub;
    rclcpp::TimerBase::SharedPtr timer_;
    const static int node_count = 1640;
    float ran [node_count];
    float inten [node_count];
};


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Pub_laser>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}