/// @file task_manager.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-31
///
/// @copyright Copyright (c) 2023
///
///

#ifndef SRC_LIB_TASK_MANAGER_H_
#define SRC_LIB_TASK_MANAGER_H_

#include <functional>
#include <memory>
#include <thread>
#include <vector>

namespace physics
{

class TaskManager
{
 public:
    TaskManager() = default;
    ~TaskManager() = default;

    void createTask(std::function<void()> task);
    void run();

 private:
    std::vector<std::thread> mTasks{};
};
}  // namespace physics
#endif  // SRC_LIB_TASK_MANAGER_H_
