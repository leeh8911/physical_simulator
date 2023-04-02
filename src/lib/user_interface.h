/// @file user_interface.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-30
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_LIB_USER_INTERFACE_H_
#define SRC_LIB_USER_INTERFACE_H_

#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>
#include <unordered_map>

#include "src/lib/mouse_state.h"


namespace physics
{

class TextFormat
{
 public:
    static void loadFont();
    static sf::Text button(const std::string& text);

 private:
    inline static sf::Font mFont{};
};

class UserInterface;
using UserInterfacePtr = std::shared_ptr<UserInterface>;
using UiMap = std::unordered_map<std::string, UserInterfacePtr>;

class UserInterface : public std::enable_shared_from_this<UserInterface>
{
 public:
    UserInterface() = default;
    virtual ~UserInterface() = default;

    virtual bool selected(const sf::Vector2f& mousePosition);

    void addChild(UserInterfacePtr child);
    void removeChild(UserInterfacePtr child);

    UserInterfacePtr getChild(std::string name);
    UiMap getChildren();

    void setRelativePosition(const sf::Vector2f& position);
    void setRelativeSize(const sf::Vector2f& size);
    void setShape(const sf::RectangleShape& shape);
    void setName(std::string name);
    void setColor(const sf::Color& color);
    void setParent(UserInterfacePtr parent);

    sf::Vector2f getRelativePosition() const;
    sf::Vector2f getRelativeSize() const;
    sf::RectangleShape getShape() const;
    std::string getName() const;
    sf::Color getColor() const;
    UserInterfacePtr getParent() const;

    virtual void render(sf::RenderWindow& window) = 0;

 private:
    UserInterfacePtr mParent{nullptr};
    UiMap mChildren;

    std::string mName{};
    sf::Vector2f mRelativePosition{};
    sf::Vector2f mRelativeSize{};
    sf::RectangleShape mShape{};
    sf::Color mColor{};
};

class Section : public UserInterface
{
 public:
    Section() = default;
    ~Section() override = default;

    void render(sf::RenderWindow& window) override;
};

class Button : public UserInterface
{
 public:
    using Callback = std::function<void()>;

    Button() = default;
    ~Button() override = default;

    bool selected(const sf::Vector2f& mousePosition) override;
    void render(sf::RenderWindow& window) override;

    void setCallback(Button::Callback callback);

 private:
    std::shared_ptr<Callback> mCallback{};
};

}  // namespace physics

#endif  // SRC_LIB_USER_INTERFACE_H_
