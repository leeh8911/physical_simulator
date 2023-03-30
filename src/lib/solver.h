/// @file solver.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-30
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_LIB_SOLVER_H_
#define SRC_LIB_SOLVER_H_

#include <memory>
namespace physics
{
class Solver
{
};
using SolverPtr = std::unique_ptr<Solver>;
}  // namespace physics

#endif  // SRC_LIB_SOLVER_H_
