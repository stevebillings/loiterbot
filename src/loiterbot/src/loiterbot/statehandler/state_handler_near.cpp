
#include "state_handler_near.h"

Action StateHandlerNear::act(const History& history, const double current_time,
                             const LaserCharacteristics& laser_characteristics,
                             const LaserAnalysis& laser_analysis) const
{
  if (laser_analysis.isTooNear())
    return handleTooNear();
  else if (laser_analysis.isInSight())
    return handleInSight(laser_analysis);
  else
    return handleLostSight(history, laser_analysis);
}

const char* StateHandlerNear::name() const
{
  return "obstacle near";
}

const Action StateHandlerNear::handleTooNear() const
{
  return Action(Velocity::create_reverse(), State::OBSTACLE_TOO_NEAR);
}

const Action StateHandlerNear::handleInSight(const LaserAnalysis& laser_analysis) const
{
  return Action(velocity_calculator_.toParallel(laser_analysis), State::OBSTACLE_NEAR);
}

const Action StateHandlerNear::handleLostSight(const History& history, const LaserAnalysis& laser_analysis) const
{
  if (history.get_time_lost() > 1.0)
    return Action(Velocity::create_stopped(), State::SEARCH);
  else
    return Action(State::OBSTACLE_NEAR);
}