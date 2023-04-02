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

    this->initializeEventHandler();
    auto shared_this = shared_from_this();
    this->mMouseState = std::make_shared<DefaultMouseState>(shared_this);

    this->mWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1700, 800),
                                                       "Physics Engine");
    this->mWindow->setFramerateLimit(60);

    this->initializeSections();
}

void Application::run()
{
    while (true)
    {
        this->handleEvent();

        if (this->mWindow->isOpen())
        {
            this->clear();

            this->update();

            this->render();
        }
        else
        {
            break;
        }
    }
}

std::vector<UserInterfacePtr> Application::getSections()
{
    return this->mSections;
}

void Application::addObject(sf::Vector2f position)
{
    this->mWorld.addObject(position);
}

void Application::update() {}

void Application::render()
{
    for (auto& section : this->mSections)
    {
        section->render(*this->mWindow);
    }

    this->mWorld.render(*this->mWindow);

    this->mWindow->display();
}

void Application::handleEvent()
{
    this->mEventHandler->handleEvent(this->mWindow);
}

void Application::clear() { this->mWindow->clear(); }

UserInterfacePtr Application::createControlBox()
{
    this->mButtonNames = {"Select", "Object",   "Contraints",
                          "Delete", "Interact", "Cancel"};

    int rows = 4;
    int cols = 4;
    float margin = 0.03F;

    auto section = std::make_shared<Section>();
    size_t count = 0;
    for (auto& buttonName : mButtonNames)
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

        auto callback = [this, buttonName]() {
            this->mMouseState =
                newMouseState(buttonName, this->shared_from_this());
        };
        button->setCallback(callback);

        section->addChild(button);

        ++count;
    }

    return section;
}

void Application::initializeEventHandler()
{
    this->mEventHandler = std::make_shared<EventHandler>();
    this->initializeEventCallbacks();
}

void Application::initializeEventCallbacks()
{
    auto closedCallback = [this]() { this->mWindow->close(); };
    this->mEventHandler->addCallback(
        EventType::Closed, std::make_shared<EventCallback>(closedCallback));

    auto mouseClickCallback = [this]()
    {
        auto event = this->mEventHandler->getEvent();
        auto mousePosition =
            sf::Vector2f(static_cast<float>(event.mouseButton.x),
                         static_cast<float>(event.mouseButton.y));

        mMouseState->press(mousePosition);
    };

    this->mEventHandler->addCallback(
        EventType::MousePressed,
        std::make_shared<EventCallback>(mouseClickCallback));
}

void Application::initializeSections()
{
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
}  // namespace physics::application
