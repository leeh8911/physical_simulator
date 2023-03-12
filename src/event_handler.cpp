/// @file event_handler.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-12
///
/// @copyright Copyright (c) 2023
///
///

#include "src/event_handler.h"

namespace engine
{
void EventManager::AddProcess(sf::Event::EventType event_type,
                              std::function<void(sf::Event)> callback)
{
    process_map_[event_type] = callback;
}

void EventManager::Process(sf::Event event)
{
    auto found = process_map_.find(event.type);
    if (found != process_map_.end())
    {
        process_map_[event.type](event);
    }
}
}  // namespace engine