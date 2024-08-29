# Task Tracker

Sample solution for the [task-tracker](https://roadmap.sh/projects/task-tracker) challenge from [roadmap.sh](https://roadmap.sh/).

## How to run

Clone the repository and run the following command:

```bash
git clone git@github.com:AlexaKrut/backend_projects.git
cd backend-projects/task_tracker_CLI
```

Run the following command to build the project:

```bash
make

# To add a task
cli add "Buy groceries"

# To update a task
cli update 1 "Buy groceries and cook dinner"

# To delete a task
cli delete 1

# To mark a task as in progress/done/todo
cli mark-in-progress 1
./task-tracker mark-done 1
./task-tracker mark-todo 1

# To list all tasks
cli list
cli list done
cli list todo
cli list in-progress
```
