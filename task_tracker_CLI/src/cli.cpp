#include "../include/cli.h"

void CLI::addTask(const string& description) {
    // Add a new task to the task list
    Task newTask;
    newTask.id = getLastId("tasks.json") + 1;
    newTask.description = description;
    newTask.status = "todo";
    newTask.createdAt = getCurrentTime();
    newTask.updatedAt = getCurrentTime();

    writeTaskToJson(newTask, "tasks.json");
}

void CLI::listTasks()
{
    cout << "List of Tasks: " << endl;
    vector<Task> tasks = parseJsonFile("tasks.json");
    for (const auto& task : tasks) {
        if (!task.description.empty()) {
            cout << task.description << endl;
        } else {
            cout << "Task has no description" << endl;
        }
    }
}
