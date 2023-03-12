/// @file event_handler.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-12
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_EVENT_HANDLER_H_
#define SRC_EVENT_HANDLER_H_

#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>

namespace engine
{
class EventManager
{
 public:
    EventManager() = default;
    ~EventManager() = default;

    void AddProcess(sf::Event::EventType event_type,
                    std::function<void(sf::Event)> callback);

    void Process(sf::Event event);

 private:
    std::unordered_map<sf::Event::EventType, std::function<void(sf::Event)>>
        process_map_{};
};
}  // namespace engine

#endif  // SRC_EVENT_HANDLER_H_
