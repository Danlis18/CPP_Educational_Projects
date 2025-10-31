#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


void find_car(vector<int> v, function<bool(int)> fn) {
    for (int el : v) {
        if (fn(el))
            cout << el << " ";
    }
    cout << "\n";
}

class car {
    string auto_name;
    int year;
    double engineVolume;
    double price;

public:
    car() {
        auto_name = "No-declared";
        year = 0;
        engineVolume = 0;
        price = 0;
    }

    car(string auto_name, int year, double engineVolume, double price) {
        this->auto_name = auto_name;
        this->year = year;
        this->engineVolume = engineVolume;
        this->price = price;
	}

    void print() {
        cout << "Auto Name: " << auto_name << " -> Year: " << year << " -> Engine Volume: " << engineVolume << " -> Price: " << price << endl;
	}
};

class dealership {
    vector<car> cars;

public:
    void add_car(car c) {
        cars.push_back(c);
	}

    void dell_car(car c) {
        cars.erase();
    }

    void find_car() {
        auto res = find_if(cars.begin(), cars.end(), [](const car& c) {
            return c.get_name()[0] == s;
        })
    }



    void print_cars() {
		cars.print();
};











int main() {








    return 0;
}
