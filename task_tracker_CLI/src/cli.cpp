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

void CLI::deleteTask(int id)
{
    // Delete a task from the task list
    vector<Task> updatedTasks;
    vector<Task> tasks = parseJsonFile("tasks.json");
    for (int i = 1; i <= id;  i++) {
        if (i != id) {
            updatedTasks.push_back(tasks[i-1]);
        }
    }
    for (int i = id; i < (int)tasks.size();  i++) {
        tasks[i-1].id = i;
        updatedTasks.push_back(tasks[i-1]);
    }
    // Write the updated tasks to a temporary file
    for  (const auto& task : updatedTasks) {
        writeTaskToJson(task, "tasks.json.tmp");
    }
    // Replace the original file with the temporary file
    remove("tasks.json");
    rename("tasks.json.tmp", "tasks.json");
}
