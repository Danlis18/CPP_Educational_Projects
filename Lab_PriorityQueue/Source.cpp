#include <iostream>
#include <string>
#include <vector>
#include <windows.h> // for Sleep, system("cls")
using namespace std;

void clearScreen() {
    system("cls");
}

void line(int n = 50) {
    for (int i = 0; i < n; ++i) cout << '-';
    cout << "\n";
}

int priorityFromYears(int y) {
    if (y < 1) 
        return 6;
    else if (y < 3) 
        return 5;
    else if (y < 5) 
        return 4;
    else if (y < 7)
        return 3;
    else if (y < 10)
        return 2;
    else
        return 1;
}


class Client {
    int id;
    string name;
    int years;
    int priority;

public:
    Client(int _id = 0, string _name = "", int _years = 0) : id(_id), name(_name), years(_years), priority(priorityFromYears(_years)) {
    }

    int getPriority() const { 
        return priority; 
    }

    friend ostream& operator<<(ostream& os, const Client& c) {
        os << "ID: " << c.id
            << " | Name: " << c.name
            << " | Years: " << c.years
            << " | Priority: " << c.priority;
        return os;
    }
};


class PriorityQueue {
    vector<Client> arr;

public:
    void push(const Client& c) {
        int pr = c.getPriority();
        int i = 0;
        while (i < arr.size() && arr[i].getPriority() <= pr) i++;
        arr.insert(arr.begin() + i, c);
    }

    bool empty() const { 
        return arr.empty();
    }

    Client pop() {
        Client temp = arr.front();
        arr.erase(arr.begin());
        return temp;
    }

    void clear() {
        arr.clear();
    }

    friend ostream& operator<<(ostream& os, const PriorityQueue& pq) {
        if (pq.arr.empty()) {
            os << "Queue is empty.\n";
        }
        else {
            for (int i = 0; i < pq.arr.size(); i++) {
                os << (i + 1) << ") " << pq.arr[i] << "\n";
            }
        }
        return os;
    }
};


void showMenu() {
    cout << "===== BANK PRIORITY QUEUE SYSTEM =====\n";
    cout << "1) Add client\n";
    cout << "2) Serve next client\n";
    cout << "3) Show queue\n";
    cout << "4) Add sample clients\n";
    cout << "5) Clear queue\n";
    cout << "0) Exit\n";
    line();
    cout << "Enter your choice: ";
}



int main() {
    PriorityQueue q;
    bool running = true;

    while (running) {
        clearScreen();
        showMenu();

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            int id, years;
            string name;
            clearScreen();
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter years in bank: ";
            cin >> years;
            q.push(Client(id, name, years));
            cout << "Client added!\n";
            Sleep(1000);
            break;
        }
        case 2: {
            clearScreen();
            if (q.empty()) {
                cout << "Queue is empty!\n";
            }
            else {
                Client served = q.pop();
                cout << "Serving client:\n" << served << "\n";
            }
            Sleep(1500);
            break;
        }
        case 3: {
            clearScreen();
            cout << "Current Queue:\n";
            cout << q;
            Sleep(2000);
            break;
        }
        case 4: {
            q.push(Client(1, "John", 5));
            q.push(Client(2, "Mary", 1));
            q.push(Client(3, "Alex", 10));
            q.push(Client(4, "Kate", 3));
            cout << "Sample clients added.\n";
            Sleep(1000);
            break;
        }
        case 5: {
            q.clear();
            cout << "Queue cleared!\n";
            Sleep(1000);
            break;
        }
        case 0:
            running = false;
            break;
        default:
            cout << "Invalid option.\n";
            Sleep(1000);
        }
    }

    clearScreen();
    cout << "Goodbye!\n";
    Sleep(1000);
    return 0;
}
