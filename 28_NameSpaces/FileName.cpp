#include <iostream>
using namespace std;

//просори імен - це область оголошення данних та типів, яка забезпечує логічний зв'язок між ними.

namespace point_d2 {
    class point {
    private:
        int x, y;
    public:

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

        void set_x(int x_value) {
            x = x_value;
        }

        void set_y(int y_value) {
            y = y_value;
        }

        void print() {
            cout << "X: " << x << ", Y:" << y << endl;
        }

        int get_x() {
            return x;
        }

        int get_y() {
            return y;
        }
    };
}

namespace point_d3 {
    class point {
    private:
        int x, y, z;
    public:

        void set() {
            cout << "Enter x: ";
            cin >> x;
            cout << "Enter y: ";
            cin >> y;
            cout << "Enter z: ";
            cin >> z;
        }

        void set(int x_value, int y_value, int x) {
            x = x_value;
            y = y_value;
            this->z = z;
        }

        void set_x(int x_value) {
            x = x_value;
        }

        void set_y(int y_value) {
            y = y_value;
        }

        void set_z(int z) {
            this->z = z;
        }

        void print() {
            cout << "X: " << x << ", Y:" << y << ", Z:" << z << endl;
        }

        int get_x() {
            return x;
        }

        int get_y() {
            return y;
        }

        int get_z() {
            return z;
        }
    };
}


int main() {
    point_d2::point p2;
    p2.set();
    p2.print();

    cout << endl;

    point_d3::point p3;
    p3.set();
    p3.print();

    return 0;
}