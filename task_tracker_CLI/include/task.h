// Заголовочный файл, содержащий определение структуры Task.

#ifndef TASK_H
#define  TASK_H

#include <string>
#include <ctime>

using namespace std;

struct Task {
    int id;
    string description;
    string status;
    string createdAt;
    string updatedAt;
};

#endif  // TASK_H

