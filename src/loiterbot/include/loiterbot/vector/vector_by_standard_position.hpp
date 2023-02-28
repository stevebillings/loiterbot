#ifndef LOITERBOT_VECTOR_BY_STANDARD_POSITION_HPP
#define LOITERBOT_VECTOR_BY_STANDARD_POSITION_HPP

class VectorByStandardPosition
{
public:
  VectorByStandardPosition(double endpoint_x, double endpoint_y)
  : endpoint_x_(endpoint_x), endpoint_y_(endpoint_y)
  {
  }
  double getEndpointX() const;
  double getEndpointY() const;

private:
  double endpoint_x_;
  double endpoint_y_;
};

#endif  // LOITERBOT_VECTOR_BY_STANDARD_POSITION_HPP
