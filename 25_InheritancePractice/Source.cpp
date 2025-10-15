#include <iostream>
#include <string>
using namespace std;


void line(int num) {
    for (int i = 0; i < num; i++)
        cout << "-";
    cout << endl;
}

string type_of_figure_func_4(float a,float b, int angle) {
	if (a == b && angle == 90)
		return "Square";
	else if (a != b && angle == 90)
		return "Rectangle";
	else if (a != b && angle != 90)
		return "Parallelogram";
	else
		return "Undefined figure";
};

string type_of_figure_func_3(float a, float b, float c, int angle) {
	if (a == b && b == c && angle == 60)
		return "Equilateral triangle";
	else if (a == b && b != c && angle != 60)
		return "Isosceles triangle";
	else if (a != b && b != c && angle != 60)
		return "Scalene triangle";
	else
		return "Undefined figure";
};  

class Figure {
public:
    float get_perimeter(float a, float b, float c = 0) const {
        if (c == 0) {
            return 2 * (a + b);
        }
        else {
            return a + b + c;
        }
    }

    float get_area(float a, float b, float c = 0) const {
        if (c == 0) {
            return a * b;
        }
        else {
            float p = (a + b + c) / 2;
            return sqrt(p * (p - a) * (p - b) * (p - c));
        }
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
        cout << "Perimeter: " << get_perimeter() << "\n";    }
};

class rectangle : public TwoDimensionalFigure {
    string type_of_figure;
    //const b != a;
public:
    rectangle(float a, float b)
        : TwoDimensionalFigure(a, b)
    {
        int angle = 90;
        type_of_figure = type_of_figure_func_4(a, b, angle);
    }

    string get_type_of_figure() const {
        return type_of_figure;
    }

    double get_area_rectangle() const {
        return get_area();
    }

    void print() const override {
        TwoDimensionalFigure::print();
        cout << "Area: " << get_area_rectangle() << "\n";
        cout << "Type of figure: " << type_of_figure << "\n";
    }
};

class square : public TwoDimensionalFigure {
    string type_of_figure;
    //const b = a;
public:
    square(float a, float b)
        : TwoDimensionalFigure(a, b)
    {
        int angle = 90;
        type_of_figure = type_of_figure_func_4(a, b, angle);
    }

    string get_type_of_figure() const {
        return type_of_figure;
    }

    double get_area_square() const {
        return get_area();
    }

    void print() const override {
        TwoDimensionalFigure::print();
        cout << "Area: " << get_area_square() << "\n";
        cout << "Type of figure: " << type_of_figure << "\n";
    }
};

class parallelogram : public TwoDimensionalFigure {
    string type_of_figure;
	int angle;
public:
    parallelogram(float a, float b, int angle)
        : TwoDimensionalFigure(a, b)
    {
        type_of_figure = type_of_figure_func_4(a, b, angle);
		this->angle = angle;
    }

    string get_type_of_figure() const {
        return type_of_figure;
    }

	double get_area_parallelogram() const {
		return get_area() * sin(angle * 3.14 / 180);
	}

    void print() const override {
        TwoDimensionalFigure::print();
        cout << "Area: " << get_area_parallelogram() << "\n";
        cout << "Type of figure: " << type_of_figure << "\n";		
    }
};



class ThirdDimensionalFigure : public Figure {
protected:
    float a, b, c;
public:
    ThirdDimensionalFigure(float a, float b, float c) {
        this->a = a;
        this->b = b;
		this->c = c;
    }

    void set_a(float a) {
        this->a = a;
    }
    void set_b(float b) {
        this->b = b;
    }

    void set_c(float c) {
        this->c = c;
    }

    float get_a() const {
        return a;
    }
    float get_b() const {
        return b;
    }

    float get_c() const {
        return c;
    }

    float get_perimeter() const {
        return Figure::get_perimeter(a, b, c);
    }
    float get_area() const {
        return Figure::get_area(a, b, c);
    }

    virtual void print() const {
        cout << "Side-A: " << a << "\n";
        cout << "Side-B: " << b << "\n";
        cout << "Side-C: " << c << "\n";
        cout << "Perimeter: " << get_perimeter() << "\n";
    }
};

class equilateral_triangle : public ThirdDimensionalFigure {
    string type_of_figure;
    //const b = a = ñ;
public:
    equilateral_triangle(float a, float b, float c)
        : ThirdDimensionalFigure(a, b, c)
    {
        int angle = 60;
        type_of_figure = type_of_figure_func_3(a, b, c, angle);
    }

    string get_type_of_figure() const {
        return type_of_figure;
    }

    double get_area_equilateral_triangle() const {
        return get_area();
    }

    void print() const override {
        ThirdDimensionalFigure::print();
        cout << "Area: " << get_area_equilateral_triangle() << "\n";
        cout << "Type of figure: " << type_of_figure << "\n";
    }
};

class isosceles_triangle : public ThirdDimensionalFigure {
    string type_of_figure;
    //const b = a = ñ;
    int angle;
public:
    isosceles_triangle(float a, float b, float c, float angle)
        : ThirdDimensionalFigure(a, b, c)
    {
        type_of_figure = type_of_figure_func_3(a, b, c, angle);
		this->angle = angle;
    }

    string get_type_of_figure() const {
        return type_of_figure;
    }

    double get_area_isosceles_triangle() const {
        return get_area();
    }

    void print() const override {
        ThirdDimensionalFigure::print();
        cout << "Area: " << get_area_isosceles_triangle() << "\n";
        cout << "Type of figure: " << type_of_figure << "\n";
    }
};

class scalene_triangle : public ThirdDimensionalFigure {
    string type_of_figure;
    //const b = a = ñ;
	int angle;
public:
    scalene_triangle(float a, float b, float c, float angle)
        : ThirdDimensionalFigure(a, b, c)
    {
        type_of_figure = type_of_figure_func_3(a, b, c, angle);
    }

    string get_type_of_figure() const {
        return type_of_figure;
    }

    double get_area_scalene_triangle() const {
        return get_area();
    }

    void print() const override {
        ThirdDimensionalFigure::print();
        cout << "Area: " << get_area_scalene_triangle() << "\n";
        cout << "Type of figure: " << type_of_figure << "\n";
    }
};



int main() {

    line(30);
    cout << "---Two Dimensional Figures---\n";

    parallelogram paral(4, 6, 78);
    rectangle rect(5, 8);
    square sq(10, 10);

    line(30);
    cout << "Figure 1:\n";
    paral.print();

    line(30);
    cout << "Figure 2:\n";
    rect.print();

    line(30);
    cout << "Figure 3:\n";
    sq.print();

	cout << endl;

    line(30);
    cout << "---Third Dimensional Figures---\n";

    equilateral_triangle equilateral(5, 5, 5);
    isosceles_triangle isosceles(5, 5, 8, 50);
    scalene_triangle scalene(3, 4, 5, 60);

    line(30);
    cout << "Figure 1:\n";
    equilateral.print();

    line(30);
    cout << "Figure 2:\n";
    isosceles.print();

    line(30);
    cout << "Figure 3:\n";
    scalene.print();


    return 0;
}
