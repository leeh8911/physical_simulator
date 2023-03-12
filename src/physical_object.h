/// @file physical_object.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-13
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_PHYSICAL_OBJECT_H_
#define SRC_PHYSICAL_OBJECT_H_

#include <Eigen/Dense>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

namespace engine
{
using DrawablePtr = std::shared_ptr<sf::Drawable>;

class PhysicalObject
{
 public:
    PhysicalObject() = default;
    virtual ~PhysicalObject() = default;

    PhysicalObject(Eigen::Vector2d center, Eigen::Vector2d velocity,
                   Eigen::Vector4d color);

    void SetCenter(Eigen::Vector2d center);
    void SetVelocity(Eigen::Vector2d velocity);
    void SetAcceleration(Eigen::Vector2d acceleration);
    void SetColor(Eigen::Vector4d color);

    Eigen::Vector2d GetCenter() const;
    Eigen::Vector2d GetVelocity() const;
    Eigen::Vector2d GetAcceleration() const;
    Eigen::Vector4d GetColor() const;

    void Update(double delta_time);

    virtual DrawablePtr GetDrawable() const = 0;

 private:
    Eigen::Vector2d center_{0.0, 0.0};
    Eigen::Vector2d velocity_{0.0, 0.0};
    Eigen::Vector2d acceleration_{0.0, 0.0};
    Eigen::Vector4d color_{0.0, 0.0, 0.0, 1.0};
};

using PhysicalObjectPtr = std::shared_ptr<PhysicalObject>;
using PhysicalObjectPtrList = std::vector<PhysicalObjectPtr>;

class Circle : public PhysicalObject
{
 public:
    Circle() = default;

    Circle(Eigen::Vector2d center, double radius, Eigen::Vector2d velocity,
           Eigen::Vector4d color);

    void SetRadius(double radius);
    double GetRadius() const;

    DrawablePtr GetDrawable() const override;

 private:
    double radius_{};
    std::shared_ptr<sf::CircleShape> drawable_{};
};
}  // namespace engine
#endif  // SRC_PHYSICAL_OBJECT_H_