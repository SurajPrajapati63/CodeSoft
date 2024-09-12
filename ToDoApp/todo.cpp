#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct todolist {
    int id;
    string task;
};

int ID = 0;

void banner() {
    cout << "--------------------------------------" << endl;
    cout << "\t       MY TODO" << endl;
    cout << "--------------------------------------" << endl;
}

void addtask() {
    system("cls");
    banner();
    todolist todo;
    cout << "Enter new task: " << endl;
    cin.get();
    getline(cin, todo.task);
    char save;
    cout << "  Save? (y/n): " << endl;
    cin >> save;
    if (save == 'y') {
        ID++;
        ofstream fout("todolist.txt", ios::app);
        fout << ID << endl << todo.task << endl;
        fout.close();
        char more;
        cout << "\t Add more Task? (y/n): " << endl;
        cin >> more;
        if (more == 'y') {
            addtask();
        } else {
            system("cls");
            cout << "Add task successful!" << endl;
        }
    }
}

void showtask() {
    system("cls");
    banner();
    cout << "\t Task:" << endl;
    todolist todo;
    ifstream fin("todolist.txt");
    while (fin >> todo.id) {
        fin.ignore();
        getline(fin, todo.task);
        cout << "\t" << todo.id << "\t" << todo.task << endl;
    }
    fin.close();
    char exit;
    cout << "Exit? (y/n): " << endl;
    cin >> exit;
    if (exit == 'y') return;
    system("cls");
}

int searchtask() {
    system("cls");
    banner();
    int id;
    cout << "Enter task id: ";
    cin >> id;
    todolist todo;
    ifstream fin("todolist.txt");
    while (fin >> todo.id) {
        fin.ignore();
        getline(fin, todo.task);
        if (todo.id == id) {
            system("cls");
            cout << "\t" << todo.id << "\t" << todo.task << endl;
            fin.close();
            return id;
        }
    }
    fin.close();
    cout << "\t Data Not Found" << endl;
    char exit;
    cout << "Exit? (y/n): " << endl;
    cin >> exit;
    if (exit == 'y') return 0;
    system("cls");
    return 0;
}

void deletetask() {
    system("cls");
    int id = searchtask();
    if (id != 0) {
        char del;
        cout << "\n\t Delete? (y/n): ";
        cin >> del;
        if (del == 'y') {
            todolist todo;
            ofstream tempfile("temp.txt");
            ifstream fin("todolist.txt");
            int index = 1;
            while (fin >> todo.id) {
                fin.ignore();
                getline(fin, todo.task);
                if (todo.id != id) {
                    tempfile << index << endl << todo.task << endl;
                    index++;
                }
            }
            fin.close();
            tempfile.close();
            remove("todolist.txt");
            rename("temp.txt", "todolist.txt");
            system("cls");
            cout << "Delete successful!" << endl;
        } else {
            system("cls");
            cout << "Not Deleted!" << endl;
        }
    }
}

void updatetask() {
    system("cls");
    banner();
    int id = searchtask();
    if (id != 0) {
        string new_task;
        cout << "Enter new task description: ";
        cin.ignore(); // To ignore any leftover newline character
        getline(cin, new_task);
        
        // Create a temporary file to store updated tasks
        ofstream tempfile("temp.txt");
        ifstream fin("todolist.txt");
        todolist todo;
        int index = 1;
        
        while (fin >> todo.id) {
            fin.ignore();
            getline(fin, todo.task);
            if (todo.id == id) {
                tempfile << index << endl << new_task << endl;
            } else {
                tempfile << index << endl << todo.task << endl;
            }
            index++;
        }
        
        fin.close();
        tempfile.close();
        
        remove("todolist.txt");
        rename("temp.txt", "todolist.txt");
        
        system("cls");
        cout << "Update successful!" << endl;
    }
}

int main() {
    int choice;
    do {
        system("cls");
        banner();
        cout << "Enter the task number: " << endl;
        cout << "\t 1. Add task" << endl;
        cout << "\t 2. Show tasks" << endl;
        cout << "\t 3. Search task" << endl;
        cout << "\t 4. Delete task" << endl;
        cout << "\t 5. Update task" << endl;
        cin >> choice;
        
        switch (choice) {
            case 1:
                addtask();
                break;
            case 2:
                showtask();
                break;
            case 3:
                searchtask();
                break;
            case 4:
                deletetask();
                break;
            case 5:
                updatetask();
                break;
            default:
                cout << "Invalid entry!" << endl;
                break;
        }
    } while (choice >= 1 && choice <= 5);

    return 0;
}
