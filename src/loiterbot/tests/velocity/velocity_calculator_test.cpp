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
#include "../test_constants.hpp"

TEST(VelocityCalculatorTest, AheadRight)
{
  VelocityCalculator velocity_calculator;
  LaserAnalysis laser_analysis = LaserAnalysis(true, false, false, -1 * M_PI/8.0l, 3.0l);
  Velocity velocity = velocity_calculator.toApproach(laser_analysis);
  EXPECT_NEAR(velocity.get_forward(), 1.0l, .05l);
  EXPECT_NEAR(velocity.get_yaw(), -1 * M_PI/8.0l, .001l);
}

TEST(VelocityCalculatorTest, FarAheadLeft)
{
  VelocityCalculator velocity_calculator;
  LaserAnalysis laser_analysis = LaserAnalysis(true, false, false, M_PI/16.0l, 9.0l);
  Velocity velocity = velocity_calculator.toApproach(laser_analysis);
  EXPECT_NEAR(velocity.get_forward(), 3.0l, .05l);
  EXPECT_NEAR(velocity.get_yaw(), M_PI/16.0l, .001l);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
