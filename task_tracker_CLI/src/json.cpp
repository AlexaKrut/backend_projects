#include "./include/json.h"

void saveTasksToJson(vector<Task>& tasks, const string& jsonFile) {
    Json::Value json;
    for  (const auto& task : tasks) {
        Json::Value taskJson;
        taskJson["id"] = task.id;
        taskJson["description"] = task.description;
        taskJson["status"] = task.status;
        taskJson["createdAt"] = task.createdAt;
        taskJson["updatedAt"] = task.updatedAt;
        json["tasks"].append(taskJson);
    }
    Json::StyledWriter writer;
    std::ofstream file(jsonFile);
    file << writer.write(json);
    file.close();
}