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

#include <gtest/gtest.h>

#include "../test_constants.hpp"
#include "loiterbot/fsm/statehandler/state_handler_go.hpp"

TEST(StateHandlerJustGoTest, StraightAhead)
{
  LaserCharacteristics laser_characteristics =
    LaserCharacteristics(LASER_ANGLE_MINIMUM, LASER_ANGLE_INCREMENT, 4ul, 2ul);
  LaserAnalysis laser_analysis = LaserAnalysis(true, false, false, 0.0, 2.0l);
  StateHandlerGo state_handler = StateHandlerGo();
  History history = History();
  history.set_obstacle_last_seen_time(1000.0l, true);
  history.set_time_lost(0.1l);

  Action action = state_handler.act(history, 0.0l, laser_characteristics, laser_analysis);

  EXPECT_EQ(action.get_state(), State::GO);
  // Ensure the values are reasonable without being overly sensitive to magnitude
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_TRUE(action.get_velocity().value().get_forward() > 0.5l);
  EXPECT_NEAR(action.get_velocity().value().get_yaw(), 0.0, 0.01l);
}

TEST(StateHandlerJustGoTest, AheadRight)
{
  LaserCharacteristics laser_characteristics =
    LaserCharacteristics(LASER_ANGLE_MINIMUM, LASER_ANGLE_INCREMENT, 4ul, 2ul);
  LaserAnalysis laser_analysis = LaserAnalysis(true, false, false, -1 * M_PI / 4.0, 2.0l);
  StateHandlerGo state_handler = StateHandlerGo();
  History history = History();
  history.set_obstacle_last_seen_time(1000.0l, true);
  history.set_time_lost(0.1l);

  Action action = state_handler.act(history, 0.0l, laser_characteristics, laser_analysis);

  EXPECT_EQ(action.get_state(), State::GO);
  // Ensure the values are reasonable without being overly sensitive to magnitude
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_TRUE(action.get_velocity().value().get_forward() > 0.5l);
  EXPECT_TRUE(action.get_velocity().value().get_forward() < 8.0l);
  EXPECT_TRUE(action.get_velocity().value().get_yaw() > 0.2l);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
