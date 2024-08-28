#include <iostream>
#include <string>
#include "./include/cli.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc > 1) {
        CLI TaskManager;

    } else {
        cout << "You need to choose an option!!!" << endl;
        cout << "Format:  <./task_tracker_CLI option data>" << endl;
        cout << "Option variants:" << endl;
        cout << "1. Add - add a new task" << endl;
        cout << "2. Update - update task" << endl;
        cout << "3. Delete - delete task" << endl;
        cout << "4. Mark-in-progress - mark a task as in progress" << endl;
        cout << "5. Mark-done - mark a task as done" << endl;
        cout << "6. List - list all tasks" << endl;
        cout << "7. List-done - list all tasks that are done" << endl;
        cout << "8. List-undone - list all tasks that are not done" << endl;
        cout << "9. List-in-progress - list all tasks that are in progress" << endl;
    }
    return 0;
}