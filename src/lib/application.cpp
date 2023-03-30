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

#include <utility>

namespace physics::application
{
void Application::initialize()
{
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

void Application::clear() { this->mWindow->clear(); }

UserInterfacePtr Application::createControlBox()
{
    auto selectButton = std::make_shared<Button>();
    selectButton->setName("Select");
    selectButton->setRelativePosition({0.03F, 0.03F});
    selectButton->setRelativeSize({0.2F, 0.2F});
    selectButton->setColor(sf::Color(51, 51, 102, 255));
    auto objectButton = std::make_shared<Button>();
    objectButton->setName("Object");
    objectButton->setRelativePosition({0.26F, 0.03F});
    objectButton->setRelativeSize({0.2F, 0.2F});
    objectButton->setColor(sf::Color(51, 51, 102, 255));
    auto deleteButton = std::make_shared<Button>();
    deleteButton->setName("Delete");
    deleteButton->setRelativePosition({0.49F, 0.03F});
    deleteButton->setRelativeSize({0.2F, 0.2F});
    deleteButton->setColor(sf::Color(51, 51, 102, 255));
    auto contraintsButton = std::make_shared<Button>();
    contraintsButton->setName("Contraints");
    contraintsButton->setRelativePosition({0.72F, 0.03F});
    contraintsButton->setRelativeSize({0.2F, 0.2F});
    contraintsButton->setColor(sf::Color(51, 51, 102, 255));
    auto interactButton = std::make_shared<Button>();
    interactButton->setName("Interact");
    interactButton->setRelativePosition({0.03F, 0.26F});
    interactButton->setRelativeSize({0.2F, 0.2F});
    interactButton->setColor(sf::Color(51, 51, 102, 255));

    auto section = std::make_shared<Section>();
    section->addChild(selectButton);
    section->addChild(objectButton);
    section->addChild(deleteButton);
    section->addChild(contraintsButton);
    section->addChild(interactButton);

    return section;
}
}  // namespace physics::application
