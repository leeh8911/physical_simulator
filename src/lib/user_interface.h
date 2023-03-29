/// @file user_interface.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-30
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_LIB_USER_INTERFACE_H_
#define SRC_LIB_USER_INTERFACE_H_

#include <memory>

namespace physics
{

class UserInterface
{
};
using UserInterfacePtr = std::unique_ptr<UserInterface>;
}  // namespace physics

#endif  // SRC_LIB_USER_INTERFACE_H_
