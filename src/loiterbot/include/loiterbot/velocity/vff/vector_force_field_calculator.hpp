#ifndef LOITERBOT_VECTOR_FORCE_FIELD_CALCULATOR_HPP
#define LOITERBOT_VECTOR_FORCE_FIELD_CALCULATOR_HPP

#include <algorithm>
#include <cmath>
#include <vector>

#include "loiterbot/vector/vector_by_standard_position.hpp"

class VectorForceFieldCalculator
{
public:
  [[nodiscard]] VectorByStandardPosition getVffResult(double laser_angle_min, double laser_angle_increment, std::vector<float>  const & laser_ranges) const;
};

#endif  // LOITERBOT_VECTOR_FORCE_FIELD_CALCULATOR_HPP