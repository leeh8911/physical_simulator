/// @file world.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-04-03
///
/// @copyright Copyright (c) 2023
///
///

#include "src/lib/world.h"

#include <SFML/Graphics.hpp>
#include <iostream>

namespace physics
{
Circle2D::Circle2D(sf::Vector2f position, float radius)
    : mPosition(position), mRadius(radius)
{
}

sf::Vector2f Circle2D::getPosition() const { return this->mPosition; }

float Circle2D::getRadius() const { return this->mRadius; }

void World::addObject(sf::Vector2f position, float radius)
{
    this->mObjects.emplace_back(position, radius);
}

void World::addObject(Circle2D object) { this->mObjects.emplace_back(object); }

std::vector<Circle2D> World::getObjects() { return this->mObjects; }

void World::render(sf::RenderWindow& window) const
{
    for (auto& object : this->mObjects)
    {
        sf::CircleShape circle(object.getRadius());
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(object.getPosition());
        window.draw(circle);
    }
}
}  // namespace physics