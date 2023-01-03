//
// Created by stevebillings on 12/17/22.
//

#ifndef OBSTACLE_HUGGER_ACTION_H
#define OBSTACLE_HUGGER_ACTION_H

#include <optional>
#include "state.h"
#include "../velocity/velocity.h"

class Action
{
public:
  Action(const Velocity& velocity, const State state) : velocity_(velocity), state_(state){};
  Action(const State state) : velocity_(std::nullopt), state_(state){};
  std::optional<Velocity> get_velocity() const;
  State get_state() const;

private:
  std::optional<Velocity> velocity_;
  State state_;
};

#endif  // OBSTACLE_HUGGER_ACTION_H
