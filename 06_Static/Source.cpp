#include <iostream>
using namespace std;

#define NAME_SIZE 100

// Статичні поля - це поля, які використовуються спільно всіма об'єктами класу.
// Кажуть, що вони належать не конкретному об'єкту, а класу вцілому

class point {

private:
    // дані, поля
    int x, y;

    // функції, методи
public:
    static int count;
    static int liveObjects;

    point() {
        x = y = 0;
        count++;
        liveObjects++;
    }

    point(int x, int y) {
        this->x = x;
        this->y = y;
        count++;
        liveObjects++;
    }


    void set() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }

    // Методи аксесори

    // Модифікатори
    void set_x(int x_value) {
        x = x_value;
    }

    void set_y(int y_value) {
        y = y_value;
    }

    // Інспектори
    int get_x() {
        return x;
    }

    int get_y() {
        return y;
    }


    void print() {
        cout << "X: " << x << ", Y:" << y << "\n";
    }

    ~point() {
        liveObjects--;
    }
};
int point::count = 0;                                                                                         
int point::liveObjects = 0;

// Створити клас Employee(Працівник).
// Прізвище(last_name), унікальний ідентифікатор(id, int).
// При створенні об'єкта йому автоматично присвоється ідентифікатор.
// Першому працівникові - 1, другому - 2 ...
// Свторити декілька працівників і виіести інфо про них.
class employee{
private:
    char* surname;
    int id;
    static int id_count;

public:

    employee() {
        surname = new char[NAME_SIZE];
        id = id_count++;
    }

    employee(const char* surname) {
        this->surname = new char[strlen(surname) + 1];
        strcpy_s(this->surname, strlen(surname) + 1, surname);
        id = id_count++;
    }

    static int get_last_ID() {
        return id_count;
    }

    void set() {
        cout << "enter surname: ";
        gets_s(surname, NAME_SIZE);
        
    }

    void print() {
        cout << "Employee surname: " << surname << " | ";
        cout << "Employee ID: " << id << endl;
    }

    ~employee() {
        delete[] surname;
    }
};
int employee::id_count = 1;


class my_math {
public:
    static const double PI;

    static int sum(int a, int b) {
        return a + b;
    }

    static int min(int a, int b) {
        return a - b;
    }

    static int mul(int a, int b) {
        return a * b;
    }

    static float div(float a, float b) {
        return a / b;
    }

    static int square(int a) {
        return a*a;
    }
};
const double my_math::PI = 3.14;


class area {
private:
    static int area_count;
public:

    static int get_last_ID() {
        return area_count;
    }

    static float s_triangle(float base, float height) {
        area_count++;
        return 0.5 * base * height;
    }

    static float s_triangle(float a, float b, float angle) {
        area_count++;
        return 0.5 * a * b * sin(angle);
    }

    static float s_rectangle(float width, float height) {
        area_count++;
        return width * height;
    }

    static float s_square(float a) {
        area_count++;
        return a * a;
    }

    static float s_rombe(float d1, float d2) {
        area_count++;
        return 0.5 * d1 * d2;
    }

};
int area::area_count = 0;

int main() {
    //class point
    /*point p1(3, 4);
    point p2(-2, 4);
    point p3(3, -10);

    {
        point p4(1, 2);
    }

    cout << point::count << endl;
    cout << point::liveObjects;*/

    //class Employee
    /*employee w1("Dilan");
    employee w2("Yilo");
    employee w3("Bardis");
    w1.print();
    w2.print();
    w3.print();
    
    cout << endl << endl << employee::get_last_ID;*/

    //class my_math
    /*cout << my_math::div(3, 2);*/

    //class area
    /*cout << "Triangle area: " << area::s_triangle(3, 2) << "\n";
    cout << "Triangle area: " << area::s_triangle(3, 2, 30) << "\n";
    cout << "Rectangle area: " << area::s_rectangle(13, 2) << "\n";
    cout << "Square area " << area::s_square(32) << "\n";
    cout << "Rhombus area: " << area::s_rombe(32, 30) << "\n";
    cout << "Last ID: " << area::get_last_ID() << "\n";*/



    return 0;
}