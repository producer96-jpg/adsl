#include <iostream>
using namespace std;

#define MAX 5

struct client {
    long long phone;
    string name;
};

class LinearHash {
private:
    client table[MAX];

public:
    LinearHash() {
        for (int i = 0; i < MAX; i++)
            table[i].phone = -1;
    }

    client getdata() {
        client c;
        cout << "Enter phone number: ";
        cin >> c.phone;
        cout << "Enter name: ";
        cin >> c.name;
        return c;
    }

    void insert() {
        client c = getdata();
        int index = c.phone % MAX;

        for (int i = 0; i < MAX; i++) {
            int pos = (index + i) % MAX;

            if (table[pos].phone == -1) {
                table[pos] = c;
                cout << "Inserted (Linear)\n";
                return;
            }
        }
        cout << "Hash table full\n";
    }

    void search(long long key) {
        int index = key % MAX;
        int count = 0;

        for (int i = 0; i < MAX; i++) {
            count++;
            int pos = (index + i) % MAX;

            if (table[pos].phone == key) {
                cout << "Found: " << table[pos].name;
                cout << " | Comparisons: " << count << endl;
                return;
            }

            if (table[pos].phone == -1)
                break;
        }
        cout << "Not Found | Comparisons: " << count << endl;
    }

    void display() {
        cout << "\n--- Linear Hash Table ---\n";
        for (int i = 0; i < MAX; i++)
            cout << i << " -> " << table[i].phone << " " << table[i].name << endl;
    }
};

int main() {
    LinearHash h;
    int choice;
    long long key;

    while (true) {
        cout << "\n1.Insert  2.Display  3.Search  4.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: h.insert(); break;
            case 2: h.display(); break;
            case 3:
                cout << "Enter phone: ";
                cin >> key;
                h.search(key);
                break;
            case 4: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
