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

#ifndef OBSTACLE_HUGGER_HISTORY_H
#define OBSTACLE_HUGGER_HISTORY_H

#include <optional>

#include "state.h"

class History
{
public:
  void set_time_entered_state(State new_state, double current_time);
  double get_time_entered_state() const;

  void set_time_lost(double time_lost);
  double get_time_lost() const;

  void set_obstacle_last_seen_time(double obstacle_last_seen_time, bool seen_to_right);
  double get_obstacle_last_seen_time() const;
  bool was_seen_to_right() const;

  bool has_obstacle_ever_been_seen() const;

private:
  std::optional<State> cur_state_ = std::nullopt;
  double time_entered_state_ = 0.0l;
  double time_lost_ = 0.0l;
  double obstacle_last_seen_time_ = 0.0l;
  bool seen_to_right_ = false;
};

#endif  // OBSTACLE_HUGGER_HISTORY_H
