#include <iostream>
using namespace std;

#define NAME_SIZE 100

template<class T>
class area {
private:
    static int area_count;
public:

    static T get_last_ID() {
        return area_count;
    }

    static T s_triangle(T base, T height) {
        area_count++;
        return 0.5 * base * height;
    }

    static T s_triangle(T a, T b, T angle) {
        area_count++;
        return 0.5 * a * b * sin(angle);
    }

    static T s_rectangle(T width, T height) {
        area_count++;
        return width * height;
    }

    static T s_square(T a) {
        area_count++;
        return a * a;
    }

    static T s_rombe(T d1, T d2) {
        area_count++;
        return 0.5 * d1 * d2;
    }

};
template<class T>
int area<T>::area_count = 0;

int main() {
    //class area
    cout << "Triangle area: " << area<int>::s_triangle(3, 2) << "\n";
    cout << "Triangle area: " << area<int>::s_triangle(3, 2, 30) << "\n";
    cout << "Rectangle area: " << area<int>::s_rectangle(13, 2) << "\n";
    cout << "Square area " << area<int>::s_square(32) << "\n";
    cout << "Rhombus area: " << area<int>::s_rombe(32, 30) << "\n";
    cout << "Last ID: " << area<int>::get_last_ID() << "\n";



    return 0;
}