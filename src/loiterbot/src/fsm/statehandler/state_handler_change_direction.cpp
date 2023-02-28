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

#include "loiterbot/fsm/statehandler/state_handler_change_direction.hpp"

Action StateHandlerChangeDirection::act(
  const History & history, const double current_time,
  const LaserCharacteristics & laser_characteristics, const LaserAnalysis & laser_analysis) const
{
  if ((current_time - history.get_time_entered_state()) > 1.0) {
    return Action(Velocity::create_stopped(), State::JUST_GO);
  }
  return Action(State::CHANGE_DIRECTION);
}

const char * StateHandlerChangeDirection::name() const {return "change direction";}
