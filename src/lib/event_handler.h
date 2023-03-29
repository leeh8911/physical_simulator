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

#include <memory>
namespace physics
{

class EventHandler
{
};
using EventHandlerPtr = std::unique_ptr<EventHandler>;
}  // namespace physics

#endif  // SRC_LIB_EVENT_HANDLER_H_
