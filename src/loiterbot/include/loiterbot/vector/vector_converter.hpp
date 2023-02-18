#ifndef LOITERBOT_VFFVELOCITY_H
#define LOITERBOT_VFFVELOCITY_H

#include <vector>
#include <cmath>

#include "vector_by_magnitude_angle.hpp"
#include "vector_by_standard_position.hpp"

class VectorConverter
{
public:
   VectorByMagnitudeAngle standardPositionToMagnitudeAngle(const VectorByStandardPosition& vectorByStandardPosition) const;
};

#endif  //LOITERBOT_VFFVELOCITY_H
