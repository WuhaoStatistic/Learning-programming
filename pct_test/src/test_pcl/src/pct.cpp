#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "laser_geometry/laser_geometry.hpp"
#include "pcl_conversions/pcl_conversions.h"
#include <math.h>
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "sensor_msgs/point_cloud2_iterator.hpp"


class FilterNode : public rclcpp::Node
{
public:
    // construct fucntion create a pointcloud publisher
    // and also a laser scan sub
    FilterNode(): Node("filter_node")
    {
      filt_pub = this->create_publisher<sensor_msgs::msg::PointCloud2>("filt", rclcpp::QoS(rclcpp::KeepLast(10)));
      // pcl library against BOOST, so we can not use place holder. Lambda function is used here.
      scan_sub= this->create_subscription<sensor_msgs::msg::LaserScan>("scan", rclcpp::SensorDataQoS(),
                                                                        [this]
                                                                        (sensor_msgs::msg::LaserScan::SharedPtr scan)
                                                                        {scanCb(scan);}
                                                                      );
      this->declare_parameter("frame_id");
      this->get_parameter_or<std::string>("frame_id", frame_id, "filter");
    }
    ~FilterNode(){}
private:
    void scanCb(sensor_msgs::msg::LaserScan::SharedPtr scan) 
    {
        auto pub_msg = std::make_shared<sensor_msgs::msg::PointCloud2>();
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = boost::make_shared<pcl::PointCloud<pcl::PointXYZ>>();
        int count = scan->scan_time / scan->time_increment;
        laser_geometry::LaserProjection projector;
        projector.projectLaser(*scan,*pub_msg);
        pub_msg->header.frame_id = frame_id;
	      pcl::fromROSMsg(*pub_msg, *cloud);
        printf("successful");
        printf("%d",count);
        printf("\n");
    }
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr filt_pub;
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_sub;
    std::string frame_id;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);

  auto node = std::make_shared<FilterNode>();

  rclcpp::spin(node);

  rclcpp::shutdown();


  return 0;
}
