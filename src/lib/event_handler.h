/// @file event_handler.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-30
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_LIB_EVENT_HANDLER_H_
#define SRC_LIB_EVENT_HANDLER_H_

#include <SFML/Graphics.hpp>
#include <functional>
#include <map>
#include <memory>
#include <unordered_map>

namespace physics
{

enum class EventType
{
    None = 0,
    Closed,
    MousePressed,
    MouseReleased,
    KeyPressed,
    KeyReleased,
    Count
};

using EventCallback = std::function<void(void)>;
using EventCallbackPtr = std::shared_ptr<EventCallback>;
using EventCallbackMap = std::map<EventType, EventCallbackPtr>;

class EventHandler
{
 public:
    EventHandler();
    virtual ~EventHandler() = default;

    void handleEvent(std::shared_ptr<sf::RenderWindow> window);

    sf::Event getEvent() const;

    void addCallback(EventType type, EventCallbackPtr callback);
    void removeCallback(EventType type);

 private:
    void invokeCallback(EventType type);

    EventCallbackMap mCallbacks{};
    sf::Event mEvent{};
};
using EventHandlerPtr = std::shared_ptr<EventHandler>;

}  // namespace physics

#endif  // SRC_LIB_EVENT_HANDLER_H_
