#include <iostream>
#include <string>
using namespace std;


void line(int num) {
    cout << endl;
    for (int i = 0; i < num; i++)
        cout << "-";
    cout << endl;
}


class Figure {
public:
    float get_perimeter(float a, float b) const {
        return 2 * (a + b);
    }

    float get_area(float a, float b) const {
        return a * b;
    }
};


class TwoDimensionalFigure : public Figure {
protected:
    float a, b;
public:
    TwoDimensionalFigure(float a, float b) {
        this->a = a;
        this->b = b;
    }

    void set_a(float a) {
        this->a = a; 
    }
    void set_b(float b) {
        this->b = b;
    }

    float get_a() const {
        return a; 
    }
    float get_b() const { 
        return b; 
    }

    float get_perimeter() const {
        return Figure::get_perimeter(a, b); 
    }
    float get_area() const { 
        return Figure::get_area(a, b); 
    }

    virtual void print() const {
        cout << "Side-A: " << a << "\n";
        cout << "Side-B: " << b << "\n";
        cout << "Perimeter: " << get_perimeter() << "\n";
        cout << "Area: " << get_area() << "\n";
    }
};

class Rectangle : public TwoDimensionalFigure {
    string type_of_figure;
public:
    Rectangle(float a, float b)
        : TwoDimensionalFigure(a, b)
    {
        if (a == b)
            type_of_figure = "Square";
        else
            type_of_figure = "Rectangle";
    }

    string get_type_of_figure() const {
        return type_of_figure;
    }

    void print() const override {
        TwoDimensionalFigure::print();
        cout << "Type of figure: " << type_of_figure << "\n";
    }
};

int main() {
    srand(time(0));

    line(30);
    cout << "Creating geometric figures...\n";

    Rectangle rect1(4, 6);
    Rectangle rect2(5, 5);

    line(30);
    cout << "Figure 1:\n";
    rect1.print();

    line(30);
    cout << "Figure 2:\n";
    rect2.print();

    line(30);
    cout << "Program finished.\n";
    line(30);

    return 0;
}
