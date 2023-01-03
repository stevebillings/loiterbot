#include "state_handlers.h"

StateHandler* StateHandlers::get_state_handler(State state) const
{
  switch (state)
  {
    case State::SEARCH:
      return state_handler_search_;
    case State::OBSTACLE_NEAR:
      return state_handler_near_;
    case State::OBSTACLE_TOO_NEAR:
      return state_handler_too_near_;
    default:
      return state_handler_error_;
  }
}