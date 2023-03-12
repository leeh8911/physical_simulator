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
#include <array>
#include <iostream>
#include <string>

namespace engine
{

Application::Application(std::string name, sf::Vector2u window_size)
    : name_(std::move(name)),
      window_(sf::VideoMode(window_size.x, window_size.y), name_),
      renderer_{window_size}
{
    window_.setFramerateLimit(60U);
}

void Application::InitializeEventProcess()
{
    auto mouse_click_callback = [this](sf::Event event)
    {
        std::cout << event.mouseButton.button << "[" << event.mouseButton.x
                  << ", " << event.mouseButton.y << "]" << std::endl;
    };
    event_handler_.AddProcess(sf::Event::EventType::MouseButtonPressed,
                              mouse_click_callback);

    auto terminate_callback = [this](sf::Event event)
    {
        std::cout << "terminate" << event.type << std::endl;
        window_.close();
    };
    event_handler_.AddProcess(sf::Event::EventType::Closed, terminate_callback);
}

bool Application::Run()
{
    InitializeEventProcess();

    while (window_.isOpen())
    {
        window_.clear(sf::Color::Black);

        renderer_.Render(window_);

        window_.display();

        sf::Event event{};

        while (window_.pollEvent(event))
        {
            event_handler_.Process(event);
        }
    }
    return true;
}
}  // namespace engine