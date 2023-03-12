/// @file utils.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-13
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_

#include <Eigen/Dense>
#include <SFML/Graphics.hpp>

namespace engine
{
inline sf::Vector2f EigenToSFVector(Eigen::Vector2d eigen_vector)
{
    return sf::Vector2f{static_cast<float>(eigen_vector[0]),
                        static_cast<float>(eigen_vector[1])};
}
inline Eigen::Vector2d SFToEigenVector(sf::Vector2f sf_vector)
{
    return Eigen::Vector2d{static_cast<double>(sf_vector.x),
                           static_cast<double>(sf_vector.y)};
}
inline sf::Color EigenToSFColor(Eigen::Vector4d eigen_color)
{
    return sf::Color{static_cast<uint8_t>(eigen_color[0]),
                     static_cast<uint8_t>(eigen_color[1]),
                     static_cast<uint8_t>(eigen_color[2]),
                     static_cast<uint8_t>(eigen_color[3])};
}
inline Eigen::Vector4d SFToEigenColor(sf::Color sf_color)
{
    return Eigen::Vector4d{
        static_cast<double>(sf_color.r), static_cast<double>(sf_color.g),
        static_cast<double>(sf_color.b), static_cast<double>(sf_color.a)};
}
}  // namespace engine

#endif