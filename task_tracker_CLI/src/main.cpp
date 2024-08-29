#include <iostream>
#include <string>
#include <vector>
#include "../include/cli.h"

using namespace std;

//Represents command line arguments.
struct CommandLineArgs {
    string command;
    vector<string> args;
};

CommandLineArgs parseCommandLineArgs(int argc, char* argv[]);

/**
 * The main entry point of the program.
 * 
 * @param argc The number of command line arguments.
 * @param argv The array of command line arguments.
 * 
 * Example:
 * ```
 * $ ./task_manager add "New Task"
 * $ ./task_manager list
 * $ ./task_manager delete 1
 * $ ./task_manager update 1 "Updated Task"
 * $ ./task_manager mark-in-progress 1
 * $ ./task_manager mark-done 1
 * $ ./task_manager list in-progress
 * ```
 */
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
        else if (args.command == "list" && !args.args.empty()){TaskManager.listTaskByStatus(args.args[0]);}
        else {cout << "Error: Not find this command. You need to choose one of existing commands." << endl;}
    }
}

//Parses command line arguments.
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