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

    sf::Clock clock{};
    sf::Clock ai_timer{};

    float interval = 0.F;

    const sf::Time ai_time = sf::seconds(0.5F);

    sf::RectangleShape rect(sf::Vector2f(200, 200));
    rect.setFillColor(sf::Color::Red);

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();

        interval += time;

        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                std::cout << "Terminated Program!";
                window.close();
            }
        }

        if (ai_timer.getElapsedTime().asSeconds() > ai_time.asSeconds())
        {
            std::cout << "AI Timer: " << ai_timer.getElapsedTime().asSeconds()
                      << std::endl;
            ai_timer.restart();
        }

        if (static_cast<size_t>(interval) % 2 == 0)
        {
            window.clear(sf::Color::White);
        }
        else
        {
            window.clear(sf::Color::Black);
        }
        window.draw(rect);
        window.display();
    }
    return 0;
}