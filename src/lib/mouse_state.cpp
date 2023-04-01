/// @file mouse_state.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-04-02
///
/// @copyright Copyright (c) 2023
///
///

#include "src/lib/mouse_state.h"

#include <SFML/Graphics.hpp>
#include <iostream>

namespace physics
{
MouseState::MouseState(ApplicationPtr app) : mApp(app) {}

void DefaultMouseState::press(sf::Vector2f mousePosition)
{
    std::cout << "press <" << mousePosition.x << ", " << mousePosition.y
              << ">\n";
}

void DefaultMouseState::release(sf::Vector2f mousePosition)
{
    std::cout << "release <" << mousePosition.x << ", " << mousePosition.y
              << ">\n";
}

DefaultMouseState::DefaultMouseState(ApplicationPtr app) : MouseState(app) {}
}  // namespace physics