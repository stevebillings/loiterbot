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

#include "velocity_calculator.h"

VelocityCalculator::VelocityCalculator()
{
}

Velocity VelocityCalculator::toApproach(const LaserCharacteristics& laser_characteristics,
                                        const LaserAnalysis& laser_analysis) const
{
  if (laser_analysis.isNear() || laser_analysis.isTooNear())
  {
    return Velocity(0.0, 0.0);
  }
  double x = laser_analysis.getNearestSighting().getRange() / 4.0;
  double yaw;
  if (laser_analysis.isToRight())
  {
    long index_offset = laser_characteristics.getStraightIndex() - laser_analysis.getNearestSighting().getRangeIndex();
    yaw = (double)index_offset * DELTA_TO_YAW_MULTIPLIER * -1.0;
  }
  else
  {
    long index_offset = laser_analysis.getNearestSighting().getRangeIndex() - laser_characteristics.getStraightIndex();
    yaw = (double)index_offset * DELTA_TO_YAW_MULTIPLIER;
  }
  return Velocity(x, yaw);
}
Velocity VelocityCalculator::toParallel(const LaserAnalysis& laser_analysis) const
{
  double yaw;
  if (laser_analysis.isInSight())
  {
    if (laser_analysis.isToRight())
    {
      yaw = laser_analysis.getDeltaFromPerpendicular() * DELTA_TO_YAW_MULTIPLIER;
    }
    else
    {
      yaw = (laser_analysis.getDeltaFromPerpendicular()) * DELTA_TO_YAW_MULTIPLIER * -1;
    }
  }
  return Velocity(PARALLEL_X_VELOCITY, yaw);
}