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

 private:
    double radius_{};
    std::shared_ptr<sf::CircleShape> drawable_{};
};

class ObjectHandler
{
 public:
    ObjectHandler(sf::Vector2f world_origin);
    ObjectHandler() = default;
    ~ObjectHandler() = default;

    void SetWorldOrigin(sf::RectangleShape world_box);
    void AddObject(PhysicalObjectPtr object);
    void RemoveObject(PhysicalObjectPtr object);

    void CreateCircle(sf::Vector2f center, double radius, sf::Vector2f velocity,
                      sf::Color color);

    PhysicalObjectPtrList GetObjects() const;
    std::vector<DrawablePtr> ToDrawables() const;

 private:
    Eigen::Vector2d ConvertWindowToWorld(sf::Vector2f window_pos) const;
    sf::Vector2f ConvertWorldToWindow(Eigen::Vector2d world_pos) const;
    Eigen::Vector4d ConvertColor(sf::Color color) const;
    sf::Color ConvertColor(Eigen::Vector4d color) const;
    DrawablePtr ConvertDrawable(Circle object) const;

    PhysicalObjectPtrList objects_{};

    sf::Vector2f world_origin_{};
    sf::RectangleShape world_box_{};
};
}  // namespace engine
#endif  // SRC_PHYSICAL_OBJECT_H_