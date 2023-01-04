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

#include "loiterbot/fsm/statehandler/state_handlers.hpp"

StateHandler * StateHandlers::get_state_handler(State state) const
{
  switch (state) {
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