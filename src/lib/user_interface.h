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
#include <memory>
#include <unordered_map>

namespace physics
{

class UserInterface;
using UserInterfacePtr = std::shared_ptr<UserInterface>;

class UserInterface : public std::enable_shared_from_this<UserInterface>
{
 public:
    UserInterface() = default;
    virtual ~UserInterface() = default;

    void setRelativePosition(const sf::Vector2f& position);
    void setRelativeSize(const sf::Vector2f& size);
    void setName(std::string name);
    void setColor(const sf::Color& color);
    void setParent(UserInterfacePtr parent);

    sf::Vector2f getRelativePosition() const;
    sf::Vector2f getRelativeSize() const;
    std::string getName() const;
    sf::Color getColor() const;
    UserInterfacePtr getParent() const;

    virtual void render(sf::RenderWindow& window) = 0;

 private:
    UserInterfacePtr mParent{nullptr};

    std::string mName{};
    sf::Vector2f mRelativePosition{};
    sf::Vector2f mRelativeSize{};
    sf::Color mColor{};
};

class Section : public UserInterface
{
 public:
    using UiMap = std::unordered_map<std::string, UserInterfacePtr>;

    Section() = default;
    ~Section() override = default;

    void addChild(UserInterfacePtr child);
    void removeChild(UserInterfacePtr child);

    UserInterfacePtr getChild(std::string name);

    void render(sf::RenderWindow& window) override;

 private:
    UiMap mChildren;
};

class Button : public UserInterface
{
 public:
    Button() = default;
    ~Button() override = default;

    void render(sf::RenderWindow& window) override;
};

}  // namespace physics

#endif  // SRC_LIB_USER_INTERFACE_H_
