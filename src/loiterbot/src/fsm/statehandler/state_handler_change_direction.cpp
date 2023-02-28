//
// Created by stevebillings on 2/24/23.
//

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
