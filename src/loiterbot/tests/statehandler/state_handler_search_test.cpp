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

#include "loiterbot/fsm/statehandler/state_handler_search.hpp"

#include <gtest/gtest.h>

TEST(StateHandlerSearchTest, Name)
{
  StateHandlerSearch state_handler = StateHandlerSearch();
  EXPECT_STREQ("search", state_handler.name());
}

TEST(StateHandlerSearchTest, NotInSight)
{
  // TODO use reasonable values for angle min and angle incr
  LaserCharacteristics laser_characteristics = LaserCharacteristics(0.0l, 0.1l, 4ul, 2ul);
  NearestSighting nearest_sighting = NearestSighting(1ul, 100.0l);
  // TODO use reasonable value for angle
  LaserAnalysis laser_analysis = LaserAnalysis(nearest_sighting, false, false, false, 0.0l, 100.0l, true, 1ul);
  StateHandlerSearch state_handler = StateHandlerSearch();
  History history = History();
  history.set_obstacle_last_seen_time(0.0l, true);
  history.set_time_lost(0.1l);

  Action action = state_handler.act(history, 0.0l, laser_characteristics, laser_analysis);

  EXPECT_EQ(action.get_state(), State::SEARCH);
  // Ensure the values are reasonable without being overly sensitive to magnitude
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_NEAR(action.get_velocity().value().get_forward(), 0.0l, 0.01L);
  EXPECT_TRUE(action.get_velocity().value().get_yaw() < -0.1l);
}

TEST(StateHandlerSearchTest, InSightRight)
{
  // TODO use reasonable values for angle min and angle incr
  LaserCharacteristics laser_characteristics = LaserCharacteristics(0.0l, 0.1l, 4ul, 2ul);
  NearestSighting nearest_sighting = NearestSighting(1ul, 4.0l);
  // TODO use reasonable value for angle
  LaserAnalysis laser_analysis = LaserAnalysis(nearest_sighting, true, false, false, 0.0l, 4.0l, true, 1ul);
  StateHandlerSearch state_handler = StateHandlerSearch();
  History history = History();
  history.set_obstacle_last_seen_time(1000.0l, true);
  history.set_time_lost(0.1l);

  Action action = state_handler.act(history, 0.0l, laser_characteristics, laser_analysis);

  EXPECT_EQ(action.get_state(), State::SEARCH);
  // Ensure the values are reasonable without being overly sensitive to magnitude
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_TRUE(action.get_velocity().value().get_forward() > 0.5l);
  EXPECT_TRUE(action.get_velocity().value().get_forward() < 5.0l);
  EXPECT_TRUE(action.get_velocity().value().get_yaw() < 0.0l);
  EXPECT_TRUE(action.get_velocity().value().get_yaw() > -0.1l);
}

TEST(StateHandlerSearchTest, Near)
{
  // TODO use reasonable values for angle min and angle incr
  LaserCharacteristics laser_characteristics = LaserCharacteristics(0.0l, 0.1l, 4ul, 2ul);
  NearestSighting nearest_sighting = NearestSighting(1ul, 1.5l);
  // TODO use reasonable value for angle
  LaserAnalysis laser_analysis = LaserAnalysis(nearest_sighting, true, true, false, 0.0l, 1.5l, true, 1ul);
  StateHandlerSearch state_handler = StateHandlerSearch();
  History history = History();
  history.set_obstacle_last_seen_time(1000.0l, true);
  history.set_time_lost(0.1l);

  Action action = state_handler.act(history, 0.0l, laser_characteristics, laser_analysis);

  EXPECT_EQ(action.get_state(), State::OBSTACLE_NEAR);
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_NEAR(action.get_velocity().value().get_forward(), 0.0l, 0.01L);
  EXPECT_NEAR(action.get_velocity().value().get_yaw(), 0.0l, 0.01L);
}

TEST(StateHandlerSearchTest, TooNear)
{
  // TODO use reasonable values for angle min and angle incr
  LaserCharacteristics laser_characteristics = LaserCharacteristics(0.0l, 0.1l, 4ul, 2ul);
  NearestSighting nearest_sighting = NearestSighting(1ul, 0.5l);
  // TODO use reasonable value for angle
  LaserAnalysis laser_analysis = LaserAnalysis(nearest_sighting, true, false, true, 0.0l, 0.5l, true, 1ul);
  StateHandlerSearch state_handler = StateHandlerSearch();
  History history = History();
  history.set_obstacle_last_seen_time(1000.0l, true);
  history.set_time_lost(0.1l);

  Action action = state_handler.act(history, 0.0l, laser_characteristics, laser_analysis);

  EXPECT_EQ(action.get_state(), State::OBSTACLE_TOO_NEAR);
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_NEAR(action.get_velocity().value().get_forward(), 0.0l, 0.01L);
  EXPECT_NEAR(action.get_velocity().value().get_yaw(), 0.0l, 0.01L);
}

TEST(StateHandlerSearchTest, LostSight)
{
  // TODO use reasonable values for angle min and angle incr
  LaserCharacteristics laser_characteristics = LaserCharacteristics(0.0l, 0.1l, 4ul, 2ul);
  NearestSighting nearest_sighting = NearestSighting(1ul, 20.0l);
  // TODO use reasonable value for angle
  LaserAnalysis laser_analysis = LaserAnalysis(nearest_sighting, false, false, false, 0.0l, 20.0l, true, 1ul);
  StateHandlerSearch state_handler = StateHandlerSearch();
  History history = History();
  history.set_obstacle_last_seen_time(1000.0l, true);
  history.set_time_lost(5.0l);

  Action action = state_handler.act(history, 0.0l, laser_characteristics, laser_analysis);

  EXPECT_EQ(action.get_state(), State::SEARCH);
  // Ensure the values are reasonable without being overly sensitive to magnitude
  EXPECT_TRUE(action.get_velocity().has_value());
  EXPECT_NEAR(action.get_velocity().value().get_forward(), 0.0l, 0.01L);
  EXPECT_TRUE(action.get_velocity().value().get_yaw() < 0.0l);
  EXPECT_TRUE(action.get_velocity().value().get_yaw() > -1.0l);
}

TEST(StateHandlerSearchTest, RecentlyLostSight)
{
  // TODO use reasonable values for angle min and angle incr
  LaserCharacteristics laser_characteristics = LaserCharacteristics(0.0l, 0.1l, 4ul, 2ul);
  NearestSighting nearest_sighting = NearestSighting(1ul, 20.0l);
  // TODO use reasonable value for angle
  LaserAnalysis laser_analysis = LaserAnalysis(nearest_sighting, false, false, false, 0.0l, 20.0l, true, 1ul);
  StateHandlerSearch state_handler = StateHandlerSearch();
  History history = History();
  history.set_obstacle_last_seen_time(1000.0l, true);
  history.set_time_lost(0.1l);

  Action action = state_handler.act(history, 0.0l, laser_characteristics, laser_analysis);

  EXPECT_EQ(action.get_state(), State::SEARCH);
  EXPECT_FALSE(action.get_velocity().has_value());
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
