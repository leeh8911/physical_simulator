/// @file application.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-12
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_APPLICATION_H_
#define SRC_APPLICATION_H_

#include <SFML/Graphics.hpp>
#include <array>
#include <memory>
#include <string>
#include <thread>
#include <vector>

#include "src/event_handler.h"
#include "src/physical_object.h"
#include "src/renderer.h"

namespace engine
{
class Application
{
 public:
    Application(std::string name, sf::Vector2u window_size);
    ~Application() = default;

    bool Run();

 private:
    std::string name_{""};
    std::vector<std::thread> threads_{};

    sf::RenderWindow window_{};

    EventManager event_handler_{};
    Renderer renderer_{};

    ObjectHandler object_handler_{};

    void InitializeEventProcess();
};
}  // namespace engine

#endif  // SRC_APPLICATION_H_
