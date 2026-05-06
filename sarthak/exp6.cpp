#include <iostream>
using namespace std;

#define SIZE 5

struct Client {
    long phone;
    string name;
};

class HashTable {
    Client LP[SIZE], QP[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            LP[i].phone = QP[i].phone = -1;
        }
    }

    int hash(long key) {
        return key % SIZE;
    }

    // -------- Linear Probing --------
    void insertLP(long phone, string name) {
        int i = hash(phone);

        for (int j = 0; j < SIZE; j++) {
            int idx = (i + j) % SIZE;
            if (LP[idx].phone == -1) {
                LP[idx] = {phone, name};
                return;
            }
        }
        cout << "Table Full!\n";
    }

    void searchLP(long phone) {
        int i = hash(phone), comp = 0;

        for (int j = 0; j < SIZE; j++) {
            int idx = (i + j) % SIZE;
            comp++;
            if (LP[idx].phone == phone) {
                cout << "Found in " << comp << " comparisons\n";
                return;
            }
        }
        cout << "Not found\n";
    }

    void displayLP() {
        cout << "\n-- Linear Probing --\n";
        for (int i = 0; i < SIZE; i++)
            cout << LP[i].phone << "  " << LP[i].name << endl;
    }

    // -------- Quadratic Probing --------
    void insertQP(long phone, string name) {
        int i = hash(phone);

        for (int j = 0; j < SIZE; j++) {
            int idx = (i + j * j) % SIZE;
            if (QP[idx].phone == -1) {
                QP[idx] = {phone, name};
                return;
            }
        }
        cout << "Table Full!\n";
    }

    void searchQP(long phone) {
        int i = hash(phone), comp = 0;

        for (int j = 0; j < SIZE; j++) {
            int idx = (i + j * j) % SIZE;
            comp++;
            if (QP[idx].phone == phone) {
                cout << "Found in " << comp << " comparisons\n";
                return;
            }
        }
        cout << "Not found\n";
    }

    void displayQP() {
        cout << "\n-- Quadratic Probing --\n";
        for (int i = 0; i < SIZE; i++)
            cout << QP[i].phone << "  " << QP[i].name << endl;
    }
};

int main() {
    HashTable h;
    int ch;
    long phone;
    string name;

    do {
        cout << "\n1.Insert\n2.Display\n3.Search\n4.Exit\nChoice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Phone: "; cin >> phone;
            cout << "Name: "; cin >> name;

            cout << "1.Linear  2.Quadratic: ";
            int p; cin >> p;

            if (p == 1) h.insertLP(phone, name);
            else h.insertQP(phone, name);
            break;

        case 2:
            h.displayLP();
            h.displayQP();
            break;

        case 3:
            cout << "Phone: "; cin >> phone;
            cout << "1.Linear  2.Quadratic: ";
            cin >> ch;

            if (ch == 1) h.searchLP(phone);
            else h.searchQP(phone);
            break;

        case 4:
            return 0;
        }
    } while (true);
}
