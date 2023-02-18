#include "loiterbot/velocity/vff/vector_force_field_calculator.hpp"

[[nodiscard]] VectorByStandardPosition VectorForceFieldCalculator::getVffResult(double laser_angle_min, double laser_angle_increment, std::vector<float>  const & laser_ranges) const {
  const float MINIMUM_IGNORABLE_DISTANCE = 1.0;

  VectorByStandardPosition goal_vector(MINIMUM_IGNORABLE_DISTANCE, 0.0); // Goal: go forward
  double repulsive_vector_endpoint_x = 0.0L;
  double repulsive_vector_endpoint_y = 0.0L;

  long nearest_obstacle_index = std::min_element(laser_ranges.begin(), laser_ranges.end()) - laser_ranges.begin();
  float nearest_obstacle_distance = laser_ranges[nearest_obstacle_index];
  if (nearest_obstacle_distance < MINIMUM_IGNORABLE_DISTANCE) {
    float obstacle_angle = laser_angle_min + laser_angle_increment * nearest_obstacle_index;
    float obstacle_opposite_angle = obstacle_angle + M_PI;
    float repulsive_vector_magnitude = MINIMUM_IGNORABLE_DISTANCE - nearest_obstacle_distance;
    // Calculate cartesian (x, y) components from polar (angle, distance)
    repulsive_vector_endpoint_x = cos(obstacle_opposite_angle) * repulsive_vector_magnitude;
    repulsive_vector_endpoint_y = sin(obstacle_opposite_angle) * repulsive_vector_magnitude;
  }
  // Add the repulsive vector to the goal vector to get the result vector (path to avoid obstacle)
  double result_endpoint_x = repulsive_vector_endpoint_x + goal_vector.getEndpointX();
  double result_endpoint_y = repulsive_vector_endpoint_y + goal_vector.getEndpointY();
  return VectorByStandardPosition(result_endpoint_x, result_endpoint_y);
}
