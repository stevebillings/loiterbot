#ifndef LOITERBOT_VECTORBYMAGNITUDEDIRECTION_H
#define LOITERBOT_VECTORBYMAGNITUDEDIRECTION_H

class VectorByMagnitudeAngle
{
public:
  VectorByMagnitudeAngle(double magnitude, double angle_radians)
     : magnitude_(magnitude)
     , angle_radians_(angle_radians) {};
  double getMagnitude() const;
  double getAngleRadians() const;
private:
  double magnitude_;
  double angle_radians_;
};

#endif  //LOITERBOT_VECTORBYMAGNITUDEDIRECTION_H
