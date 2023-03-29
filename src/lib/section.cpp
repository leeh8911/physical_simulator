/// @file section.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-30
///
/// @copyright Copyright (c) 2023
///
///

#include "src/lib/section.h"

#include "src/lib/utils.h"

namespace physics
{
void Section::setRelativePosition(const sf::Vector2f& position)
{
    mRelativePosition = position;
}

void Section::setRelativeSize(const sf::Vector2f& size)
{
    mRelativeSize = size;
}

void Section::setName(std::string name) { mName = std::move(name); }

void Section::setColor(const sf::Color& color) { mColor = color; }

void Section::Render(sf::RenderWindow& window)
{
    auto windowSize = window.getSize();
    sf::Vector2f windowSizeF(static_cast<float>(windowSize.x),
                             static_cast<float>(windowSize.y));

    sf::RectangleShape rect;
    rect.setPosition(mRelativePosition * windowSizeF);
    rect.setSize(mRelativeSize * windowSizeF);
    rect.setFillColor(mColor);
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1.0f);

    window.draw(rect);
}

}  // namespace physics