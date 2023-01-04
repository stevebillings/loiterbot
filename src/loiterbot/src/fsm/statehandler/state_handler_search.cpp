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

static constexpr double TIME_LOST_TOLERANCE_SECONDS = 0.75;

Action StateHandlerSearch::act(
  const History & history, const double current_time,
  const LaserCharacteristics & laser_characteristics, const LaserAnalysis & laser_analysis) const
{
  if (laser_analysis.isInSight())
    return handleInSight(laser_characteristics, laser_analysis);
  else if (
    history.has_obstacle_ever_been_seen() && history.get_time_lost() > TIME_LOST_TOLERANCE_SECONDS)
    return handleLostSight(history);
  else if (!history.has_obstacle_ever_been_seen())
    return handleNeverSeen();
  else
    return handleRecentlyLost();
}

const char * StateHandlerSearch::name() const { return "search"; }

Action StateHandlerSearch::handleRecentlyLost() const { return Action(State::SEARCH); }

Action StateHandlerSearch::handleInSight(
  const LaserCharacteristics & laser_characteristics, const LaserAnalysis & laser_analysis) const
{
  State new_state = State::SEARCH;
  Velocity new_velocity = getVelocityCalculator().toApproach(laser_characteristics, laser_analysis);
  if (laser_analysis.isNear())
    new_state = State::OBSTACLE_NEAR;
  else if (laser_analysis.isTooNear())
    new_state = State::OBSTACLE_TOO_NEAR;
  return Action(new_velocity, new_state);
}

Action StateHandlerSearch::handleLostSight(const History & history) const
{
  Velocity new_velocity = Velocity::create_stopped();
  State new_state = State::SEARCH;
  if (history.was_seen_to_right()) {
    new_velocity = Velocity::create_spin_right();
  } else {
    new_velocity = Velocity::create_spin_left();
  }
  return Action(new_velocity, new_state);
}

Action StateHandlerSearch::handleNeverSeen() const
{
  Velocity new_velocity = Velocity::create_stopped();
  State new_state = State::SEARCH;
  new_velocity = Velocity::create_spin_right();
  return Action(new_velocity, new_state);
}
