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

ObjectHandler::ObjectHandler(sf::Vector2f world_origin)
    : world_origin_{world_origin}
{
}

void ObjectHandler::SetWorldOrigin(sf::RectangleShape world_box)
{
    world_box_ = world_box;

    auto world_box_size = world_box_.getSize();
    auto world_box_pos = world_box_.getPosition();

    world_origin_ = sf::Vector2f(world_box_pos.x + world_box_size.x / 2,
                                 world_box_pos.y + world_box_size.y / 2);
}

void ObjectHandler::AddObject(PhysicalObjectPtr object)
{
    objects_.push_back(object);
}

void ObjectHandler::RemoveObject(PhysicalObjectPtr object)
{
    auto it = std::find(objects_.begin(), objects_.end(), object);
    if (it != objects_.end())
    {
        objects_.erase(it);
    }
}

void ObjectHandler::CreateCircle(sf::Vector2f center, double radius,
                                 sf::Vector2f velocity, sf::Color color)
{
    auto world_center = ConvertWindowToWorld(center);
    auto world_velocity = ConvertWindowToWorld(velocity);
    auto world_color = Eigen::Vector4d(color.r / 255.0, color.g / 255.0,
                                       color.b / 255.0, color.a / 255.0);
    auto circle = std::make_shared<Circle>(world_center, radius, world_velocity,
                                           world_color);
    AddObject(circle);
}

PhysicalObjectPtrList ObjectHandler::GetObjects() const { return objects_; }

std::vector<DrawablePtr> ObjectHandler::ToDrawables() const
{
    std::vector<DrawablePtr> drawables{};
    drawables.reserve(objects_.size());

    for (auto object : objects_)
    {
        auto circle = std::dynamic_pointer_cast<Circle>(object);
        if (circle)
        {
            drawables.push_back(ConvertDrawable(*circle));
        }
    }
    return drawables;
}

Eigen::Vector2d ObjectHandler::ConvertWindowToWorld(
    sf::Vector2f window_pos) const
{
    return Eigen::Vector2d{window_pos.x - world_origin_.x,
                           world_origin_.y - window_pos.y};
}

sf::Vector2f ObjectHandler::ConvertWorldToWindow(
    Eigen::Vector2d world_pos) const
{
    return sf::Vector2f{static_cast<float>(world_pos[0] + world_origin_.x),
                        static_cast<float>(world_origin_.y - world_pos[1])};
}

Eigen::Vector4d ObjectHandler::ConvertColor(sf::Color color) const
{
    return Eigen::Vector4d{color.r / 255.0, color.g / 255.0, color.b / 255.0,
                           color.a / 255.0};
}
sf::Color ObjectHandler::ConvertColor(Eigen::Vector4d color) const
{
    return sf::Color{static_cast<sf::Uint8>(color[0] * 255),
                     static_cast<sf::Uint8>(color[1] * 255),
                     static_cast<sf::Uint8>(color[2] * 255),
                     static_cast<sf::Uint8>(color[3] * 255)};
}
DrawablePtr ObjectHandler::ConvertDrawable(Circle object) const
{
    auto circle = std::make_shared<sf::CircleShape>(object.GetRadius());
    circle->setFillColor(ConvertColor(object.GetColor()));
    circle->setPosition(ConvertWorldToWindow(object.GetCenter()));
    return circle;
}
}  // namespace engine
