#include <iostream>
using namespace std;
#define PI 3,14


//ћножинне насл≥дуванн¤ - це на¤вн≥сть пох≥дного класу б≥льше н≥ж одного базового


class car {
    string wheels;
public:
    car(string wheels) {
        this->wheels = wheels;
    }

    void drive() {
        cout << "I am driving!\n";
    }

    string get_wheels() {
        return wheels;
    }
};

class airplane {
    string wings;
public:
    airplane(string wings) {
        this->wings = wings;
    }

    void fly() {
        cout << "I am flying!\n";
    }

    string get_wings() {
        return wings;
    }
};

class flying_car : public car, public airplane {

public:
    flying_car(string wheels, string wings) : car(wheels), airplane(wings) {

    }
};


class circle {
    float radius;
    float area;
public:
    circle() {
        radius = 0;
    }

    circle(float radius) {
        this->radius = radius;
    }

    float get_perimetr_circle() {
        return radius * 2 * PI;
    }
    float get_area_circle() {
        return radius * radius * PI;
    }
};

class square {
    float side;
public:
    square() {
        side = 0;
    }

    square(float side) {
        this->side = side;
    }

    float get_perimetr_square() {
        return side * 4;
    }
    float get_area_square() {
        return side * side;
    }
};


class circlelnSquare : public circle, public square {

public:
    circlelnSquare(int radius, int side)
        : circle(radius), square(side) {
    }

    circlelnSquare() : circle(), square() {
    }


};




int main() {

    /*flying_car fc("fc wheels", "fc wings");

    fc.drive();
    fc.fly();

    cout << fc.get_wheels() << "\n";
    cout << fc.get_wings();*/

    circlelnSquare cs(32, 30);
    cout << cs.get_area_circle() << endl;
    cout << cs.get_area_square() << endl;
    cout << cs.get_perimetr_circle() << endl;
    cout << cs.get_perimetr_square() << endl;



    return 0;
}