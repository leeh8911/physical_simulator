/// @file main.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-10
///
/// @copyright Copyright (c) 2023
///
///

#include <Eigen/Dense>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <vector>

#include "..\src\physics.h"

// TODO : 마우스 클릭을 통해 원을 생성하기
// TODO : 생성된 객체가 바닥으로 떨어지게 하기
// TODO : 생성된 객체가 다른 객체와 충돌확인 하기
// TODO : 충돌한 객체가 서로 반발력을 주고받게 하기

static void EventHandle(sf::RenderWindow& window,
                        std::vector<engine::PhysicalObject>& circles);

static void Draw(sf::RenderWindow& window,
                 std::vector<engine::PhysicalObject>& circle, sf::Text time);

static void Update(std::vector<engine::PhysicalObject>& objects,
                   float interval);

int main(int argc, char** argv)
{
    std::cout << argc << ", " << argv[0] << std::endl;

    sf::Clock clock{};

    float interval = 0.F;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    std::cout << window.getSize().x << window.getSize().y << "\n";
    window.setFramerateLimit(60);

    std::vector<engine::PhysicalObject> circles{};

    sf::Text text;
    text.setPosition({400, 300});
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        text.setString("Time : " + std::to_string(time) + "s");

        clock.restart();

        interval += time;

        window.clear(sf::Color::Transparent);

        EventHandle(window, circles);

        Update(circles, time);

        Draw(window, circles, text);

        window.display();
    }
    return 0;
}

void EventHandle(sf::RenderWindow& window,
                 std::vector<engine::PhysicalObject>& circles)
{
    sf::Event event{};
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case (sf::Event::EventType::Closed):
            {
                std::cout << "Terminated Program!";
                window.close();
                break;
            }
            case (sf::Event::EventType::MouseButtonPressed):
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i position = sf::Mouse::getPosition(window);
                    circles.emplace_back(engine::PhysicalObject{
                        {position.x, position.y}, 30, 30});

                    circles.back().SetVelocity(Eigen::Vector2d::Random() * 100);
                }
                break;
            }
            default:
                break;
        }
    }
}

void Draw(sf::RenderWindow& window,
          std::vector<engine::PhysicalObject>& circles, sf::Text time)
{
    std::vector<sf::CircleShape> circle_shapes(circles.size());

    std::transform(std::begin(circles), std::end(circles),
                   std::begin(circle_shapes),
                   [](const auto& circle)
                   {
                       sf::CircleShape circle_shape(
                           static_cast<float>(circle.GetRadius()));
                       circle_shape.setFillColor(sf::Color::Red);
                       circle_shape.setPosition(
                           static_cast<float>(circle.GetPosition().x()),
                           static_cast<float>(circle.GetPosition().y()));
                       return circle_shape;
                   });

    for (const auto& circle_shape : circle_shapes)
    {
        window.draw(circle_shape);
    }

    window.draw(time);
}

void Update(std::vector<engine::PhysicalObject>& objects, float interval)
{
    // check collision between objects
    for (size_t i = 0; i < objects.size(); ++i)
    {
        for (size_t j = i + 1; j < objects.size(); ++j)
        {
            if ((objects[i].GetPosition() - objects[j].GetPosition()).norm() <
                objects[i].GetRadius() + objects[j].GetRadius())
            {
                objects[i].Collide(objects[j]);
            }
        }
    }

    // check collision between objects and wall
    for (auto& obj : objects)
    {
        obj.Collide(Eigen::Vector2d{0.0, 0.0}, Eigen::Vector2d{800.0, 600.0});
    }

    for (auto& obj : objects)
    {
        obj.Accelerate({0.0, 9.8});
    }

    for (auto& obj : objects)
    {
        obj.Update(interval);
    }
}