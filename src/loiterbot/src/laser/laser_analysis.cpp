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

//
// Created by stevebillings on 11/21/22.
//

#include "laser_analysis.h"

const NearestSighting LaserAnalysis::getNearestSighting() const
{
  return nearestSighting_;
}

bool LaserAnalysis::isInSight() const
{
  return in_sight_;
}

bool LaserAnalysis::isNear() const
{
  return near_;
}

bool LaserAnalysis::isTooNear() const
{
  return too_near_;
}

bool LaserAnalysis::isToRight() const
{
  return to_right_;
}

unsigned long LaserAnalysis::getDeltaFromPerpendicular() const
{
  return delta_from_perpendicular_;
}

std::string LaserAnalysis::toString() const
{
  nearestSighting_.getRangeIndex();
  nearestSighting_.getRange();
  std::string description = "";

  description.append("nearest range index: ");
  description.append(std::to_string(nearestSighting_.getRangeIndex()));

  description.append("; nearest range: ");
  description.append(std::to_string(nearestSighting_.getRange()));

  description.append("; in sight?: ");
  description.append(std::to_string(in_sight_));

  description.append("; near?: ");
  description.append(std::to_string(near_));

  description.append("; too near?: ");
  description.append(std::to_string(too_near_));

  description.append("; to right?: ");
  description.append(std::to_string(to_right_));

  description.append("; delta from perpendicular: ");
  description.append(std::to_string(delta_from_perpendicular_));

  return description;
}
