/// @file world.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-30
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_LIB_WORLD_H_
#define SRC_LIB_WORLD_H_

#include <SFML/Graphics.hpp>
#include <memory>
#include <variant>
#include <vector>

namespace physics
{
class Circle2D
{
 public:
    Circle2D() = default;
    Circle2D(sf::Vector2f position, float radius);
    ~Circle2D() = default;

    sf::Vector2f getPosition() const;
    float getRadius() const;

 private:
    sf::Vector2f mPosition{};
    float mRadius{};
};

class World
{
 public:
    World() = default;
    ~World() = default;

    void addObject(sf::Vector2f position, float radius = 1.F);
    void addObject(Circle2D object);

    std::vector<Circle2D> getObjects();

    void render(sf::RenderWindow& window) const;

 private:
    std::vector<Circle2D> mObjects{};
};
using WorldPtr = std::unique_ptr<World>;
}  // namespace physics

#endif  // SRC_LIB_WORLD_H_
