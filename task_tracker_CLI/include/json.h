// Заголовочный файл, содержащий определение функций для работы с JSON-файлом

#ifndef JSON_H
#define JSON_H

#include "fstream"
#include "cli.h"

using namespace std;

void writeTaskToJson(struct Task task, const char* filename);
vector<Task> parseJsonFile(const std::string& filename);

#endif  // JSON_H
