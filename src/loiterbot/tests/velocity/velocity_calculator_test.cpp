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

#include "loiterbot/velocity/velocity_calculator.hpp"

#include <gtest/gtest.h>

TEST(VelocityCalculatorTest, AheadRight)
{
  VelocityCalculator velocity_calculator;
  // TODO set reasonable values for angle_min and angle_increment
  LaserCharacteristics laser_characteristics = LaserCharacteristics(0.0l, 0.1l, 4ul, 2ul);
  NearestSighting nearest_sighting = NearestSighting(1ul, 3.0l);
  // TODO set reasonable value for obstacle_angle_radians
  LaserAnalysis laser_analysis = LaserAnalysis(nearest_sighting, true, false, false, 0.0l, true, 1ul);
  Velocity velocity = velocity_calculator.toApproach(laser_characteristics, laser_analysis);
  EXPECT_NEAR(velocity.get_forward(), 0.75l, .05l);
  EXPECT_NEAR(velocity.get_yaw(), -0.01l, .001l);
}

TEST(VelocityCalculatorTest, FarAheadLeft)
{
  VelocityCalculator velocity_calculator;
  // TODO set reasonable values for angle_min and angle_increment
  LaserCharacteristics laser_characteristics = LaserCharacteristics(0.0l, 0.1l, 4ul, 2ul);
  NearestSighting nearest_sighting = NearestSighting(3ul, 9.0l);
  // TODO set reasonable value for obstacle_angle_radians
  LaserAnalysis laser_analysis = LaserAnalysis(nearest_sighting, true, false, false, 0.0l, true, 1ul);
  Velocity velocity = velocity_calculator.toApproach(laser_characteristics, laser_analysis);
  EXPECT_NEAR(velocity.get_forward(), 2.25l, .05l);
  EXPECT_NEAR(velocity.get_yaw(), 0.01l, .001l);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
