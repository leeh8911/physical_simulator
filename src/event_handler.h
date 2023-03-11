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

#include "src/physical_solver.h"
namespace engine
{

class Event
{
};

class EventHandler
{
 public:
    EventHandler();

    Event operator()();
};
}  // namespace engine

#endif  // SRC_EVENT_HANDLER_H_
