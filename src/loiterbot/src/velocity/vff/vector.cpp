#include <math.h>
#include "loiterbot/velocity/vff/vector.hpp"

double Vector::getMagnitude() {
  return sqrt(endpoint_x_*endpoint_x_ + endpoint_y_*endpoint_y_);
}

double Vector::getAngle() {
  return atan2(endpoint_y_, endpoint_x_);
}
