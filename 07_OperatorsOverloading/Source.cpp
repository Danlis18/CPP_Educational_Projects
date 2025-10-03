#include <iostream>
#include <iomanip>
using namespace std;
#define ROWS 4
#define COLS 3

class my_class {
    int x;
public:

    my_class() {
        x = 0;
    }

    my_class(double x) {
        this->x = x;
    }

    void set_x(double x) {
        this->x = x;
    }

    int get_x() const {
        return x;
    }


    void print() const {
        cout << "x: " << x << "\n";
    }

    //my_class operator+(const my_class& other) {
    //    my_class res;
    //    res.x = this->x + other.x;
    //    return res;
    //}

    operator int() {
        return (int)x;
    }
};

class matrix {

    int data[ROWS][COLS] = {
        {10, 3, -6},
        {10, -2, 4},
        {1, 12, -65},
        {-32, 32, 8},
    };

public:

    void print() const {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                cout << setw(5) << data[i][j];
            }
            cout << endl;
        }
    }

    int& operator()(unsigned int row_index, unsigned int col_index) {
        return data[row_index][col_index];
    }

};

my_class operator+(const my_class& first, const my_class& second) {
    /*my_class res;
    res.set_x(first.get_x() + second.get_x());
    return res;*/
    return my_class(first.get_x() + second.get_x());
}

my_class operator-(const my_class& first, const my_class& second) {
    /*my_class res;
    res.set_x(first.get_x() - second.get_x());
    return res;*/
    return my_class(first.get_x() - second.get_x());
}

bool operator==(const my_class& first, const my_class& second) {
    return first.get_x() == second.get_x();
}

bool operator!=(const my_class& first, const my_class& second) {
    return !(first == second);
}

ostream& operator << (ostream& os, const my_class& obj) {
    os << obj.get_x() << "\n";
    return os;
}

istream& operator>> (istream& is, my_class& obj) {
    double x;
    is >> x;
    obj.set_x(x);
    return is;
}


int main() {
    //My_class

    /*my_class a(5);
    my_class b(4);

    my_class res = a + b;
    res.print();
    my_class res_min = a - b;
    res_min.print();

    bool res_ = a != b;
    cout << res_;*/

    my_class obj(100);
    cin >> obj;
    cout << obj;
    cout << int(obj);


    //Matrix
    /*matrix m;
    m(2, 1) = 1000;
    m.print();*/

    return 0;
}