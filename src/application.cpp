/// @file application.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-12
///
/// @copyright Copyright (c) 2023
///
///

#include "src/application.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "src/event_handler.h"
#include "src/physical_solver.h"
#include "src/renderer.h"

namespace engine
{
Application::Application(std::string name, sf::Vector2u window_size,
                         sf::Vector2u world_size)
    : name_(std::move(name)),
      window_(sf::VideoMode(window_size.x, window_size.y), name_),
      solver_(world_size),
      event_handler_(),
      renderer_()
{
    window_.setFramerateLimit(60);
}

bool Application::Run()
{
    while (window_.isOpen())
    {
        window_.clear();

        event = event_handler_();

        if (event.Terminate())
        {
            window_.close();
            break;
        }

        results = solver_(event);

        renderer_(event, results);

        window_.display();
    }
    return true;
}
}  // namespace engine