#ifndef LOITERBOT_VECTOR_HPP
#define LOITERBOT_VECTOR_HPP

class Vector {
public:
  Vector(double endpoint_x, double endpoint_y) : endpoint_x_(endpoint_x), endpoint_y_(endpoint_y) {};
  double getAngle();
  double getMagnitude();
private:
  double endpoint_x_;
  double endpoint_y_;
};

#endif // LOITERBOT_VECTOR_HPP
