/// @file event_handler.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-04-01
///
/// @copyright Copyright (c) 2023
///
///

#include "src/lib/event_handler.h"

#include <SFML/Graphics.hpp>

namespace physics
{
EventHandler::EventHandler() : mCallbacks() {}

void EventHandler::handleEvent(std::shared_ptr<sf::RenderWindow> window)
{
    EventType type = EventType::None;
    while (window->pollEvent(this->mEvent))
    {
        switch (this->mEvent.type)
        {
            case sf::Event::Closed:
                type = EventType::Closed;
                break;
            case sf::Event::MouseButtonPressed:
                type = EventType::MousePressed;
                break;
            case sf::Event::MouseButtonReleased:
                type = EventType::MouseReleased;
                break;
            case sf::Event::KeyPressed:
                type = EventType::KeyPressed;
                break;
            default:
                type = EventType::None;
        }

        invokeCallback(type);
    }
}

sf::Event EventHandler::getEvent() const { return this->mEvent; }

void EventHandler::addCallback(EventType type, EventCallbackPtr callback)
{
    this->mCallbacks.insert(std::make_pair(type, callback));
}

void EventHandler::removeCallback(EventType type)
{
    this->mCallbacks.erase(type);
}

void EventHandler::invokeCallback(EventType type)
{
    if (this->mCallbacks.find(type) != this->mCallbacks.end())
    {
        (*this->mCallbacks[type])();
    }
}

}  // namespace physics