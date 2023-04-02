/// @file mouse_state.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-04-02
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_LIB_MOUSE_STATE_H_
#define SRC_LIB_MOUSE_STATE_H_

#include <SFML/Graphics.hpp>

namespace physics
{

namespace application
{
class Application;
}
using ApplicationPtr = std::shared_ptr<application::Application>;

class MouseState
{
 public:
    MouseState(ApplicationPtr app);
    virtual ~MouseState() = default;

    virtual void press(sf::Vector2f) = 0;
    virtual void release(sf::Vector2f) = 0;

    ApplicationPtr getApplication();

 private:
    ApplicationPtr mApp{nullptr};
};
using MouseStatePtr = std::shared_ptr<MouseState>;

class DefaultMouseState : public MouseState
{
 public:
    DefaultMouseState(ApplicationPtr app);

    void press(sf::Vector2f mousePosition) override;
    void release(sf::Vector2f mousePosition) override;

 private:
};

class GenerateObjectMouseState : public MouseState
{
 public:
    GenerateObjectMouseState(ApplicationPtr app);

    void press(sf::Vector2f mousePosition) override;
    void release(sf::Vector2f mousePosition) override;

 private:
};

MouseStatePtr newMouseState(std::string name, ApplicationPtr app);
}  // namespace physics
#endif  // SRC_LIB_MOUSE_STATE_H_
