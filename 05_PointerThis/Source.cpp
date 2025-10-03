#include <iostream>
using namespace std;


class point {

private:
    // дані, поля
    int x, y;

    // функції, методи
public:

    point() {
        x = y = 0;
    }

    point(int a, int b) {
        x = a;
        y = b;
    }


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
};



int main() {

    /*point p1(1, 2);
    p1.print();*/

    /*int a = 5;
    int* p = &a;*/

    //Stack memory:
    /*point p1(1, 2);
    point* pointer_p1 = &p1;
    //(*pointer_p1).print();
    pointer_p1->print(); */

    //Dynami memory:
    /*point* p1 = new point(2, 3);
    p1->print();*/


    //Статичні масиви з об'єктів
    /*point points[3];
    points[0].set();
    points[0].print();*/

    //point points[3] = { point(20, 10), point(20, 10) , point(20, 10) };
    //point points[3] = { {10, 20}, {0, 2}, {-4, 7} };

    //Диамічні масиви з об'єктів
    //point* points = new point[3];
    int size = 3;
    point* points = new point[3]{ {10, 20}, {0, 2}, {-4, 7} };

    for (int i = 0; i < size; i++)
    {
        //points[i].print();
        //(points + i)->print();
        (*(points + i)).print();
    }

    return 0;
}