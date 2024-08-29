Task Tracker CLI is a simple command-line interface (CLI) application that allows you to track and manage your tasks. You can add, update, and delete tasks, mark them as in progress or done, and list all tasks or tasks by status. Usage Adding a new task task-cli add "Task description"

Example: task-cli add "Buy groceries"

Updating a task task-cli update <task_id> "New task description"

Example: task-cli update 1 "Buy groceries and cook dinner"

Deleting a task task-cli delete <task_id>

Example: task-cli delete 1

Marking a task as in progress or done task-cli mark-in-progress <task_id> task-cli mark-done <task_id>

Example: task-cli mark-in-progress 1 task-cli mark-done 1

Listing all tasks task-cli list

Listing tasks by status task-cli list

Example: task-cli list done task-cli list todo task-cli list in-progress
