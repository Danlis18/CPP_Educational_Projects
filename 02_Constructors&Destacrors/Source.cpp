#include <iostream>
using namespace std;
#define LAST_NAME_SIZE 100
#define MARKS_SIZE 5
#define STUDENT_GRUP 5

//конруктор - це метод класу, який автоматично викликається при створенні об'єкта.
//Завдання конструктора:
// - ініціалізація об'єкта
// - виділення пам'яті

//Конструктори переважно описують в public сукції.

//Конструктори можна перевантажувати.
//Якщо ми е описуємо своо власного конструктора, то нам надається конструктор за замовчуванням.
//Якщо ми описали васний конструктор, то конструктор за замовчуванням видаляється.

class point {
    //дані - поля
private:
    int x, y;

public:
    //конструктори:

    point() {
        x = 0;
        y = 0;
    }

    point(int x_value, int y_value) {
        x = x_value;
        y = y_value;
    }


    //функції - методи

    void set() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    void set(int x_value, int y_value) {
        x = x_value;
        y = y_value;
    }

    //Методи аксесори
    //Модифікатори:
    void set_x(int x_value) {
        x = x_value;
    }

    void set_y(int y_value) {
        y = y_value;
    }

    void print() {
        cout << "X: " << x << ", Y:" << y << endl;
    }

    //інспектори:
    int get_x() {
        return x;
    }

    int get_y() {
        return y;
    }
};

class student {
    char* name;
    int age;

public:
    student(){
        name = new char[100];
        age = 0;
    }

    student(const char* name, int age) {
        this->name = new char[strlen(name) + 1];
        this->age = age;
        strcpy_s(this->name, strlen(name), name);
    }

    void set() {
        cout << "Entre: ";
        gets_s(name, 100);
        cout << "Age: ";
        cin >> age;
    }

    void print() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    //Десруктор:
    ~student() {
        delete[] name;
    }
};

class student_task {
private:
    char* last_name;
    int* marks;

public:

    student_task() {
        last_name = new char[LAST_NAME_SIZE];
        marks = new int[MARKS_SIZE];
    }

    student_task(const char* last_name, int* marks) {
        this->last_name = new char[strlen(last_name) + 1];
        strcpy_s(this->last_name, strlen(last_name) + 1, last_name);
 

        this->marks = new int[MARKS_SIZE];
        for (int i = 0; i < MARKS_SIZE; i++){
            this->marks[i] = marks[i];
        }
    }

    void set() {
        cout << "Entre last_name: ";
        gets_s(last_name, LAST_NAME_SIZE);
        for (int i = 0; i < MARKS_SIZE; i++) {
            cout << "Mark-" << i+1 << ": ";
            (cin >> marks[i]).get();
        }
    }

    void print() {
        cout << "Last_Name: " << last_name << endl;
        cout << "Marks: ";
        for (int i = 0; i < MARKS_SIZE; i++) {
            cout << marks[i];
            if (i < 4) {
                cout << ", ";
            }
            else {
                cout << "." << endl;
            }
        }
    }

    ~student_task() {
        delete[] last_name;
        delete[] marks;
    }
};

class group {
    char* group_name;
    int student_count;
    student_task* student_tasks;

public:
    group(int student_count) {
        group_name = new char[LAST_NAME_SIZE];
        this->student_count = student_count;

        this->student_tasks = new student_task[student_count];
    }

    void set() {
        cout << "Enter group name: ";
        cin >> group_name;
        cout << "Enter count of student: ";
        (cin >> student_count).get();
        for (int i = 0; i < student_count; i++)
        {
            student_tasks[i].set();
        }
    }

    void print() {
        for (int i = 0; i < student_count; i++)
        {
            student_tasks[i].print();
        }
    }

    ~group() {
        delete[] group_name;
        delete[] student_tasks;
    }
};


int main() {

    //Class point
    /*point p1;
    p1.print();

    point p2(10, 20);
    p2.print();*/


    //Class Student
    /*student s1;
    s1.set();
    s1.print();

    student s2("John", 20);
    s2.print();*/


    /*student_task s1;
    s1.set();
    s1.print();*/

    group gr1(2);
    gr1.set();
    gr1.print();

    /*group gr2;
    gr2.set();
    gr2.print();*/


    return 0;
}

