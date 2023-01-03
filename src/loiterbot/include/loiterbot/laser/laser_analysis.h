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

#ifndef OBSTACLE_HUGGER_LASER_ANALYSIS_H
#define OBSTACLE_HUGGER_LASER_ANALYSIS_H

#include <string>
#include <vector>
#include "loiterbot/obstacle/nearest_sighting.h"

class LaserAnalysis
{
public:
  LaserAnalysis(
    const NearestSighting & nearestSighting, const bool in_sight, const bool near,
    const bool too_near, const bool to_right, const unsigned long delta_from_perpendicular)
  : nearestSighting_(nearestSighting),
    in_sight_(in_sight),
    near_(near),
    too_near_(too_near),
    to_right_(to_right),
    delta_from_perpendicular_(delta_from_perpendicular){};
  LaserAnalysis(const LaserAnalysis & src)
  : nearestSighting_(src.getNearestSighting()),
    in_sight_(src.isInSight()),
    near_(src.isNear()),
    too_near_(src.isTooNear()),
    to_right_(src.isToRight()),
    delta_from_perpendicular_(src.getDeltaFromPerpendicular()){};
  const NearestSighting getNearestSighting() const;
  bool isInSight() const;
  bool isNear() const;
  bool isTooNear() const;
  bool isToRight() const;
  unsigned long getDeltaFromPerpendicular() const;
  std::string toString() const;

private:
  const NearestSighting nearestSighting_;
  const bool in_sight_;
  const bool near_;
  const bool too_near_;
  const bool to_right_;
  const unsigned long delta_from_perpendicular_;
};

#endif  // OBSTACLE_HUGGER_LASER_ANALYSIS_H
