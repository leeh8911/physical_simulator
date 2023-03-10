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

// TODO : 마우스 클릭을 통해 원을 생성하기
// TODO : 생성된 객체가 바닥으로 떨어지게 하기
// TODO : 생성된 객체가 다른 객체와 충돌확인 하기
// TODO : 충돌한 객체가 서로 반발력을 주고받게 하기

int main(int argc, char** argv)
{
    std::cout << argc << ", " << argv[0] << std::endl;

    sf::Clock clock{};

    float interval = 0.F;

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
            if (event.type == sf::Event::EventType::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i position = sf::Mouse::getPosition(window);
                    std::cout << "Mouse Left Clicked! " << position.x << ", "
                              << position.y << std::endl;
                }
            }
        }

        window.clear(sf::Color::White);
        window.display();
    }
    return 0;
}