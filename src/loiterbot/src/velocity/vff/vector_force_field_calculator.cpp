#include "loiterbot/velocity/vff/vector_force_field_calculator.hpp"

[[nodiscard]] VectorByStandardPosition VectorForceFieldCalculator::getVffResult(const double obstacle_angle_radians, const double obstacle_distance) const {
  const float MINIMUM_IGNORABLE_DISTANCE = 4.0;
  // TODO min dist and goal should not be hard coded:
  VectorByStandardPosition goal_vector(MINIMUM_IGNORABLE_DISTANCE, 0.0); // Goal: go forward
  double repulsive_vector_endpoint_x = 0.0L;
  double repulsive_vector_endpoint_y = 0.0L;

  if (obstacle_distance < MINIMUM_IGNORABLE_DISTANCE) {
    float obstacle_opposite_angle = obstacle_angle_radians + M_PI;
    float repulsive_vector_magnitude = MINIMUM_IGNORABLE_DISTANCE - obstacle_distance;
    // Calculate cartesian (x, y) components from polar (angle, distance)
    repulsive_vector_endpoint_x = cos(obstacle_opposite_angle) * repulsive_vector_magnitude;
    repulsive_vector_endpoint_y = sin(obstacle_opposite_angle) * repulsive_vector_magnitude;
  }
  // Add the repulsive vector to the goal vector to get the result vector (path to avoid obstacle)
  double result_endpoint_x = repulsive_vector_endpoint_x + goal_vector.getEndpointX();
  double result_endpoint_y = repulsive_vector_endpoint_y + goal_vector.getEndpointY();
  return VectorByStandardPosition(result_endpoint_x, result_endpoint_y);
}
