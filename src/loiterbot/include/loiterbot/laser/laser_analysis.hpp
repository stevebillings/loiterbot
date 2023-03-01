// Copyright 2023 Steve Billings
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef LOITERBOT__LASER__LASER_ANALYSIS_HPP_
#define LOITERBOT__LASER__LASER_ANALYSIS_HPP_

#include <string>
#include <vector>

class LaserAnalysis
{
public:
  LaserAnalysis(
    const bool in_sight, const bool near, const bool too_near,
    const double obstacle_angle_radians_rel_to_straight, const double obstacle_distance)
  : in_sight_(in_sight),
    near_(near),
    too_near_(too_near),
    obstacle_angle_rel_to_straight_radians_(obstacle_angle_radians_rel_to_straight),
    obstacle_distance_(obstacle_distance)
  {
  }
  LaserAnalysis(const LaserAnalysis & src)
  : in_sight_(src.isInSight()),
    near_(src.isNear()),
    too_near_(src.isTooNear()),
    obstacle_angle_rel_to_straight_radians_(src.getObstacleAngleRelToStraightRadians()),
    obstacle_distance_(src.getObstacleDistance())
  {
  }
  bool isInSight() const;
  bool isNear() const;
  bool isTooNear() const;
  double getObstacleAngleRelToStraightRadians() const;
  double getObstacleDistance() const;
  bool isToRight() const;
  std::string toString() const;

private:
  const bool in_sight_;
  const bool near_;
  const bool too_near_;
  const double obstacle_angle_rel_to_straight_radians_;
  const double obstacle_distance_;
};

#endif  // LOITERBOT__LASER__LASER_ANALYSIS_HPP_
