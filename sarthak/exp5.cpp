#include <iostream>
#include <fstream>
using namespace std;

// Employee structure
struct Employee {
    int id;
    char name[20];
    char desig[20];
    float salary;
};

// Insert record
void insert() {
    Employee e;
    ofstream file("emp.txt", ios::binary | ios::app);

    cout << "Enter ID: ";
    cin >> e.id;
    cout << "Enter Name: ";
    cin >> e.name;
    cout << "Enter Designation: ";
    cin >> e.desig;
    cout << "Enter Salary: ";
    cin >> e.salary;

    file.write((char*)&e, sizeof(e));
    file.close();
}

// Display all records
void display() {
    Employee e;
    ifstream file("emp.txt", ios::binary);

    while (file.read((char*)&e, sizeof(e))) {
        cout << e.id << "  " << e.name << "  " << e.desig << "  " << e.salary << endl;
    }
    file.close();
}

// Search record
void search() {
    Employee e;
    char name[20];
    bool found = false;

    cout << "Enter name to search: ";
    cin >> name;

    ifstream file("emp.txt", ios::binary);

    while (file.read((char*)&e, sizeof(e))) {
        if (strcmp(e.name, name) == 0) {
            cout << "Found: " << e.id << " " << e.name << " " << e.desig << " " << e.salary << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << "Not Found\n";
    file.close();
}

// Delete record
void deleteRec() {
    Employee e;
    char name[20];

    cout << "Enter name to delete: ";
    cin >> name;

    ifstream in("emp.txt", ios::binary);
    ofstream out("temp.txt", ios::binary);

    while (in.read((char*)&e, sizeof(e))) {
        if (strcmp(e.name, name) != 0) {
            out.write((char*)&e, sizeof(e));
        }
    }

    in.close();
    out.close();

    remove("emp.txt");
    rename("temp.txt", "emp.txt");
}

// Update record
void update() {
    Employee e;
    char name[20];

    cout << "Enter name to update: ";
    cin >> name;

    fstream file("emp.txt", ios::in | ios::out | ios::binary);

    while (file.read((char*)&e, sizeof(e))) {
        if (strcmp(e.name, name) == 0) {
            cout << "Enter new details:\n";
            cin >> e.id >> e.name >> e.desig >> e.salary;

            file.seekp(-sizeof(e), ios::cur);
            file.write((char*)&e, sizeof(e));
            cout << "Updated\n";
            return;
        }
    }

    cout << "Not Found\n";
    file.close();
}

// MAIN
int main() {
    int ch;

    do {
        cout << "\n1.Insert\n2.Display\n3.Search\n4.Update\n5.Delete\n6.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: deleteRec(); break;
        }

    } while (ch != 6);

    return 0;
}
