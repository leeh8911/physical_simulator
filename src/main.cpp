/// @file main.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-10
///
/// @copyright Copyright (c) 2023
///
///

#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << argc << ", " << argv[0] << std::endl;

    sf::RectangleShape rect(sf::Vector2f(200, 200));
    rect.setFillColor(sf::Color::Red);

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                std::cout << "Terminated Program!";
                window.close();
            }
        }

        window.clear();
        window.draw(rect);
        window.display();
    }
    return 0;
}