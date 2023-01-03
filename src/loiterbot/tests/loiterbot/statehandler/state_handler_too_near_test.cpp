#include <gtest/gtest.h>
#include "../../../src/loiterbot/statehandler/state_handler_too_near.h"

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
