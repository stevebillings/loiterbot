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

#ifndef OBSTACLE_HUGGER_STATE_HANDLER_JUST_GO_HPP
#define OBSTACLE_HUGGER_STATE_HANDLER_JUST_GO_HPP

#include "state_handler.hpp"
#include "loiterbot/velocity/vff/vector_force_field_calculator.hpp"
#include "loiterbot/vector/vector_converter.hpp"
#include "loiterbot/vector/vector_by_standard_position.hpp"
#include "loiterbot/vector/vector_converter.hpp"

class StateHandlerJustGo : public StateHandler
{
public:
  [[nodiscard]] Action act(
    const History & history, double current_time,
    const LaserCharacteristics & laser_characteristics,
    const LaserAnalysis & laser_analysis) const override;
  const char * name() const override;

private:
  // TODO inject
  const VectorForceFieldCalculator vff_calculator = VectorForceFieldCalculator();
  const VectorConverter vector_converter = VectorConverter();
};

#endif  // OBSTACLE_HUGGER_STATE_HANDLER_JUST_GO_HPP
