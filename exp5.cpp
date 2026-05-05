#include <iostream>
#include <fstream>
using namespace std;

// Employee structure
struct Employee {
    int id;
    string name;
    string designation;
    float salary;
};

// Add Employee
void addEmployee() {
    Employee e;
    ofstream file("employee.txt", ios::app);

    cout << "\nEnter ID: ";
    cin >> e.id;
    cout << "Enter Name: ";
    cin >> e.name;
    cout << "Enter Designation: ";
    cin >> e.designation;
    cout << "Enter Salary: ";
    cin >> e.salary;

    file << e.id << " " << e.name << " "
         << e.designation << " " << e.salary << endl;

    file.close();
    cout << "Employee added successfully!\n";
}

// Display All Employees
void displayAll() {
    Employee e;
    ifstream file("employee.txt");

    cout << "\n--- Employee Records ---\n";

    while (file >> e.id >> e.name >> e.designation >> e.salary) {
        cout << "\nID: " << e.id
             << "\nName: " << e.name
             << "\nDesignation: " << e.designation
             << "\nSalary: " << e.salary << endl;
    }

    file.close();
}

// Search Employee
void searchEmployee() {
    Employee e;
    int id, found = 0;

    cout << "Enter ID to search: ";
    cin >> id;

    ifstream file("employee.txt");

    while (file >> e.id >> e.name >> e.designation >> e.salary) {
        if (e.id == id) {
            cout << "\nEmployee Found:\n";
            cout << "ID: " << e.id
                 << "\nName: " << e.name
                 << "\nDesignation: " << e.designation
                 << "\nSalary: " << e.salary << endl;
            found = 1;
            break;
        }
    }

    if (!found)
        cout << "Employee does not exist!\n";

    file.close();
}

// Update Employee
void updateEmployee() {
    Employee e;
    int id, found = 0;

    ifstream file("employee.txt");
    ofstream temp("temp.txt");

    cout << "Enter ID to update: ";
    cin >> id;

    while (file >> e.id >> e.name >> e.designation >> e.salary) {
        if (e.id == id) {
            cout << "Enter new details:\n";
            cout << "Name: ";
            cin >> e.name;
            cout << "Designation: ";
            cin >> e.designation;
            cout << "Salary: ";
            cin >> e.salary;
            found = 1;
        }

        temp << e.id << " " << e.name << " "
             << e.designation << " " << e.salary << endl;
    }

    file.close();
    temp.close();

    remove("employee.txt");
    rename("temp.txt", "employee.txt");

    if (found)
        cout << "Record updated!\n";
    else
        cout << "Employee not found!\n";
}

// Delete Employee
void deleteEmployee() {
    Employee e;
    int id, found = 0;

    ifstream file("employee.txt");
    ofstream temp("temp.txt");

    cout << "Enter ID to delete: ";
    cin >> id;

    while (file >> e.id >> e.name >> e.designation >> e.salary) {
        if (e.id != id) {
            temp << e.id << " " << e.name << " "
                 << e.designation << " " << e.salary << endl;
        } else {
            found = 1;
        }
    }

    file.close();
    temp.close();

    remove("employee.txt");
    rename("temp.txt", "employee.txt");

    if (found)
        cout << "Record deleted!\n";
    else
        cout << "Employee not found!\n";
}

// Main Menu
int main() {
    int choice;

    do {
        cout << "\n===== Employee Sequential File System =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All\n";
        cout << "3. Search Employee\n";
        cout << "4. Update Employee\n";
        cout << "5. Delete Employee\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayAll(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
