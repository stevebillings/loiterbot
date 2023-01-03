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

#ifndef OBSTACLE_HUGGER_LASER_ANALYZER_H
#define OBSTACLE_HUGGER_LASER_ANALYZER_H

#include "laser_analysis.h"
#include "laser_characteristics.h"

class LaserAnalyzer
{
public:
  LaserCharacteristics determineCharacteristics(const std::vector<float>& laser_ranges) const;
  LaserAnalysis analyze(const LaserCharacteristics& laserCharacteristics, const std::vector<float>& laser_ranges) const;

private:
  constexpr static double DIST_WITHIN_SIGHT = 9.5;
  constexpr static double DIST_NEAR = 4.0;
  constexpr static double DIST_TOO_NEAR = 1.5;
};

#endif  // OBSTACLE_HUGGER_LASER_ANALYZER_H
