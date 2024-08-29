#include "../include/cli.h"

void CLI::addTask(const string& description) {
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
            cout << task.id <<  ". " << task.description << endl;
            cout << "Task status: " << task.status << endl;
            cout << "Task createdAt: " << task.createdAt << endl;
            cout << "Task updatedAt: " << task.updatedAt << endl;
            cout << endl;
        } else {
            cout << "Task has no description" << endl;
        }
    }
}

void CLI::deleteTask(int id)
{
    vector<Task> updatedTasks;
    vector<Task> tasks = parseJsonFile("tasks.json");
    for (int i = 1; i < id;  i++) {
        if (i != id) {
            updatedTasks.push_back(tasks[i-1]);
        }
    }
    for (int i = id + 1; i <= (int)tasks.size();  i++) {
        tasks[i - 1].id = i - 1;
        updatedTasks.push_back(tasks[i-1]);
    }

    for  (const auto& task : updatedTasks) {
        writeTaskToJson(task, "tasks.json.tmp");
    }

    remove("tasks.json");
    rename("tasks.json.tmp", "tasks.json");
}

void CLI::updateTask(int id, string &description)
{
    vector<Task> updatedTasks;
    vector<Task> tasks = parseJsonFile("tasks.json");
    for (auto & task : tasks) {
        if(task.id == id) {
            task.description = description;
            task.updatedAt =  getCurrentTime();
            updatedTasks.push_back(task);
        } else {
            updatedTasks.push_back(task);
        }
    }
    for  (const auto& task : updatedTasks) {
        writeTaskToJson(task, "tasks.json.tmp");
    }
    remove("tasks.json");
    rename("tasks.json.tmp", "tasks.json");

}

void CLI::markInProgress(int id)
{
    vector<Task> updatedTasks;
    vector<Task> tasks = parseJsonFile("tasks.json");
    for (auto & task : tasks) {
        if(task.id == id) {
            task.status = "in-progress";
            task.updatedAt =  getCurrentTime();
            updatedTasks.push_back(task);
        } else {
            updatedTasks.push_back(task);
        }
    }
    for  (const auto& task : updatedTasks) {
        writeTaskToJson(task, "tasks.json.tmp");
    }
    remove("tasks.json");
    rename("tasks.json.tmp", "tasks.json");
}

void CLI::markDone(int id)
{
    vector<Task> updatedTasks;
    vector<Task> tasks = parseJsonFile("tasks.json");
    for (auto & task : tasks) {
        if(task.id == id) {
            task.status = "done";
            task.updatedAt =  getCurrentTime();
            updatedTasks.push_back(task);
        } else {
            updatedTasks.push_back(task);
        }
    }
    for  (const auto& task : updatedTasks) {
        writeTaskToJson(task, "tasks.json.tmp");
    }
    remove("tasks.json");
    rename("tasks.json.tmp", "tasks.json");
}

void CLI::listTaskByStatus(const string &status)
{
    cout << "List Of Tasks " << status << ":" << endl;
    vector<Task> tasks = parseJsonFile("tasks.json");
    for (const auto& task : tasks) {
        if (task.status == status) {
            cout << task.id <<  ". " << task.description << endl;
            cout << "Task status: " << task.status << endl;
            cout << "Task createdAt: " << task.createdAt << endl;
            cout << "Task updatedAt: " << task.updatedAt << endl;
            cout << endl;
        }
    }
}
