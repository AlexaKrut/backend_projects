// Заголовочный файл, содержащий определение функций для работы с JSON-файлом

#ifndef JSON_H
#define JSON_H

#include "cli.h"

void saveTasksToJson(vector<Task>& tasks, const string& jsonFile);

#endif  // JSON_H
