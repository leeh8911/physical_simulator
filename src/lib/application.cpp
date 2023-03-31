/// @file application.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-30
///
/// @copyright Copyright (c) 2023
///
///

#include "src/lib/application.h"

#include <chrono>
#include <utility>

#include "src/lib/user_interface.h"

namespace physics::application
{

void Application::initialize()
{
    TextFormat::loadFont();

    this->mWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1700, 800),
                                                       "Physics Engine");
    this->mWindow->setFramerateLimit(60);

    this->mSections.emplace_back(std::make_shared<Section>());
    this->mSections.back()->setRelativePosition({0.0f, 0.0f});
    this->mSections.back()->setRelativeSize({1.0f, 1.0f});
    this->mSections.back()->setColor(sf::Color::Black);
    this->mSections.back()->setName("WorldView");

    this->mSections.emplace_back(std::make_shared<Section>());
    this->mSections.back()->setRelativePosition({0.0f, 0.7f});
    this->mSections.back()->setRelativeSize({0.2f, 0.3f});
    this->mSections.back()->setColor(sf::Color(51, 51, 51, 255));
    this->mSections.back()->setName("MiniMap");

    this->mSections.emplace_back(std::make_shared<Section>());
    this->mSections.back()->setRelativePosition({0.2f, 0.8f});
    this->mSections.back()->setRelativeSize({0.6f, 0.2f});
    this->mSections.back()->setColor(sf::Color(51, 51, 51, 255));
    this->mSections.back()->setName("Dialog");

    this->mSections.emplace_back(this->createControlBox());
    this->mSections.back()->setRelativePosition({0.8f, 0.7f});
    this->mSections.back()->setRelativeSize({0.2f, 0.3f});
    this->mSections.back()->setColor(sf::Color(51, 51, 51, 255));
    this->mSections.back()->setName("ControlBox");
}

void Application::run()
{
    while (true)
    {
        this->clear();
        sf::Event event{};
        while (this->mWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->mWindow->close();
                return;
            }
        }
        this->update();
        this->render();
    }
}

void Application::update() {}

void Application::render()
{
    for (auto& section : this->mSections)
    {
        section->render(*this->mWindow);
    }

    this->mWindow->display();
}

void Application::pollEvent() {}

void Application::clear() { this->mWindow->clear(); }

UserInterfacePtr Application::createControlBox()
{
    std::vector<std::string> buttonNames = {"Select", "Object", "Delete",
                                            "Contraints", "Interact"};

    int rows = 4;
    int cols = 4;
    float margin = 0.03F;

    auto section = std::make_shared<Section>();
    size_t count = 0;
    for (auto& buttonName : buttonNames)
    {
        size_t row = count / cols;
        size_t col = count % cols;

        sf::Vector2f position = {margin + (1.0F / cols) * col,
                                 margin + (1.0F / rows) * row};
        sf::Vector2f size = {(1.0F / cols) - margin * 2,
                             (1.0F / rows) - margin * 2};

        auto button = std::make_shared<Button>();
        button->setName(buttonName);
        button->setRelativePosition(position);
        button->setRelativeSize(size);
        button->setColor(sf::Color(51, 51, 102, 255));

        section->addChild(button);

        ++count;
    }

    return section;
}
}  // namespace physics::application
