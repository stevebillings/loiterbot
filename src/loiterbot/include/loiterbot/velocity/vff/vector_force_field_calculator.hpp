#ifndef LOITERBOT_VECTOR_FORCE_FIELD_CALCULATOR_HPP
#define LOITERBOT_VECTOR_FORCE_FIELD_CALCULATOR_HPP

#include <algorithm>
#include <cmath>
#include <vector>

#include "loiterbot/vector/vector_by_standard_position.hpp"

class VectorForceFieldCalculator
{
public:
  [[nodiscard]] VectorByStandardPosition getVffResult(
    const double obstacle_angle_radians, const double obstacle_distance) const;
};

#endif  // LOITERBOT_VECTOR_FORCE_FIELD_CALCULATOR_HPP
