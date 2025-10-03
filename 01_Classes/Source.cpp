#include <iostream>
using namespace std;
#define RECT_SIZE 4

//Об'єктно-орієнтоване програмування(ООП) - це вид програмування в якому програма реалізується у вигляді обєктів, що взамодіють між собою.

//ООП реалізується на основі 3-х базових принципів:
// - Інкапсуляція - це об'єднання даних та методів роботи за цими даними в однеєдне ціле - об'єкт. Основна властивість інкапслуяції - приховуванн даних.
// - Наслідування
// - Поліморфізм

//Клас - це спеціальна конструкціяб яка використовується для групуванння повязаних між собою даних та функціїї. Дані називаються поля, а функції - методи.



//Функціональне програмування (С мова)
/*struct point {
    int x;
    int y;
};

void set_point(point &p) {
    cout << "Enter x: ";
    cin >> p.x;
    cout << "Enter y: ";
    cin >> p.y;
}

void print_point(point p) {
    cout << "X: " << p.x << ", Y:" << p.y;
}

int main() {
    point p1;
    set_point(p1);
    print_point(p1);

    return 0;
}*/



//ОПП (C++)
class point {
    //дані - поля
private:
    int x, y;

    //функції - методи
public:

    void set() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    void set(int x_value, int y_value){
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

class rectangle {
    point points[RECT_SIZE];

public:
    void set() {
        for (int i = 0; i < RECT_SIZE; i++)
        {
            points[i].set();
        }
    }

    void print() {
        for (int i = 0; i < RECT_SIZE; i++)
        {
            points[i].print();
        }
    }
};

class student {
private:
    char name[100];
    char last_name[100];
    int age;
    float height;

public:

    void set() {
        cout << "Enter first_name: ";
        cin >> name;
        cout << "Enter last_name: ";
        cin >> last_name;
        cout << "Enter your age: ";
        cin >> age;
        cout << "Enter your height: ";
        cin >> height;
    }

    void set(const char* name_value, float height_value, int age_value, const char* last_name_value) {
        strcpy_s(name, name_value);
        strcpy_s(last_name, last_name_value);
        height = height_value;
        age = age_value;
    }

    void set_name(const char* name_value) {
        strcpy_s(name, name_value);
    }
    void set_last_name(const char* last_name_value) {
        strcpy_s(last_name, last_name_value);
    }
    void set_age(int age_values) {
        age = age_values;
    }
    void set_height(int height_value) {
        height = height_value;
    }

    void print() {
        cout << "First Name: " << name << " | Last Name: " << last_name << " | Your Age: " << age << " | Your Height: " << height << endl;
    }

    int get_age() {
        return age;
    }

    int get_height() {
        return height;
    }

    const char* get_name() {
        return name;
    }

    const char* get_last_name() {
        return last_name;
    }
};

class fraction {
    int numerator, denominator;

public:
    void set(int n, int d) {
        numerator = n;
        denominator = d;
    }

    void set() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
    }
    
    void print() {
        cout << numerator << "/" << denominator << "\n";
    }

    int get_integer() {
        return numerator / denominator;
    }

    double get_double() {
        return double(numerator) / denominator;  
    }

    fraction add(fraction other) {
        int res_numerator = this->numerator * other.denominator + this->denominator * other.numerator;
        int res_denominator = this->denominator * other.denominator;

        fraction res;
        res.set(res_numerator, res_denominator);

        return res;
    }

    fraction min(fraction other) {
        int res_numerator = this->numerator * other.denominator - this->denominator * other.numerator;
        int res_denominator = this->denominator * other.denominator;

        fraction res;
        res.set(res_numerator, res_denominator);

        return res;
    }

    fraction mult(fraction other) {
        int res_numerator = this->numerator * other.numerator;
        int res_denominator = this->denominator * other.denominator;

        fraction res;
        res.set(res_numerator, res_denominator);

        return res;
    }

    fraction divide(fraction other) {
        int res_numerator = this->numerator * other.denominator;
        int res_denominator = this->denominator * other.numerator;

        fraction res;
        res.set(res_numerator, res_denominator);

        return res;
    }


};



int main() {

    //Class point:
    /*point p;
    p.set();
    p.print();*/

    /*point pXY;
    pXY.set(100, 200);
    pXY.set_x(100);
    pXY.set_y(200);
    pXY.print();*/

    /*point p4;
    int res_x = p4.get_x();
    cout << "Res-x: " << res_x;
    cout << "Res-y: " << p4.get_y();*/

    //Class Rectangle:
    /*rectangle r;
    r.set();
    r.print();*/

    //Class Stydent:
    /*student s1;
    s1.set();
    s1.print();*/

    /*student s2;
    s2.set_last_name("Bobrov");
    s2.set_name("Marko");
    s2.set_height(135);
    s2.set_age(40);
    s1.print();*/
    
    /*student s3;
    s3.get_age();
    s3.get_name();
    s3.get_last_name();
    s3.get_height();
    s1.print();*/

    //Fraction
    fraction f1;
    f1.set(3, 4);
    /*f1.print();
    cout << f1.get_integer() << endl;
    cout << f1.get_double() << endl;*/

    fraction f2;
    f2.set(4, 3);

    fraction f_add = f1.add(f2);
    f_add.print();

    fraction f_min = f1.min(f2);
    f_min.print();

    fraction f_mult = f1.mult(f2);
    f_mult.print();

    fraction f_div = f1.divide(f2);
    f_div.print();


    return 0;
}