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

void CLI::listDoneTasks(const string &status)
{
    cout << "List of Done Tasks: " << endl;
    vector<Task> tasks = parseJsonFile("tasks.json");
    for (const auto& task : tasks) {
        if (task.status == status) {
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

void CLI::listTodoTask(const string &status)
{
    cout << "List Tasks Todo: " << endl;
    vector<Task> tasks = parseJsonFile("tasks.json");
    for (const auto& task : tasks) {
        if (task.status == status) {
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

void CLI::listTaskInProgres(const string &status)
{
    cout << "List Tasks In Progres: " << endl;
    vector<Task> tasks = parseJsonFile("tasks.json");
    for (const auto& task : tasks) {
        if (task.status == status) {
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
