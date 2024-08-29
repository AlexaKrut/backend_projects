#include <iostream>
#include <string>
#include <vector>
#include "../include/cli.h"

using namespace std;

struct CommandLineArgs {
    string command;
    vector<string> args;
};

CommandLineArgs parseCommandLineArgs(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    CommandLineArgs args  = parseCommandLineArgs(argc, argv);
    if (args.command.empty()) {
        cout << "Error: No command specified." << endl;
    } else {
        CLI TaskManager;
        if (args.command == "add") {TaskManager.addTask(args.args[0]);}
        else if (args.command == "list" && args.args.empty()){TaskManager.listTasks();}
        else if (args.command == "delete"){TaskManager.deleteTask(stoi(args.args[0]));} 
        else if (args.command == "update"){TaskManager.updateTask(stoi(args.args[0]), args.args[1]);}
        else if (args.command == "mark-in-progress"){TaskManager.markInProgress(stoi(args.args[0]));}
        else if (args.command == "mark-done"){TaskManager.markDone(stoi(args.args[0]));}
        else if ((args.command == "list") && ((args.args[0]) == "done")){TaskManager.listDoneTasks(args.args[0]);}
        else if ((args.command == "list") && ((args.args[0]) == "todo")){TaskManager.listTodoTask(args.args[0]);}
        else if ((args.command == "list") && ((args.args[0]) == "in-progres")){TaskManager.listTaskInProgres(args.args[0]);}
        else {cout << "Error: Not find this command. You need to choose one of existing commands." << endl;}
    }
}

CommandLineArgs parseCommandLineArgs(int argc, char* argv[]) {
    CommandLineArgs args;
    if (argc > 1) {
        args.command = argv[1];
        for (int i = 2; i < argc; i++) {
            args.args.push_back(argv[i]);
        }
    }
    return args;
}