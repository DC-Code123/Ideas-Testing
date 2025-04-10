#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
  string name;
  string state;
  bool finishedness;
};

// Function prototypes
void AddTask(vector<Task>& pendingTasks);
void ViewTask(const vector<Task>& pendingTasks);
void MarkDone(vector<Task>& pendingTasks, vector<Task>& doneTasks);
void ViewDone(const vector<Task>& doneTasks);
void DeleteTask(vector<Task>& pendingTasks, vector<Task>& doneTasks);

int main() {
  vector<Task> pendingTasks;
  vector<Task> doneTasks;
  char rerun;

  do {
    int choice;

    cout << "\nWelcome to Day-Tracker\n";
    cout << "We have a set of operations for you:\n";
    cout << "1. Add tasks\n";
    cout << "2. View tasks\n";
    cout << "3. Mark tasks as done\n";
    cout << "4. View marked tasks\n";
    cout << "5. View all tasks\n";
    cout << "6. Delete a task\n";
    cout << "7. Exit\n";
    cout << "Enter one of the options (1-7): ";
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 7) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Invalid input. Please enter an integer between 1 and 7.\n";
      continue;
    }

    switch (choice) {
      case 1:
        AddTask(pendingTasks);
        break;
      case 2:
        ViewTask(pendingTasks);
        break;
      case 3:
        MarkDone(pendingTasks, doneTasks);
        break;
      case 4:
        ViewDone(doneTasks);
        break;
      case 5:
        ViewTask(pendingTasks);
        ViewDone(doneTasks);
        break;
      case 6:
        DeleteTask(pendingTasks, doneTasks);
        break;
      case 7:
        cout << "Thanks for using the app.\nExiting program...\n";
        return 0;
    }

    cout << "\nDo you want to perform another operation? (y = yes, n = no): ";
    cin >> rerun;

  } while (rerun == 'y' || rerun == 'Y');

  return 0;
}

void AddTask(vector<Task>& pendingTasks) {
  Task newTask;
  cout << "Enter task name: ";
  cin.ignore();
  getline(cin, newTask.name);
  newTask.state = "Pending";
  newTask.finishedness = false;
  pendingTasks.push_back(newTask);
  cout << "Task added successfully.\n";
}

void ViewTask(const vector<Task>& pendingTasks) {
  if (pendingTasks.empty()) {
    cout << "No pending tasks.\n";
    return;
  }
  cout << "Pending Tasks:\n";
  for (size_t i = 0; i < pendingTasks.size(); ++i) {
    cout << i + 1 << ". " << pendingTasks[i].name << "\n";
  }
}

void MarkDone(vector<Task>& pendingTasks, vector<Task>& doneTasks) {
  int index;
  ViewTask(pendingTasks);
  cout << "Enter task number to mark as done: ";
  cin >> index;
  if (index > 0 && index <= pendingTasks.size()) {
    Task done = pendingTasks[index - 1];
    done.state = "Done";
    done.finishedness = true;
    doneTasks.push_back(done);
    pendingTasks.erase(pendingTasks.begin() + index - 1);
    cout << "Task marked as done.\n";
  } else {
    cout << "Invalid task number.\n";
  }
}

void ViewDone(const vector<Task>& doneTasks) {
  if (doneTasks.empty()) {
    cout << "No completed tasks.\n";
    return;
  }
  cout << "Completed Tasks:\n";
  for (size_t i = 0; i < doneTasks.size(); ++i) {
    cout << i + 1 << ". " << doneTasks[i].name << "\n";
  }
}

void DeleteTask(vector<Task>& pendingTasks, vector<Task>& doneTasks) {
  int type, index;
  cout << "Delete from: 1. Pending  2. Done\nChoose: ";
  cin >> type;

  if (type == 1) {
    ViewTask(pendingTasks);
    cout << "Enter task number to delete: ";
    cin >> index;
    if (index > 0 && index <= pendingTasks.size()) {
      pendingTasks.erase(pendingTasks.begin() + index - 1);
      cout << "Task deleted from pending list.\n";
    } else {
      cout << "Invalid index.\n";
    }
  } else if (type == 2) {
    ViewDone(doneTasks);
    cout << "Enter task number to delete: ";
    cin >> index;
    if (index > 0 && index <= doneTasks.size()) {
      doneTasks.erase(doneTasks.begin() + index - 1);
      cout << "Task deleted from done list.\n";
    } else {
      cout << "Invalid index.\n";
    }
  } else {
    cout << "Invalid option.\n";
  }
}
