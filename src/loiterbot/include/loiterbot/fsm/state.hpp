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

#ifndef OBSTACLE_HUGGER_FSM_STATE_HPP
#define OBSTACLE_HUGGER_FSM_STATE_HPP

enum class State { JUST_GO, SEARCH, OBSTACLE_NEAR, OBSTACLE_TOO_NEAR, ERROR };

#endif  // OBSTACLE_HUGGER_FSM_STATE_HPP