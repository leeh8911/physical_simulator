/// @file object.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-11
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_OBJECT_H_
#define SRC_OBJECT_H_

#include <Eigen/Dense>

namespace engine
{
class PhysicalObject
{
 public:
    PhysicalObject(Eigen::Vector2d position);
    PhysicalObject(Eigen::Vector2d position, double raidus, double mass);

    Eigen::Vector2d GetPosition() const;
    Eigen::Vector2d GetVelocity() const;
    double GetRadius() const;
    double GetMass() const;

    void SetPosition(Eigen::Vector2d position);
    void SetVelocity(Eigen::Vector2d velocity);

    void Update(double interval);
    void Accelerate(Eigen::Vector2d force);
    void Collide(PhysicalObject& other);
    void Collide(Eigen::Vector2d left_top,
                 Eigen::Vector2d right_bottom);  // Collision with wall

 private:
    Eigen::Vector2d position_{0.0, 0.0};
    Eigen::Vector2d velocity_{0.0, 0.0};
    Eigen::Vector2d acceleration_{0.0, 0.0};
    double radius_{1.0};
    double mass_{1.0};
};
}  // namespace engine

#endif  // SRC_OBJECT_H_
