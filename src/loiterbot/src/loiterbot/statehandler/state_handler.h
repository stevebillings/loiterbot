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

#ifndef OBSTACLE_HUGGER_STATE_HANDLER_H
#define OBSTACLE_HUGGER_STATE_HANDLER_H

#include "../../laser/laser_analysis.h"
#include "../../laser/laser_characteristics.h"
#include "../../velocity/velocity_calculator.h"
#include "../action.h"
#include "../history.h"
#include "../state.h"

// the virtual class for State; each concrete state object implement the act() method for a specific state
class StateHandler
{
public:
  virtual const char * name() const = 0;
  virtual Action act(
    const History & history, const double current_time,
    const LaserCharacteristics & laser_characteristics,
    const LaserAnalysis & laser_analysis) const = 0;
  virtual ~StateHandler(){};

protected:
  VelocityCalculator velocity_calculator_ = VelocityCalculator();
};

#endif  // OBSTACLE_HUGGER_STATE_HANDLER_H
