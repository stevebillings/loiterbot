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

#include "loiterbot/fsm/statehandler/state_handler_too_near.h"

#include <gtest/gtest.h>

#include "rclcpp/rclcpp.hpp"

TEST(StateHandlerTooNearTest, Name)
{
  StateHandlerTooNear state_handler = StateHandlerTooNear();
  EXPECT_STREQ("obstacle too near", state_handler.name());
}

TEST(StateHandlerTooNearTest, RecentlyTooNear)
{
  LaserCharacteristics laser_characteristics = LaserCharacteristics(4ul, 2ul);
  NearestSighting nearest_sighting = NearestSighting(1ul, 4.0l);
  LaserAnalysis laser_analysis = LaserAnalysis(nearest_sighting, true, false, false, true, 1ul);
  StateHandlerTooNear state_handler = StateHandlerTooNear();
  History history = History();
  history.set_obstacle_last_seen_time(1.0l, true);
  history.set_time_lost(0.1l);
  history.set_time_entered_state(State::OBSTACLE_TOO_NEAR, 1.0l);

  Action action = state_handler.act(history, 1.1l, laser_characteristics, laser_analysis);

  EXPECT_EQ(action.get_state(), State::OBSTACLE_TOO_NEAR);
  // Ensure the values are reasonable without being overly sensitive to magnitude
  EXPECT_FALSE(action.get_velocity().has_value());
}

TEST(StateHandlerTooNearTest, TooNearForAWhile)
{
  LaserCharacteristics laser_characteristics = LaserCharacteristics(4ul, 2ul);
  NearestSighting nearest_sighting = NearestSighting(1ul, 4.0l);
  LaserAnalysis laser_analysis = LaserAnalysis(nearest_sighting, true, false, false, true, 1ul);
  StateHandlerTooNear state_handler = StateHandlerTooNear();
  History history = History();
  history.set_obstacle_last_seen_time(1.0l, true);
  history.set_time_lost(0.1l);
  history.set_time_entered_state(State::OBSTACLE_TOO_NEAR, 1.0l);

  Action action = state_handler.act(history, 5.0l, laser_characteristics, laser_analysis);

  EXPECT_EQ(action.get_state(), State::SEARCH);
  // Ensure the values are reasonable without being overly sensitive to magnitude
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_NEAR(action.get_velocity().value().get_yaw(), 0.0l, 0.001L);
  EXPECT_NEAR(action.get_velocity().value().get_forward(), 0.0l, 0.001L);
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
