#include <iostream>
#include <vector>

struct Task {
    int id;
    std::string name;
};

class TaskManager {
private:
    std::vector<Task> tasks;
    int taskCount = 0;

public:
    void addTask() {
        std::string taskName;
        std::cout << "Enter task name: ";
        std::cin.ignore();
        std::getline(std::cin, taskName);

        taskCount++;
        tasks.push_back({taskCount, taskName});

        std::cout << "Task added successfully! Task ID: " << taskCount << "\n";
    }

    void displayTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks to display.\n";
            return;
        }

        std::cout << "Current Tasks:\n";
        for (const auto& task : tasks) {
            std::cout << "ID: " << task.id << ", Name: " << task.name << "\n";
        }
    }

    void removeTask() {
        int id;
        std::cout << "Enter the ID of the task to remove: ";
        std::cin >> id;

        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->id == id) {
                tasks.erase(it);
                std::cout << "Task with ID " << id << " removed successfully.\n";
                return;
            }
        }

        std::cout << "Task with ID " << id << " not found.\n";
    }
};

int main() {
    TaskManager taskManager;
    int choice;

    do {
        std::cout << "\nTask Manager Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Display Tasks\n";
        std::cout << "3. Remove Task\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                taskManager.addTask();
                break;
            case 2:
                taskManager.displayTasks();
                break;
            case 3:
                taskManager.removeTask();
                break;
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
