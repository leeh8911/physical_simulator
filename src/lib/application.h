/// @file application.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-30
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_LIB_APPLICATION_H_
#define SRC_LIB_APPLICATION_H_

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "src/lib/event_handler.h"
#include "src/lib/mouse_state.h"
#include "src/lib/solver.h"
#include "src/lib/task_manager.h"
#include "src/lib/user_interface.h"
#include "src/lib/world.h"

namespace physics::application
{

class Application : public std::enable_shared_from_this<Application>
{
 public:
    Application() = default;
    ~Application() = default;

    void initialize();
    void run();

 private:
    void update();
    void render();
    void handleEvent();
    void clear();

    void createTasks();
    UserInterfacePtr createControlBox();

    void initializeEventHandler();
    void initializeEventCallbacks();

    void initializeSections();

    std::vector<UserInterfacePtr> mSections{};
    World mWorld{};
    Solver mSolver{};
    TaskManager mTaskManager{};

    EventHandlerPtr mEventHandler{};
    std::shared_ptr<sf::RenderWindow> mWindow{nullptr};
    MouseStatePtr mMouseState{nullptr};
};

}  // namespace physics::application
#endif  // SRC_LIB_APPLICATION_H_
