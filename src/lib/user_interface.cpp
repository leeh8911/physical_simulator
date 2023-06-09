﻿/// @file user_interface.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-31
///
/// @copyright Copyright (c) 2023
///
///

#include "src/lib/user_interface.h"

#include <iostream>

#include "src/lib/utils.h"

namespace physics
{

void TextFormat::loadFont()
{
    if (!mFont.loadFromFile("../../res/KoPubWBM.ttf"))
    {
        throw std::runtime_error("Failed to load font");
    }
}

sf::Text TextFormat::button(const std::string& text)
{
    sf::Text button;
    button.setString(text);
    button.setFont(mFont);
    button.setCharacterSize(12);
    button.setFillColor(sf::Color::Black);

    return button;
}

bool UserInterface::selected(const sf::Vector2f& mousePosition)
{
    if (this->getShape().getGlobalBounds().contains(mousePosition))
    {
        std::cout << this->getName() << " is selected\n";
        for (auto& child : mChildren)
        {
            if (child.second->selected(mousePosition))
            {
                return true;
            }
        }
    }
    return false;
}

void UserInterface::setRelativePosition(const sf::Vector2f& position)
{
    mRelativePosition = position;
}

void UserInterface::setRelativeSize(const sf::Vector2f& size)
{
    mRelativeSize = size;
}

void UserInterface::setShape(const sf::RectangleShape& shape)
{
    this->mShape = shape;
}

void UserInterface::setName(std::string name) { mName = std::move(name); }

void UserInterface::setColor(const sf::Color& color) { mColor = color; }

void UserInterface::setParent(UserInterfacePtr parent) { mParent = parent; }

sf::Vector2f UserInterface::getRelativePosition() const
{
    return mRelativePosition;
}

sf::Vector2f UserInterface::getRelativeSize() const { return mRelativeSize; }

sf::RectangleShape UserInterface::getShape() const { return mShape; }

std::string UserInterface::getName() const { return mName; }

sf::Color UserInterface::getColor() const { return mColor; }

UserInterfacePtr UserInterface::getParent() const { return mParent; }

void UserInterface::addChild(UserInterfacePtr child)
{
    child->setParent(this->shared_from_this());
    mChildren[child->getName()] = child;
}

void UserInterface::removeChild(UserInterfacePtr child)
{
    mChildren.erase(child->getName());
}

UserInterfacePtr UserInterface::getChild(std::string name)
{
    return mChildren[name];
}
UiMap UserInterface::getChildren() { return mChildren; }

void Section::render(sf::RenderWindow& window)
{
    auto windowSize = window.getSize();
    sf::Vector2f windowSizeF(static_cast<float>(windowSize.x),
                             static_cast<float>(windowSize.y));

    sf::RectangleShape rect{};
    rect.setPosition(this->getRelativePosition() * windowSizeF);
    rect.setSize(this->getRelativeSize() * windowSizeF);
    rect.setFillColor(this->getColor());
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1.0f);
    this->setShape(rect);

    window.draw(rect);

    for (auto& [name, child] : this->getChildren())
    {
        child->render(window);
    }
}

bool Button::selected(const sf::Vector2f& mousePosition)
{
    if (this->getShape().getGlobalBounds().contains(mousePosition))
    {
        (*mCallback)();
        return true;
    }
    return false;
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

    sf::RectangleShape rect{};
    rect.setPosition(relativePos);
    rect.setSize(relativeSize);
    rect.setFillColor(this->getColor());
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1.0f);
    this->setShape(rect);

    sf::Text text = TextFormat::button(this->getName());
    text.setPosition(relativePos + relativeSize / 2.0f -
                     sf::Vector2f(text.getLocalBounds().width / 2.0f,
                                  text.getLocalBounds().height / 2.0f));
    window.draw(rect);
    window.draw(text);
}

void Button::setCallback(Button::Callback callback)
{
    this->mCallback = std::make_shared<Button::Callback>(callback);
}

}  // namespace physics