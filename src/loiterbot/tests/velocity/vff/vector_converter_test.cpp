#include "loiterbot/vector/vector_converter.hpp"

#include <gtest/gtest.h>

TEST(VECTOR_UNITTEST, AHEAD)
{
  auto vc = VectorConverter();
  auto vsp = VectorByStandardPosition(1.0, 0.0);
  auto vma = vc.standardPositionToMagnitudeAngle(vsp);

  ASSERT_NEAR(vma.getAngleRadians(), 0.0, 0.001);
  ASSERT_NEAR(vma.getMagnitude(), 1.0, 0.001);
}

TEST(VECTOR_UNITTEST, LEFT)
{
  auto vc = VectorConverter();
  auto vsp = VectorByStandardPosition(0.0, 1.0);
  auto vma = vc.standardPositionToMagnitudeAngle(vsp);

  ASSERT_NEAR(vma.getAngleRadians(), M_PI / 2.0, 0.01);
  ASSERT_NEAR(vma.getMagnitude(), 1.0, 0.001);
}

TEST(VECTOR_UNITTEST, RIGHT_45)
{
  auto vc = VectorConverter();
  auto vsp = VectorByStandardPosition(1.0, -1.0);
  auto vma = vc.standardPositionToMagnitudeAngle(vsp);

  ASSERT_NEAR(vma.getAngleRadians(), -1 * M_PI / 4.0, 0.01);
  ASSERT_NEAR(vma.getMagnitude(), sqrt(2.0), 0.001);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}