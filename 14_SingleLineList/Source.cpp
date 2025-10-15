#include <iostream>
using namespace std;

// Динамічні структури даних(ДСД) - це структури даних,
// па'мять для яких виділяється по мірі необхідності.

// Вектор(Vector)
// Списки(Однозв'язний, Двозв'язний)
// Стек
// Черга(Проста, Кільцева, Черга з пріоритетами, Дек)
// Дерева(Бінарне дерево)


// Однозв'язний список - це ДСД, в якому об'єкти складаються із елементів,
// що містять певну інформацію і вказівник на інший елемент.


int menu() {

    cout << "\n\n0 - Exit\n";
    cout << "1 - Add Head\n";
    cout << "2 - Add Tail\n";
    cout << "3 - Delete Head\n";
    cout << "4 - Delete Last\n";
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
};

class list {
    element* head, * tail;
    int size;

public:
    list() {
        head = tail = nullptr;
        size = 0;
    }

    void add_head(int value) {

        element* new_element = new element;
        new_element->data = value;

        if (size == 0) {
            head = tail = new_element;
        }
        else {
            new_element->next = head;
            head = new_element;
            new_element = nullptr;
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
            tail = new_element;
            new_element = nullptr;
        }

        size++;
    }


    void delete_head() {
        element* tmp = head;

        if (size == 0) {
            return;
        }
        else {
            head = head->next;
            delete tmp;
            tmp = nullptr;
        }
        size--;
    }

    void delete_tail() {
        element* tmp = head;

        if (size == 0) {
            return;
        }

        else if (size == 1) {
            delete head;
            head = nullptr;
        }

        else {
            while (tmp->next != tail) {
                tmp = tmp->next;
            }
            delete tail;
            tail = tmp;
            tmp->next = nullptr;
            tmp = nullptr;
        }
        size--;
    }

    void clear() {
        while (size != 0) {
            delete_head();
        }
    }

    void add_pos(int pos, int value) {

        if (size == 0) add_head(value);
        else if (pos == size) add_tail(value);
        else {
            element* new_element = new element;
            new_element->data = value;

            element* tmp = head;

            int i = 0;
            while (i++ < pos - 1)
                tmp = tmp->next;

            new_element->next = tmp->next;

            tmp->next = new_element;

            size++;
        }
    }

    void dell_pos(int pos) {
        if (size == 0) return;

        if (pos == 0) {
            element* tmp = head;
            head = head->next;
            delete tmp;
        }
        else {
            element* tmp = head;
            int i = 0;
            while (i++ < pos - 1 && tmp->next != nullptr)
                tmp = tmp->next;

            if (tmp->next != nullptr) {
                element* to_delete = tmp->next;
                tmp->next = tmp->next->next;
                delete to_delete;
            }
            else {
                return;
            }
        }

        size--;
    }


    void print() const {

        element* tmp = head;

        while (tmp) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }

    void set(int size) {
        for (int i = 0; i < size; i++)
            add_head(get_random_number(-50, 50));
    }


    ~list() {
        clear();
    }
};


int main() {
    srand(time(0));

    int number;

    list l;
    l.set(10);


    do {
        system("cls");
        l.print();
        int pos = 0;
        int choice = menu();
        if (!choice) break;

        switch (choice)
        {
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
            cout << "Enter pos: ";
            cin >> pos;
            l.add_pos(number, pos);
            break;
        case 7:
            cout << "Enter pos: ";
            cin >> pos;
            l.dell_pos(pos);
            break;
        default:
            cout << "Incorrect input";
            break;
        }
    } while (true);







    return 0;
}