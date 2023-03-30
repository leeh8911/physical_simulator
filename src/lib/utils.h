/// @file utils.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-30
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_LIB_UTILS_H_
#define SRC_LIB_UTILS_H_

#include <SFML/Graphics.hpp>

namespace physics
{
template <typename T>
sf::Vector2<T> operator*(const sf::Vector2<T>& lhs, const sf::Vector2<T>& rhs)
{
    return sf::Vector2<T>(lhs.x * rhs.x, lhs.y * rhs.y);
}

template <typename T>
sf::Vector2<T> operator*=(const sf::Vector2<T>& lhs, const sf::Vector2<T>& rhs)
{
    return sf::Vector2<T>(lhs.x * rhs.x, lhs.y * rhs.y);
}

}  // namespace physics

#endif  // SRC_LIB_UTILS_H_
