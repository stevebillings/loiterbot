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

#ifndef OBSTACLE_HUGGER_NEAREST_SIGHTING_H
#define OBSTACLE_HUGGER_NEAREST_SIGHTING_H

class NearestSighting
{
public:
  NearestSighting(const unsigned long range_index, double range) : range_index_(range_index), range_(range){};
  NearestSighting(const NearestSighting& src) : range_index_(src.getRangeIndex()), range_(src.getRange()){};
  unsigned long getRangeIndex() const;
  double getRange() const;

private:
  const unsigned long range_index_;
  const double range_;
};

#endif  // OBSTACLE_HUGGER_NEAREST_SIGHTING_H
