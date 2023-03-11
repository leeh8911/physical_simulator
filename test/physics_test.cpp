/// @file physics_test.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-12
///
/// @copyright Copyright (c) 2023
///
///

#include "src/physics.h"

#include <gtest/gtest.h>

#include <Eigen/Dense>

namespace engine::test
{

// TODO: PhysicalObject
TEST(PhysicsTest, PhysicalObjectTest)
{
    PhysicalObject object{Eigen::Vector2d{0.0, 0.0}};
    EXPECT_EQ(object.GetPosition(), Eigen::Vector2d{0.0, 0.0});
    EXPECT_EQ(object.GetVelocity(), Eigen::Vector2d{0.0, 0.0});
    EXPECT_EQ(object.GetRadius(), 1.0);
    EXPECT_EQ(object.GetMass(), 1.0);
}
}  // namespace engine::test