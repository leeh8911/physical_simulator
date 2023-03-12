/// @file renderer.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-12
///
/// @copyright Copyright (c) 2023
///
///

#include "src/renderer.h"

#include <SFML/Graphics.hpp>

namespace engine
{

Renderer::Renderer(sf::Vector2u window_size)
{
    sf::Vector2f dashboard_size{static_cast<float>(window_size.x) * 0.2f,
                                static_cast<float>(window_size.y)};
    sf::Vector2f dashboard_left_top{0.f, 0.f};
    sf::Vector2f world_size{static_cast<float>(window_size.x) * 0.8f,
                            static_cast<float>(window_size.y)};
    sf::Vector2f world_left_top{dashboard_size.x, 0.f};

    dashboard_box_.setSize(dashboard_size);
    dashboard_box_.setFillColor(sf::Color::Black);
    dashboard_box_.setOutlineColor(sf::Color::White);
    dashboard_box_.setOutlineThickness(1.0f);
    dashboard_box_.setPosition(dashboard_left_top.x, dashboard_left_top.y);

    world_box_.setSize(world_size);
    world_box_.setFillColor(sf::Color::Black);
    world_box_.setOutlineColor(sf::Color::White);
    world_box_.setOutlineThickness(1.0f);
    world_box_.setPosition(world_left_top.x, world_left_top.y);
}

void Renderer::Render(sf::RenderWindow& window,
                      const PhysicalObjectPtrList& objects)
{
    window.draw(dashboard_box_);
    window.draw(world_box_);

    for (auto& object : objects)
    {
        window.draw(*(object->GetDrawable()));
    }
}
}  // namespace engine