/// @file main.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-30
///
/// @copyright Copyright (c) 2023
///
///

#include <iostream>
#include <memory>
#include <string>
#include <utility>

#include "src/lib/application.h"

int main(int /* argc */, char** /* argv */)
{
    std::cout << "Hello World!" << std::endl;

    using namespace physics::application;

    auto app = std::make_shared<Application>();

    app->initialize();
    app->run();

    return 0;
}