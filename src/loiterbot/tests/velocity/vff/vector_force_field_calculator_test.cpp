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

#include "loiterbot/velocity/vff/vector_force_field_calculator.hpp"

#include <gtest/gtest.h>

TEST(VECTOR_FORCE_FIELD_CALCULATOR_TEST, FAR)
{
  auto vff = VectorForceFieldCalculator();
  VectorByStandardPosition result = vff.getVffResult(0.0l, 10.0l);

  ASSERT_NEAR(result.getEndpointX(), 1.0, 0.01);
  ASSERT_NEAR(result.getEndpointY(), 0.0, 0.001);
}

TEST(VECTOR_FORCE_FIELD_CALCULATOR_TEST, AHEAD_CLOSE)
{
  auto vff = VectorForceFieldCalculator();
  VectorByStandardPosition result = vff.getVffResult(0.0l, 0.5l);

  ASSERT_NEAR(result.getEndpointX(), 0.5, 0.1);
  ASSERT_NEAR(result.getEndpointY(), 0.0, 0.1);
}

TEST(VECTOR_FORCE_FIELD_CALCULATOR_TEST, RIGHT_CLOSE)
{
  auto vff = VectorForceFieldCalculator();
  VectorByStandardPosition result = vff.getVffResult(M_PI / 4.0, 0.1l);

  ASSERT_NEAR(result.getEndpointX(), 0.3, 0.1);
  ASSERT_NEAR(result.getEndpointY(), -0.6, 0.1);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
