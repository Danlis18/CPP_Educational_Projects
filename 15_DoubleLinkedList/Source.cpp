#include <iostream>
using namespace std;

int menu() {
    cout << "\n\n0 - Exit\n";
    cout << "1 - Add Head\n";
    cout << "2 - Add Tail\n";
    cout << "3 - Delete Head\n";
    cout << "4 - Delete Tail\n";
    cout << "5 - Clear All\n";
    cout << "6 - Add element to position\n";
    cout << "7 - Delete element from position\n";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

struct element {
    int data = 0;
    element* next = nullptr;
    element* prev = nullptr;
};

class list {
    element* head, * tail;
    int size;

public:
    list() {
        head = tail = nullptr;
        size = 0;
    }

    ~list() {
        clear();
    }

    void add_head(int value) {
        element* new_element = new element;
        new_element->data = value;

        if (size == 0) {
            head = tail = new_element;
        }
        else {
            new_element->next = head;
            head->prev = new_element;
            head = new_element;
        }
        size++;
    }

    void add_tail(int value) {
        element* new_element = new element;
        new_element->data = value;

        if (size == 0) {
            head = tail = new_element;
        }
        else {
            tail->next = new_element;
            new_element->prev = tail;
            tail = new_element;
        }
        size++;
    }

    void delete_head() {
        if (size == 0) return;

        element* tmp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr; // якщо був лише один елемент
        delete tmp;
        size--;
    }

    void delete_tail() {
        if (size == 0) return;

        element* tmp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr; // якщо був лише один елемент
        delete tmp;
        size--;
    }

    void clear() {
        while (size > 0) {
            delete_head();
        }
    }

    void add_pos(int value, int pos) {
        if (pos <= 0) add_head(value);
        else if (pos >= size) add_tail(value);
        else {
            element* new_element = new element;
            new_element->data = value;

            element* tmp = head;
            for (int i = 0; i < pos - 1; i++)
                tmp = tmp->next;

            new_element->next = tmp->next;
            new_element->prev = tmp;
            tmp->next->prev = new_element;
            tmp->next = new_element;

            size++;
        }
    }

    void delete_pos(int pos) {
        if (size == 0) return;
        if (pos <= 0) {
            delete_head();
        }
        else if (pos >= size - 1) {
            delete_tail();
        }
        else {
            element* tmp = head;
            for (int i = 0; i < pos; i++)
                tmp = tmp->next;

            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
            size--;
        }
    }

    void print() const {
        element* tmp = head;
        while (tmp) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    void set(int s) {
        for (int i = 0; i < s; i++)
            add_head(get_random_number(-50, 50));
    }
};

int main() {
    srand(time(0));

    list l;
    l.set(10);

    int number, pos;

    do {
        system("cls");
        cout << "Current list: ";
        l.print();

        int choice = menu();
        if (choice == 0) break;

        switch (choice) {
        case 1:
            cout << "Enter number: ";
            cin >> number;
            l.add_head(number);
            break;
        case 2:
            cout << "Enter number: ";
            cin >> number;
            l.add_tail(number);
            break;
        case 3:
            l.delete_head();
            break;
        case 4:
            l.delete_tail();
            break;
        case 5:
            l.clear();
            break;
        case 6:
            cout << "Enter number: ";
            cin >> number;
            cout << "Enter position: ";
            cin >> pos;
            l.add_pos(number, pos);
            break;
        case 7:
            cout << "Enter position to delete: ";
            cin >> pos;
            l.delete_pos(pos);
            break;
        default:
            cout << "Incorrect input!";
            break;
        }

    } while (true);

    return 0;
}
