/// @file main.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-10
///
/// @copyright Copyright (c) 2023
///
///

#include <iostream>

#include "src/application.h"

int main(int argc, char** argv)
{
    constexpr size_t kWindowWidth = 1024;
    constexpr size_t kWindowHeight = 768;

    for (int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << std::endl;
    }

    engine::Application app("engine",
                            sf::Vector2u{kWindowWidth, kWindowHeight});

    return app.Run();
}