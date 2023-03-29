/// @file application.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-30
///
/// @copyright Copyright (c) 2023
///
///

#include "src/lib/application.h"

#include <utility>

namespace physics::application
{
void Application::initialize()
{
    this->mWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600),
                                                       "Physics Engine");
    this->mWindow->setFramerateLimit(60);

    this->mSections.emplace_back(std::make_unique<Section>());
    this->mSections.back()->setRelativePosition({0.0f, 0.0f});
    this->mSections.back()->setRelativeSize({1.0f, 1.0f});
    this->mSections.back()->setColor(sf::Color::Black);
    this->mSections.back()->setName("WorldView");

    this->mSections.emplace_back(std::make_unique<Section>());
    this->mSections.back()->setRelativePosition({0.0f, 0.7f});
    this->mSections.back()->setRelativeSize({0.2f, 0.3f});
    this->mSections.back()->setColor(sf::Color::Green);
    this->mSections.back()->setName("MiniMap");

    this->mSections.emplace_back(std::make_unique<Section>());
    this->mSections.back()->setRelativePosition({0.2f, 0.8f});
    this->mSections.back()->setRelativeSize({0.6f, 0.2f});
    this->mSections.back()->setColor(sf::Color::Green);
    this->mSections.back()->setName("Dialog");

    this->mSections.emplace_back(std::make_unique<Section>());
    this->mSections.back()->setRelativePosition({0.8f, 0.7f});
    this->mSections.back()->setRelativeSize({0.2f, 0.3f});
    this->mSections.back()->setColor(sf::Color::Green);
    this->mSections.back()->setName("ControlBox");
}

void Application::run()
{
    while (true)
    {
        this->clear();
        sf::Event event{};
        while (this->mWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->mWindow->close();
                return;
            }
        }
        this->update();
        this->render();
    }
}

void Application::update() {}

void Application::render()
{
    for (auto& section : this->mSections)
    {
        section->Render(*this->mWindow);
    }

    this->mWindow->display();
}

void Application::clear() { this->mWindow->clear(); }
}  // namespace physics::application
