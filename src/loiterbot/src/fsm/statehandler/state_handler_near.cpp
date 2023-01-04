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

#include "loiterbot/fsm/statehandler/state_handler_near.hpp"

Action StateHandlerNear::act(
  const History & history, const double current_time,
  const LaserCharacteristics & laser_characteristics, const LaserAnalysis & laser_analysis) const
{
  if (laser_analysis.isTooNear())
    return handleTooNear();
  else if (laser_analysis.isInSight())
    return handleInSight(laser_analysis);
  else
    return handleLostSight(history, laser_analysis);
}

const char * StateHandlerNear::name() const { return "obstacle near"; }

const Action StateHandlerNear::handleTooNear() const
{
  return Action(Velocity::create_reverse(), State::OBSTACLE_TOO_NEAR);
}

const Action StateHandlerNear::handleInSight(const LaserAnalysis & laser_analysis) const
{
  return Action(velocity_calculator_.toParallel(laser_analysis), State::OBSTACLE_NEAR);
}

const Action StateHandlerNear::handleLostSight(
  const History & history, const LaserAnalysis & laser_analysis) const
{
  if (history.get_time_lost() > 1.0)
    return Action(Velocity::create_stopped(), State::SEARCH);
  else
    return Action(State::OBSTACLE_NEAR);
}