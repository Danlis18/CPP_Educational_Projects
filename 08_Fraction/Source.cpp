#include <iostream>
using namespace std;

class fraction {
    int numerator, denominator;
public:
    fraction() {
        numerator = 0;
        denominator = 1;
    }

    fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void set(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void set() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
    }

    int get_integer() {
        return numerator / denominator;
    }

    int get_numerator() const {
        return numerator;
    }

    int get_denominator() const {
        return denominator;
    }

    double get_double() {
        return (double)numerator / denominator;
    }

    operator int() {
        return (int)numerator / denominator;
    }

    operator double() {
        return (double)numerator / denominator;
    }


    fraction add(fraction other) {

        int res_numerator = this->numerator * other.denominator + this->denominator * other.numerator;

        int res_denominator = this->denominator * other.denominator;

        fraction res;
        res.set(res_numerator, res_denominator);

        return res;
    }

    void print() {
        cout << numerator << "/" << denominator << "\n";
    }

};

fraction operator+(const fraction& first, const fraction& second) {
    int res_numerator = first.get_numerator() * second.get_denominator() + first.get_denominator() * second.get_numerator();
    int res_denominator = first.get_denominator() * second.get_denominator();
    return fraction(res_numerator, res_denominator);;
}

//fraction operator+(const fraction& first, int number) {
//    int res_numerator = first.get_numerator() * 1 + first.get_denominator() * number;
//    int res_denominator = first.get_denominator() * 1;
//    return fraction(res_numerator, res_denominator);;
//} знизу те саме, тут просто описана логіка 

fraction operator+(const fraction& first, int number) {
    return  first + fraction(number, 1);
}

fraction operator+(int number, const fraction& second) {
    return fraction(number, 1) + second;
}


fraction operator-(const fraction& first, const fraction& second) {
    int res_numerator = first.get_numerator() * second.get_denominator() - first.get_denominator() * second.get_numerator();
    int res_denominator = first.get_denominator() * second.get_denominator();
    return fraction(res_numerator, res_denominator);
}

fraction operator-(const fraction& first, int number) {
    return  first - fraction(number, 1);
}

fraction operator-(int number, const fraction& second) {
    return fraction(number, 1) - second;
}


fraction operator*(const fraction& first, const fraction& second) {
    int res_numerator = first.get_numerator() * second.get_numerator();
    int res_denominator = first.get_denominator() * second.get_denominator();
    return fraction(res_numerator, res_denominator);
}

fraction operator*(const fraction& first, int number) {
    return  first * fraction(number, 1);
}

fraction operator*(int number, const fraction& second) {
    return fraction(number, 1) * second;
}


fraction operator/(const fraction& first, const fraction& second) {
    int res_numerator = first.get_numerator() * second.get_denominator();
    int res_denominator = first.get_denominator() * second.get_numerator();
    return fraction(res_numerator, res_denominator);
}

fraction operator/(const fraction& first, int number) {
    return  first / fraction(number, 1);
}

fraction operator/(int number, const fraction& second) {
    return fraction(number, 1) / second;
}


bool operator==(const fraction& first, const fraction& second) {
    return first.get_numerator() * second.get_denominator() == second.get_numerator() * first.get_denominator();
}

bool operator!=(const fraction& first, const fraction& second) {
    return !(first == second);
}

bool operator<(const fraction& first, const fraction& second) {
    return first.get_numerator() * second.get_denominator() < second.get_numerator() * first.get_denominator();
}

bool operator>(const fraction& first, const fraction& second) {
    return second < first;
}

bool operator<=(const fraction& first, const fraction& second) {
    return !(first > second);
}

bool operator>=(const fraction& first, const fraction& second) {
    return !(first < second);
}

ostream& operator << (ostream& os, const fraction& obj) {
    os << obj.get_numerator() << "/" << obj.get_denominator() << "\n";
    return os;
}

istream& operator>> (istream& is, fraction& obj) {
    obj.set();
    return is;
}

#include <iostream>
using namespace std;

int main() {
    /*fraction f1(1, 2);
    fraction f2(3, 4);

    cout << "f1 = ";
    f1.print();

    cout << "f2 = ";
    f2.print();

    cout << "f1 + f2 = ";
    (f1 + f2).print();

    cout << "f1 - f2 = ";
    (f1 - f2).print();

    cout << "f1 * f2 = ";
    (f1 * f2).print();

    cout << "f1 / f2 = ";
    (f1 / f2).print();

    cout << endl;

    cout << "f1 == f2 ? " << (f1 == f2) << endl;
    cout << "f1 != f2 ? " << (f1 != f2) << endl;
    cout << "f1 <  f2 ? " << (f1 < f2) << endl;
    cout << "f1 >  f2 ? " << (f1 > f2) << endl;
    cout << "f1 <= f2 ? " << (f1 <= f2) << endl;
    cout << "f1 >= f2 ? " << (f1 >= f2) << endl << endl;

    fraction f3;
    cout << "Now enter your own fraction: " << endl;
    f3.set();
    cout << "You entered: ";
    f3.print();
    cout << " = " << f3.get_double() << endl;*/

    fraction f3(5, 2);
    fraction f4(7, 8); 
    
    /*cout << f3;
    cin >> f4;
    cout << f4;
    cout << int(f3) << endl;
    cout << double(f4) << endl;*/

    cout << f3 + f4;
    cout << f3 - f4;
    cout << f3 * f4;
    cout << f3 / f4;

    return 0;
}