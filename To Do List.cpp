#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};

void addTask(std::vector<Task>& tasks, const std::string& description) {
    Task task;
    task.description = description;
    task.completed = false;
    tasks.push_back(task);
    std::cout << "Task added: " << description << std::endl;
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list." << std::endl;
        return;
    }

    std::cout << "Tasks in the list:" << std::endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        std::cout << i + 1 << ". ";
        if (tasks[i].completed) {
            std::cout << "[X] ";
        } else {
            std::cout << "[ ] ";
        }
        std::cout << tasks[i].description << std::endl;
    }
}

void markCompleted(std::vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
        tasks[taskIndex - 1].completed = true;
        std::cout << "Task marked as completed." << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

void removeTask(std::vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex - 1);
        std::cout << "Task removed from the list." << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;
    std::string description; 

    while (true) {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 5) {
            break;
        }

        switch (choice) {
            case 1:
                std::cin.ignore(); 
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                addTask(tasks, description);
                break;

            case 2:
                viewTasks(tasks);
                break;

            case 3:
                std::cout << "Enter the task number to mark as completed: ";
                int taskIndex;
                std::cin >> taskIndex;
                markCompleted(tasks, taskIndex);
                break;

            case 4:
                std::cout << "Enter the task number to remove: ";
                int taskIndexToRemove;
                std::cin >> taskIndexToRemove;
                removeTask(tasks, taskIndexToRemove);
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}

