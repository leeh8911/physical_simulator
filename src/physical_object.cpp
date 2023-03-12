/// @file physical_object.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-13
///
/// @copyright Copyright (c) 2023
///
///

#include "src/physical_object.h"

#include "src/utils.h"

namespace engine
{

PhysicalObject::PhysicalObject(Eigen::Vector2d center, Eigen::Vector2d velocity,
                               Eigen::Vector4d color)
    : center_(center), velocity_(velocity), color_(color)
{
}

void PhysicalObject::SetCenter(Eigen::Vector2d center) { center_ = center; }

void PhysicalObject::SetVelocity(Eigen::Vector2d velocity)
{
    velocity_ = velocity;
}

void PhysicalObject::SetAcceleration(Eigen::Vector2d acceleration)
{
    acceleration_ = acceleration;
}

void PhysicalObject::SetColor(Eigen::Vector4d color) { color_ = color; }

Eigen::Vector2d PhysicalObject::GetCenter() const { return center_; }

Eigen::Vector2d PhysicalObject::GetVelocity() const { return velocity_; }

Eigen::Vector2d PhysicalObject::GetAcceleration() const
{
    return acceleration_;
}

Eigen::Vector4d PhysicalObject::GetColor() const { return color_; }

void PhysicalObject::Update(double delta_time)
{
    velocity_ += acceleration_ * delta_time;
    center_ += velocity_ * delta_time;

    acceleration_ = Eigen::Vector2d::Zero();
}

Circle::Circle(Eigen::Vector2d center, double radius, Eigen::Vector2d velocity,
               Eigen::Vector4d color)
    : PhysicalObject(center, velocity, color), radius_(radius)
{
}

void Circle::SetRadius(double radius) { radius_ = radius; }

double Circle::GetRadius() const { return radius_; }

DrawablePtr Circle::GetDrawable() const
{
    auto circle = std::make_shared<sf::CircleShape>(radius_);
    circle->setFillColor(EigenToSFColor(GetColor()));
    circle->setPosition(EigenToSFVector(GetCenter()));
    return circle;
}

}  // namespace engine
