#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <string>
using namespace std;


int menu() {
    cout << "\n======== MENU ========\n";
    cout << "1. Add a car\n";
    cout << "2. Show all cars\n";
    cout << "3. Find cars by Уear/Name/Engine-volume/Price\n";
    cout << "4. Sort cars by Уear/Name/Engine-volume/Price\n";
    cout << "5. Delete cars by Уear/Name/Engine-volume/Price\n";
    cout << "0. Exit\n";
    cout << "Your choice: ";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

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

    void print() const {
        cout << "Auto Name: " << auto_name << " -> Year: " << year << " -> Engine Volume: " << engineVolume << " -> Price: " << price << endl;
    }

    string get_name() const {
        return auto_name;
    };

    int get_year() const {
        return year;
    };

    double get_price() const {
        return price;
    };

    double get_engineVolume() const {
        return engineVolume;
    };
};

class dealership {
    vector<car> cars;

public:
    void add_car(const car& c) {
        cars.push_back(c);
    }

    // Видалення всіх авто, які задовольняють умову fn (готовий алгоритм remove_if)
    int delete_car(function<bool(const car&)> fn) {
        size_t old_size = cars.size();
        auto it = remove_if(cars.begin(), cars.end(),
            [&](const car& c) { return fn(c); });
        cars.erase(it, cars.end());
        return static_cast<int>(old_size - cars.size());
    }

    // Пошук і вивід усіх авто, що задовольняють умову fn (готовий алгоритм for_each)
    void find_car_by_element(function<bool(const car&)> fn) const {
        bool found = false;

        for_each(cars.begin(), cars.end(),
            [&](const car& c) {
                if (fn(c)) {
                    c.print();
                    found = true;
                }
            });

        if (!found) {
            cout << "No cars found matching the specified criteria." << endl;
        }
    }

    // Сортування за критерієм fn (готовий алгоритм sort)
    void sort_cars_by_element(function<bool(const car&, const car&)> fn) {
        sort(cars.begin(), cars.end(), fn);
    }

    void print_cars() const {
        if (cars.empty()) {
            cout << "The list of cars is empty." << endl;
            return;
        }
        for (const auto& c : cars) {
            c.print();
        }
    }

    bool empty() const {
        return cars.empty();
    }

};

int main() {
    setlocale(LC_CTYPE, "ukr");

    dealership d;
    int choice;

    do {
        choice = menu();

        switch (choice) {
        case 1: {
            string name;
            int year;
            double engine, price;

            cout << "Enter car name: ";
            cin.ignore();             
            getline(cin, name);
            cout << "Enter year of manufacture: ";
            cin >> year;
            cout << "Enter engine volume: ";
            cin >> engine;
            cout << "Enter price: ";
            cin >> price;

            d.add_car(car(name, year, engine, price));
            break;
        }
        case 2: {
            d.print_cars();
            break;
        }
        case 3: {
            if (d.empty()) {
                cout << "The car list is empty." << endl;
                break;
            }

            int year;
            cout << "Enter the year (cars after this year will be shown): ";
            cin >> year;

            cout << "Cars produced after " << year << ":" << endl;
            d.find_car_by_element([&](const car& c) {
                return c.get_year() > year;
                });
            break;
        }
        case 4: {
            if (d.empty()) {
                cout << "The car list is empty." << endl;
                break;
            }

            d.sort_cars_by_element([](const car& a, const car& b) {
                return a.get_price() > b.get_price();
                });

            cout << "Cars have been sorted by price (descending order)." << endl;
            d.print_cars();
            break;
        }
        case 5: {
            if (d.empty()) {
                cout << "The car list is empty." << endl;
                break;
            }

            string name;
            cout << "Enter car name to delete (all cars with this name will be removed): ";
            cin >> name;

            int removed = d.delete_car([&](const car& c) {
                return c.get_name() == name;
                });

            if (removed == 0) {
                cout << "No cars found with that name." << endl;
            }
            else {
                cout << removed << " car(s) have been deleted." << endl;
            }
            break;
        }
        case 0:
            cout << "Exiting the program..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
