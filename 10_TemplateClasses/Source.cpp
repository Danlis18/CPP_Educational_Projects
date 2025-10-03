#include <iostream>
using namespace std;


//Шаблонні Класи 

template<class T>
class my_class {
	T a;
public:
	my_class() { a = 0; }
	my_class(T a) { this->a = a; }
	void set_a(T a) { this->a = a; }
	T get_a() const { return a; }
	void print() const { cout << a << "\n"; }
};


template <class P>
class point {
private:
    P x, y;

public:

    point() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    point(P x_value, P y_value) {
        x = x_value;
        y = y_value;
    }

    void set_x(P x_value) {
        x = x_value;
    }

    void set_y(P y_value) {
        y = y_value;
    }

    void print() const {
        cout << x << ", " << y;
    }

    P get_x() {
        return x;
    }

    P get_y() {
        return y;
    }

    template<class P>
    friend double distance(point<P> p1, point<P> p2);
};

template<class P>
double distance(point<P> p1, point<P> p2) {
    return sqrt(pow(p1.get_y() - p1.get_x(), 2) + pow(p2.get_y() - p2.get_x(), 2));
};

template<class P>
ostream& operator<< (ostream& os, const point<P>& obj) {
    obj.print();
    return os;
}

int main() {
	/*my_class<int> obj(100);
	obj.print();

	my_class<double> obj1(10.432);
	obj1.print();

	my_class<char> obj2('h');
	obj2.print();*/

    point<int> p1;
    point<int> p2;
    double res = distance(p1, p2);
    cout << "The distance between p1(" << p1 << ") and p2(" << p2 << ") is " << res;

	return 0;
}