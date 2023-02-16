#ifndef LOITERBOT_VFF_HPP
#define LOITERBOT_VFF_HPP \
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include <math.h>

class Vff {
public:
  [[nodiscard]] std::vector<float> getVffResult(double laser_angle_min, double laser_angle_increment, std::vector<float>  const & laser_ranges) const;
};

#endif // LOITERBOT_VFF_HPP