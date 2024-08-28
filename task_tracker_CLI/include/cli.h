// Заголовочный файл, содержащий определение класса CLI

#ifndef CLI_H
#define CLI_H

#include <string>
#include <vector>
#include "task.h"

using namespace std;

class CLI {
public:
    void addTask(const string& description);
    void updateTask(int id, const string& description);
    void deleteTask(int id);
    void markInProgress(int id);
    void markDone(int id);
    void listTasks();
    void listTasksByStatus(const string& status);
private:  
    vector<Task> tasks;
    string jsonFile;
};

#endif  // CLI_H
