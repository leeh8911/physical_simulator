/// @file physics.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-11
///
/// @copyright Copyright (c) 2023
///
///

#include "src/physics.h"

#include <Eigen/Dense>

namespace engine
{

PhysicalObject::PhysicalObject(Eigen::Vector2d position)
    : position_(std::move(position))
{
}

PhysicalObject::PhysicalObject(Eigen::Vector2d position, double raidus,
                               double mass)
    : position_(std::move(position)), radius_(raidus), mass_(mass)
{
}

Eigen::Vector2d PhysicalObject::GetPosition() const { return position_; }

Eigen::Vector2d PhysicalObject::GetVelocity() const { return velocity_; }

double PhysicalObject::GetRadius() const { return radius_; }

double PhysicalObject::GetMass() const { return mass_; }

void PhysicalObject::SetPosition(Eigen::Vector2d position)
{
    position_ = position;
}
void PhysicalObject::SetVelocity(Eigen::Vector2d velocity)
{
    velocity_ = velocity;
}
void PhysicalObject::Update(double interval)
{
    position_ += velocity_ * interval;
    velocity_ += acceleration_ * interval;
    acceleration_ = {0.0, 0.0};
}

void PhysicalObject::Accelerate(Eigen::Vector2d accel)
{
    acceleration_ += accel;
}

void PhysicalObject::Collide(PhysicalObject& other)
{
    double m1 = this->GetMass();
    double m2 = other.GetMass();
    double total_mass = m1 + m2;
    Eigen::Vector2d v1 = this->GetVelocity();
    Eigen::Vector2d v2 = other.GetVelocity();

    Eigen::Vector2d v1_new =
        ((m1 - m2) / total_mass) * v1 + (2.0 * m2 / total_mass) * v2;
    Eigen::Vector2d v2_new =
        (2.0 * m1 / total_mass) * v1 + ((m2 - m1) / total_mass) * v2;

    this->velocity_ = v1_new;
    other.velocity_ = v2_new;
}
void PhysicalObject::Collide(Eigen::Vector2d left_top,
                             Eigen::Vector2d right_bottom)
{
    Eigen::Vector2d position = this->GetPosition();
    Eigen::Vector2d velocity = this->GetVelocity();

    if (position.x() - radius_ < left_top.x() ||
        position.x() + radius_ > right_bottom.x())
    {
        velocity.x() *= -1;
    }
    if (position.y() - radius_ < left_top.y() ||
        position.y() + radius_ > right_bottom.y())
    {
        velocity.y() *= -1;
    }

    this->velocity_ = velocity;
}

}  // namespace engine