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

//
// Created by stevebillings on 12/4/22.
//

#ifndef OBSTACLE_HUGGER_LASER_CHARACTERISTICS_H
#define OBSTACLE_HUGGER_LASER_CHARACTERISTICS_H

class LaserCharacteristics
{
public:
  LaserCharacteristics(const unsigned long leftmost_index, const unsigned long straight_index)
    : leftmost_index_(leftmost_index), straight_index_(straight_index){};
  LaserCharacteristics(const LaserCharacteristics& other)
    : leftmost_index_(other.leftmost_index_), straight_index_(other.straight_index_){};
  unsigned long getLeftmostIndex() const;
  unsigned long getStraightIndex() const;

private:
  unsigned long leftmost_index_;
  unsigned long straight_index_;
};

#endif  // OBSTACLE_HUGGER_LASER_CHARACTERISTICS_H
