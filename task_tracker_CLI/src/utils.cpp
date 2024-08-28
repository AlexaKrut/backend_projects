#include "../include/utils.h"

string getCurrentTime() {
    auto now = chrono::system_clock::now();
    time_t nowTimeT = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&nowTimeT);

    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%d %H:%M:%S");
    string currentTime = oss.str();
    return currentTime;
}

int getLastId(const string& filename) {
    int maxId = 0;
    vector<Task> tasks = parseJsonFile(filename);
    for (const auto& task : tasks) {
        if (task.id > maxId) {
            maxId = task.id;
        } 
    }
    return maxId;

}