#ifndef CLI_H
#define CLI_H

#include <string>
#include <vector>
#include  <iostream>
#include "task.h"
#include "utils.h"
#include "json.h"

using namespace std;

class CLI {
public:
    void addTask(const string& description);
    void listTasks();
    void deleteTask(int id);
    void updateTask(int id, string& description);
    void markInProgress(int id);
    void markDone(int id);
    void listTaskByStatus(const string &status);
private:  
    vector<Task> tasks;
    string jsonFile;
};

#endif  // CLI_H
