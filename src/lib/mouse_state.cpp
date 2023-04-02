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

#include "src/lib/application.h"

namespace physics
{
MouseState::MouseState(ApplicationPtr app) : mApp(app) {}

ApplicationPtr MouseState::getApplication() { return this->mApp; }

DefaultMouseState::DefaultMouseState(ApplicationPtr app) : MouseState(app) {}

void DefaultMouseState::press(sf::Vector2f mousePosition)
{
    std::cout << "DefaultMouseState::press <" << mousePosition.x << ", "
              << mousePosition.y << ">\n";
    auto app = this->getApplication();

    for (auto& section : app->getSections())
    {
        section->selected(mousePosition);
    }
}

void DefaultMouseState::release(sf::Vector2f mousePosition)
{
    std::cout << "DefaultMouseState::release <" << mousePosition.x << ", "
              << mousePosition.y << ">\n";
}

GenerateObjectMouseState::GenerateObjectMouseState(ApplicationPtr app)
    : MouseState(app)
{
}

void GenerateObjectMouseState::press(sf::Vector2f mousePosition)
{
    std::cout << "GenerateObjectMouseState::press <" << mousePosition.x << ", "
              << mousePosition.y << ">\n";
    auto app = this->getApplication();

    app->addObject(sf::Vector2f{static_cast<float>(mousePosition.x),
                                static_cast<float>(mousePosition.y)});

    for (auto& section : app->getSections())
    {
        section->selected(mousePosition);
    }
}

void GenerateObjectMouseState::release(sf::Vector2f mousePosition)
{
    std::cout << "GenerateObjectMouseState::release <" << mousePosition.x
              << ", " << mousePosition.y << ">\n";
}

MouseStatePtr newMouseState(std::string name, ApplicationPtr app)
{
    if ((name == "Select") || (name == "Contraints") || (name == "Delete") ||
        (name == "Interact") || (name == "Cancel"))
    {
        return std::make_shared<DefaultMouseState>(app);
    }
    else if ((name == "Object"))
    {
        return std::make_shared<GenerateObjectMouseState>(app);
    }
    else
    {
        return nullptr;
    }
}
}  // namespace physics