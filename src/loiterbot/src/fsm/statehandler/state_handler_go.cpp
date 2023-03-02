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

#include "loiterbot/fsm/statehandler/state_handler_go.hpp"

Action StateHandlerGo::act(
  const History & history, const double current_time,
  const LaserCharacteristics & laser_characteristics, const LaserAnalysis & laser_analysis) const
{
  if (laser_analysis.isTooNear()) {
    return Action(Velocity::create_reverse(), State::OBSTACLE_TOO_NEAR);
  }
  auto new_motion_vector_by_standard_position = vff_calculator.getVffResult(
    laser_analysis.getObstacleAngleRelToStraightRadians(), laser_analysis.getObstacleDistance());
  auto new_motion_vector_by_magnitude_angle =
    vector_converter.standardPositionToMagnitudeAngle(new_motion_vector_by_standard_position);
  // TODO do we need both early returns?
  if (abs(new_motion_vector_by_magnitude_angle.getAngleRadians()) >= (M_PI / 2.0l)) {
    return Action(Velocity::create_reverse(), State::OBSTACLE_TOO_NEAR);
  }
  const double SLOWDOWN_FACTOR = 2.0l;
  auto new_velocity = Velocity(
    new_motion_vector_by_magnitude_angle.getMagnitude() / SLOWDOWN_FACTOR,
    new_motion_vector_by_magnitude_angle.getAngleRadians());
  return Action(new_velocity, State::GO);
}

const char * StateHandlerGo::name() const {return "go";}