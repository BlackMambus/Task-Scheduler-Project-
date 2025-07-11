#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Task {
    int id;
    string name;
    string dueTime; // Format: "YYYY-MM-DD HH:MM"
};

class TaskScheduler {
private:
    vector<Task> tasks;
    int nextId = 1;

public:
    void addTask() {
        Task t;
        t.id = nextId++;
        cout << "Enter task name: ";
        cin.ignore();
        getline(cin, t.name);
        cout << "Enter due time (YYYY-MM-DD HH:MM): ";
        getline(cin, t.dueTime);
        tasks.push_back(t);
        cout << "Task added!\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks scheduled.\n";
            return;
        }

        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.dueTime < b.dueTime;
        });

        cout << "\n📋 Scheduled Tasks:\n";
        cout << left << setw(5) << "ID" << setw(25) << "Task Name" << "Due Time\n";
        for (const auto& t : tasks) {
            cout << left << setw(5) << t.id << setw(25) << t.name << t.dueTime << endl;
        }
    }

    void deleteTask() {
        int id;
        cout << "Enter task ID to delete: ";
        cin >> id;

        auto it = remove_if(tasks.begin(), tasks.end(), [id](const Task& t) {
            return t.id == id;
        });

        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            cout << "Task deleted.\n";
        } else {
            cout << "Task not found.\n";
        }
    }
};
int main() {
    TaskScheduler scheduler;
    int choice;

    while (true) {
        cout << "\n--- Task Scheduler ---\n";
        cout << "1. Add Task\n2. View Tasks\n3. Delete Task\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: scheduler.addTask(); break;
            case 2: scheduler.viewTasks(); break;
            case 3: scheduler.deleteTask(); break;
            case 4: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
