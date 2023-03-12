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
    Renderer(sf::Vector2u window_size);
    ~Renderer() = default;

    void Render(sf::RenderWindow& window);

 private:
    sf::RectangleShape world_box_{};
    sf::RectangleShape dashboard_box_{};
};
}  // namespace engine

#endif  // SRC_RENDERER_H_
