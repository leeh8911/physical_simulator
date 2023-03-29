/// @file section.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-30
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_LIB_SECTION_H_
#define SRC_LIB_SECTION_H_

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

namespace physics
{

class Section
{
 public:
    Section() = default;

    void setRelativePosition(const sf::Vector2f& position);
    void setRelativeSize(const sf::Vector2f& size);
    void setName(std::string name);
    void setColor(const sf::Color& color);

    void Render(sf::RenderWindow& window);

 private:
    std::string mName{};
    sf::Vector2f mRelativePosition{};
    sf::Vector2f mRelativeSize{};
    sf::Color mColor{};
};
using SectionPtr = std::unique_ptr<Section>;
}  // namespace physics

#endif  // SRC_LIB_SECTION_H_
