/// @file physical_solver.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-12
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_PHYSICAL_SOLVER_H_
#define SRC_PHYSICAL_SOLVER_H_

#include <functional>

#include "src/event_handler.h"

namespace engine
{

class Solution
{
};

class PhysicalSolver
{
 public:
    PhysicalSolver(sf::Vector2u world_size);
    Solution operator()(const Event& event);
};
}  // namespace engine

#endif  // SRC_PHYSICAL_SOLVER_H_
