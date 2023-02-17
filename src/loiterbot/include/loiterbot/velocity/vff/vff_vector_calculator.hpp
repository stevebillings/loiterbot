#ifndef LOITERBOT_VFF_VECTOR_CALCULATOR_HPP
#define LOITERBOT_VFF_VECTOR_CALCULATOR_HPP

#include <vector>
#include <cmath>
#include <algorithm>
#include "vector_by_standard_position.hpp"

class VffVectorCalculator
{
public:
  [[nodiscard]] VectorByStandardPosition getVffResult(double laser_angle_min, double laser_angle_increment, std::vector<float>  const & laser_ranges) const;
};

#endif  // LOITERBOT_VFF_VECTOR_CALCULATOR_HPP