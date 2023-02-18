#include "loiterbot/vector/vector_converter.hpp"

VectorByMagnitudeAngle VectorConverter::standardPositionToMagnitudeAngle(const VectorByStandardPosition& vectorByStandardPosition) const {
  double magnitude = sqrt(vectorByStandardPosition.getEndpointX()*vectorByStandardPosition.getEndpointX()
                          + vectorByStandardPosition.getEndpointY()*vectorByStandardPosition.getEndpointY());

  double angleRadians = atan2(vectorByStandardPosition.getEndpointY(), vectorByStandardPosition.getEndpointX());
  return VectorByMagnitudeAngle(magnitude, angleRadians);
}