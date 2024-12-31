#include <iostream>
#include <vector>
#include <string>
#define clrscr() system("cls");
using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "\nMain Menu To-Do List" << endl;
    cout << "1. Add a Task" << endl;
    cout << "2. View All Tasks" << endl;
    cout << "3. Remove a Task" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to display all tasks
void displayTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "\nYour To-Do List is empty." << endl;
    } else {
        cout << "\nYour Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}

int main() {
    vector<string> tasks; // To-Do List storage
    int choice;

    do {
        displayTasks(tasks);
        displayMenu();
        cin >>choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            clrscr();
            cin.clear(); // Clear the errors flag in the input stream
            cin.ignore(10000, '\n');/*will ignore the invalid input upto 10000 characters with delimiter '\n' */
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                clrscr();
                cin.ignore(); // Clear input buffer
                string newTask;
                cout << "Enter the new task: ";
                getline(cin, newTask);
                tasks.push_back(newTask);
                cout << "Task added successfully!" << endl;
                break;
            }
            case 2: {
                clrscr();
                // displayTasks(tasks);
                break;
            }
            case 3: {
                clrscr();
                displayTasks(tasks);
                if (tasks.empty()) {
                    cout << "Your To-Do List is empty." << endl;
                } else {
                    size_t taskNumber;
                    cout << "Enter the task number to remove: ";
                    cin >> taskNumber;

                    if (cin.fail() || taskNumber < 1 || taskNumber > tasks.size()) {
                        cin.clear();
                        cin.ignore(10000, '\n');/*will ignore the invalid input upto 10000 characters with delimiter '\n' */
                        cout << "Invalid task number. Please try again." << endl;
                    } else {
                        tasks.erase(tasks.begin() + taskNumber - 1);
                        cout << "Task removed successfully!" << endl;
                    }
                }
                break;
            }
            case 4:
                clrscr();
                cout << "Exiting the program. Goodbye!" << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
