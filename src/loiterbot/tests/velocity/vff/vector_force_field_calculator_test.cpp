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
