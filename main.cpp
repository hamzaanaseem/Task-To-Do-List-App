
#include <iostream>
#include <string>
using namespace std;

struct Task {
    string name;
    bool done;
    Task* next;
};


Task* head = NULL;

void addTask( ) {
    Task* t = new Task;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin,   t->name);


    t->done = false;
    t->next = NULL;

    if (head == NULL) {
        head = t;
    } else {
        Task* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = t;
    }

    cout << "Task added.\n";
}

void showTasks() {
    if (head == NULL) {
        cout << "No tasks found.\n";
        return;
    }

    Task* p = head;
    int i = 1;

    cout << "\nTask List:\n";
    while (p != NULL) {
        cout << i << ". " << p->name;
        if (p->done)
            cout << " (Completed)";
        cout << endl;
        p = p->next;
        i++;
    }
}



void markDone() {
    if (head == NULL) {
        cout << "No tasks to mark.\n";
        return;
    }

    showTasks();

    int num;
    cout << "Enter task number to mark completed: ";
    cin >> num;

    Task* p = head;
    int i = 1;

    while (p != NULL && i < num) {
        p = p->next;
        i++;
    }

    if (p == NULL) {
        cout << "Invalid task number.\n";
    } else {
        p->done = true;
        cout << "Task marked as completed.\n";
    }
}

void deleteTask() {
    if (head == NULL) {
        cout << "No tasks to delete.\n";
        return;
    }

    showTasks();

    int num;
    cout << "Enter task number to delete: ";
    cin >> num;

    if (num == 1) {
        Task* temp = head;
        head = head->next;
        delete temp;
        cout << "Task deleted.\n";
        return;
    }

    Task* p =   head;
    for (int i = 1; i < num - 1 && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL || p->next == NULL) {
        cout << "Invalid task number.\n";
    } else {
        Task* temp = p->next;
        p->next = temp->next;
        delete temp;
        cout << "Task deleted.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Task To-Do List ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
            addTask();
          
        else if (choice == 2)
            showTasks();
          
        else if (choice == 3)
            markDone();
          
        else if (choice == 4)
            deleteTask();
          
        else if (choice == 5)
            cout << "Program ended.\n";
        else
            cout << "Wrong option.\n";

    } while (choice != 5);

    return 0;
}  
