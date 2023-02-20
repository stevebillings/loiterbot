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

#include "loiterbot/laser/laser_analyzer.hpp"

LaserCharacteristics LaserAnalyzer::determineCharacteristics(
  const double laser_angle_min, const double laser_angle_increment,
  const std::vector<float> & laser_ranges) const
{
  unsigned long straight_index = laser_ranges.size() / 2;
  unsigned long leftmost_index = laser_ranges.size() - 1;
  return LaserCharacteristics(laser_angle_min, laser_angle_increment, leftmost_index, straight_index);
}

LaserAnalysis LaserAnalyzer::analyze(
  const LaserCharacteristics & laserCharacteristics, const std::vector<float> & laser_ranges) const
{
  int cur_range_index = 0;
  double min_range = 1000.0;
  unsigned long min_range_index = laserCharacteristics.getStraightIndex();
  for (float this_range : laser_ranges) {
    if (this_range < min_range) {
      min_range = this_range;
      min_range_index = cur_range_index;
    }
    cur_range_index++;
  }
  bool in_sight = min_range < DIST_WITHIN_SIGHT;
  bool near = min_range < DIST_NEAR;
  bool too_near = min_range < DIST_TOO_NEAR;

  long index_rel_to_straight = min_range_index - (laserCharacteristics.getLeftmostIndex()/2 - 1);
  double obstacle_angle = laserCharacteristics.getAngleIncrement() * index_rel_to_straight;

  bool to_right = min_range_index < laserCharacteristics.getStraightIndex();
  unsigned long delta_from_perpendicular = 0L;
  if (to_right) {
    delta_from_perpendicular = min_range_index;
  } else {
    delta_from_perpendicular = laserCharacteristics.getLeftmostIndex() - min_range_index;
  }
  // TODO how does this memory get freed?
  NearestSighting nearestSighting = NearestSighting(min_range_index, min_range);
  return LaserAnalysis(
    nearestSighting, in_sight, near, too_near, obstacle_angle, min_range, to_right, delta_from_perpendicular);
}