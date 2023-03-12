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

namespace engine
{
class Renderer
{
 public:
    Renderer() = default;
    ~Renderer() = default;

    Renderer(sf::Vector2u world_size) : world_size_(world_size){};

 private:
    sf::Vector2u world_size_{};
};
}  // namespace engine

#endif  // SRC_RENDERER_H_
