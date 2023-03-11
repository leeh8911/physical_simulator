/// @file renderer.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-12
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_RENDERER_H_
#define SRC_RENDERER_H_

#include <SFML/Graphics.hpp>

#include "src/event_handler.h"
#include "src/physical_solver.h"

namespace engine
{
class Renderer
{
 public:
    Renderer();
    void operator()(const Event& event, const Solution& solution);

 private:
};
}  // namespace engine

#endif  // SRC_RENDERER_H_
