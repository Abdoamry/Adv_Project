#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task
{
    int id;
    string description;
    bool completed;

    Task(int id, string description, bool completed)
    {
        this->id = id;
        this->description = description;
        this->completed = completed;
    }
};

vector<Task> tasks;

void addTask(int id, string description, bool completed)
{
    tasks.push_back(Task(id, description, completed));
}

void showTasks()
{
    if (tasks.empty())
    {
        cout << "No tasks available." << endl;
        return;
    }

    for (const auto& task : tasks)
    {
        cout << "Task ID: " << task.id 
             << ", Description: " << task.description 
             << ", Completed: " << (task.completed ? "Yes" : "No") 
             << endl;
    }
}

void deleteTask(int taskId)
{
    for (size_t i = 0; i < tasks.size(); i++)
    {
        if (tasks[i].id == taskId)
        {
            tasks.erase(tasks.begin() + i);
            cout << "Task with ID " << taskId << " has been deleted." << endl;
            return;
        }
    }

    cout << "Task with ID " << taskId << " not found." << endl;
}

void markTaskCompleted(int taskId)
{
    for (auto& task : tasks)
    {
        if (task.id == taskId)
        {
            task.completed = true;
            cout << "Task with ID " << taskId << " has been marked as completed." << endl;
            return;
        }
    }
    cout << "Task with ID " << taskId << " not found." << endl;
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n=== To-Do List Menu ===" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Show Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Mark Task as Completed" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id;
            string description;
            cout << "Enter Task ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Task Description: ";
            getline(cin, description);
            addTask(id, description, false);
            cout << "Task added successfully!" << endl;
        }
        else if (choice == 2)
        {
            showTasks();
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Task ID to delete: ";
            cin >> id;
            deleteTask(id);
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter Task ID to mark as completed: ";
            cin >> id;
            markTaskCompleted(id);
        }
        else if (choice == 5)
        {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
