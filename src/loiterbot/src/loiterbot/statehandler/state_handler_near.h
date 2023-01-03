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

#ifndef OBSTACLE_HUGGER_STATE_HANDLER_NEAR_H
#define OBSTACLE_HUGGER_STATE_HANDLER_NEAR_H

#include "state_handler.h"

class StateHandlerNear : public StateHandler
{
public:
  Action act(
    const History & history, const double current_time,
    const LaserCharacteristics & laser_characteristics,
    const LaserAnalysis & laser_analysis) const override;
  const char * name() const;

private:
  const Action handleTooNear() const;
  const Action handleInSight(const LaserAnalysis & laser_analysis) const;
  const Action handleLostSight(const History & history, const LaserAnalysis & laser_analysis) const;
};

#endif  // OBSTACLE_HUGGER_STATE_HANDLER_NEAR_H
