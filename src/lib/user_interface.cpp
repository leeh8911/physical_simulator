/// @file user_interface.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-31
///
/// @copyright Copyright (c) 2023
///
///

#include "src/lib/user_interface.h"

#include "src/lib/utils.h"

namespace physics
{

void UserInterface::setRelativePosition(const sf::Vector2f& position)
{
    mRelativePosition = position;
}

void UserInterface::setRelativeSize(const sf::Vector2f& size)
{
    mRelativeSize = size;
}

void UserInterface::setName(std::string name) { mName = std::move(name); }

void UserInterface::setColor(const sf::Color& color) { mColor = color; }

void UserInterface::setParent(UserInterfacePtr parent) { mParent = parent; }

sf::Vector2f UserInterface::getRelativePosition() const
{
    return mRelativePosition;
}

sf::Vector2f UserInterface::getRelativeSize() const { return mRelativeSize; }

std::string UserInterface::getName() const { return mName; }

sf::Color UserInterface::getColor() const { return mColor; }

UserInterfacePtr UserInterface::getParent() const { return mParent; }

void Section::addChild(UserInterfacePtr child)
{
    child->setParent(this->shared_from_this());
    mChildren[child->getName()] = child;
}

void Section::removeChild(UserInterfacePtr child)
{
    mChildren.erase(child->getName());
}

UserInterfacePtr Section::getChild(std::string name) { return mChildren[name]; }

void Section::render(sf::RenderWindow& window)
{
    auto windowSize = window.getSize();
    sf::Vector2f windowSizeF(static_cast<float>(windowSize.x),
                             static_cast<float>(windowSize.y));

    sf::RectangleShape rect;
    rect.setPosition(this->getRelativePosition() * windowSizeF);
    rect.setSize(this->getRelativeSize() * windowSizeF);
    rect.setFillColor(this->getColor());
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1.0f);

    window.draw(rect);

    for (auto& [name, child] : mChildren)
    {
        child->render(window);
    }
}

void Button::render(sf::RenderWindow& window)
{
    auto windowSize = window.getSize();
    sf::Vector2f windowSizeF(static_cast<float>(windowSize.x),
                             static_cast<float>(windowSize.y));

    sf::Vector2f parentSize =
        this->getParent()->getRelativeSize() * windowSizeF;
    sf::Vector2f parentPos =
        this->getParent()->getRelativePosition() * windowSizeF;

    sf::Vector2f relativePos =
        this->getRelativePosition() * parentSize + parentPos;
    sf::Vector2f relativeSize = this->getRelativeSize() * parentSize;

    sf::RectangleShape rect;
    rect.setPosition(relativePos);
    rect.setSize(relativeSize);
    rect.setFillColor(this->getColor());
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1.0f);

    window.draw(rect);
}
}  // namespace physics