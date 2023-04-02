/// @file task_manager.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2023-03-31
///
/// @copyright Copyright (c) 2023
///
///

#include "src/lib/task_manager.h"

namespace physics
{
void TaskManager::createTask(std::function<void()> task)
{
    mTasks.emplace_back(task);
}

void TaskManager::run()
{
    for (auto& task : mTasks)
    {
        task.join();
    }
}
}  // namespace physics