#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <string>
#include <stdexcept>
using namespace std;


int safeInputInt(const string& text_need) {
    int x;
    while (true) {
        try {
            cout << text_need;
            cin >> x;

            if (!cin) {
                cin.clear();
                cin.ignore(1000, '\n');
                throw runtime_error("Error: You must enter an integer!");
            }
            return x;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }
    }
}

double safeInputDouble(const string& text_need) {
    double x;
    while (true) {
        try {
            cout << text_need;
            cin >> x;

            if (!cin) {
                cin.clear();
                cin.ignore(1000, '\n');
                throw runtime_error("Error: You must enter a number (double)!");
            }
            return x;
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }
    }
}

int menu() {
    cout << "\n======== MENU ========\n";
    cout << "1. Add a car\n";
    cout << "2. Show all cars\n";
    cout << "3. Find cars\n";
    cout << "4. Sort cars\n";
    cout << "5. Delete cars\n";
    cout << "0. Exit\n";

    return safeInputInt("Enter your choice: ");
}

int menu_fieldChoice() {
    cout << "\nSort cars by:\n";
    cout << "1. Name\n";
    cout << "2. Year\n";
    cout << "3. Engine volume\n";
    cout << "4. Price\n";
    cout << "5. Brand\n";

    return safeInputInt("Your choice: ");
}

int menu_orderChoice() {
    cout << "\nOrder:\n";
    cout << "1. Ascending\n";
    cout << "2. Descending\n";

    return safeInputInt("Your choice: ");
}

int menu_searchChoice() {
    cout << "\nFind cars by:\n";
    cout << "1. Name\n";
    cout << "2. Year (after given year)\n";
    cout << "3. Price range [min; max]\n";
    cout << "4. Cheapest and most expensive\n";
    cout << "5. Brnad\n";
    cout << "0. Back\n";

    return safeInputInt("Your choice: ");
}


class car {
    string auto_name;
    string auto_brand;
    int year;
    double engineVolume;
    double price;

public:
    car() {
        auto_name = "No-declared";
        auto_brand = "No-declared";
        year = 0;
        engineVolume = 0;
        price = 0;
    }

    car(string auto_name, int year, double engineVolume, double price, string auto_brand) {
        this->auto_name = auto_name;
        this->year = year;
        this->engineVolume = engineVolume;
        this->price = price;
        this->auto_brand = auto_brand;
    }

    void print() const {
        cout << "Auto Name: " << auto_name << " -> Brand: " << auto_brand << " -> Year: " << year << " -> Engine Volume: " << engineVolume << " -> Price: " << price << "$" << endl;
    }

    string get_name() const {
        return auto_name;
    }

    string get_name_brand() const { 
        return auto_brand; 
    }

    int get_year() const { 
        return year;
    }

    double get_price() const { 
        return price;
    }

    double get_engineVolume() const { 
        return engineVolume;
    }
};

//string::npos — це спеціальне значення в C++, яке використовується для позначення ситуації, коли підрядок не знайдено у рядку.
bool car_finder_indentifi(const car& c, const string& query) {
    if (c.get_name().find(query) != string::npos) {
        return true;
    }

    if (to_string(c.get_year()).find(query) != string::npos) {
        return true;
	}

    if (to_string(c.get_engineVolume()).find(query) != string::npos){
        return true;
	}

    if (to_string(c.get_price()).find(query) != string::npos){
		return true;
	}

    if (c.get_name_brand().find(query) != string::npos) {
		return true;
    }

    return false;
}


class dealership {
    vector<car> cars;

public:
    void add_car(const car& c) {
        cars.push_back(c);
    }

    int delete_car_by_element(function<bool(const car&)> fn) {
        auto temp = cars.size();

        cars.erase(remove_if(cars.begin(), cars.end(), fn), cars.end());

        return temp - cars.size();
    }

    void find_car_by_element(function<bool(const car&)> fn) const {
        bool found = false;

        for (const auto& c : cars) {
            if (fn(c)) {
                if (!found) {
                    cout << "Found cars:\n";
                    found = true;
                }
                c.print();
            }
        }
        if (!found)
            cout << "No cars found by given criteria.\n";
    }

    void sort_cars_by_element(function<bool(const car&, const car&)> fn) {
        sort(cars.begin(), cars.end(), fn);
    }

    void print_cars() const {
        if (cars.empty()) {
            cout << "The list of cars is empty.\n";
            return;
        }
        for (const auto& c : cars)
            c.print();
    }

    bool empty() const {
        return cars.empty();
    }

    void print_min_max_price() const {
        if (cars.empty()) {
            cout << "The list of cars is empty.\n";
            return;
        }

        auto min = min_element(cars.begin(), cars.end(), [](const car& a, const car& b) {
                return a.get_price() < b.get_price();
            });

        auto max = max_element(cars.begin(), cars.end(), [](const car& a, const car& b) {
                return a.get_price() < b.get_price();
            });

        cout << "\nCheapest car:\n";
        min->print();

        cout << "\nMost expensive car:\n";
        max->print();
    }
};


bool isEmpty(const dealership& d) {
    if (d.empty()) {
        cout << "The car list is empty.\n";
        return true;
    }
    return false;
}


int main() {
    setlocale(LC_CTYPE, "ukr");

    dealership d;
    int choice;

    do {
        system("cls");
        choice = menu();

        switch (choice) {
        case 1: {
            string name, brand;
            int year;
            double engine, price;

            cout << "Enter car name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter car brand: ";
            getline(cin, brand);

            year = safeInputInt("Enter year of manufacture: ");
            engine = safeInputDouble("Enter engine volume: ");
            price = safeInputDouble("Enter price: ");

            d.add_car(car(name, year, engine, price, brand));
            cout << "Car added successfully!\n";
            Sleep(1000);
            break;
        }

        case 2: {
            d.print_cars();
            cout << endl;
            system("pause");
            break;
        }

        case 3: {
            if (isEmpty(d)) {
                system("pause");
                break;
            }

            int searchChoice = menu_searchChoice();
            switch (searchChoice) {
            case 1: {
                string query;
                cout << "Enter name substring: ";
                cin.ignore();
                getline(cin, query);

                d.find_car_by_element([&query](const car& c) {
                    return c.get_name().find(query) != string::npos;
                    });
                break;
            }
            case 2: {
                int from_year = safeInputInt("Enter minimal year (cars from this year to the latest will be shown): ");
                d.find_car_by_element([&from_year](const car& c) {
                    return c.get_year() >= from_year;
                    });
                break;
            }
            case 3: { 
                double min_price = safeInputDouble("Enter minimal price: ");
                double max_price = safeInputDouble("Enter maximal price: ");

                if (max_price < min_price) {
                    cout << "Max price is less than min price. Swapping them.\n";
                    double tmp = min_price;
                    min_price = max_price;
                    max_price = tmp;
                }

                d.find_car_by_element([&min_price, &max_price](const car& c) {
                    return c.get_price() >= min_price && c.get_price() <= max_price;
                    });
                break;
            }
            case 4: {
                d.print_min_max_price();
                break;
            }
            case 5: {
                string query;
                cout << "Enter brand name: ";
                cin.ignore();
                getline(cin, query);

                d.find_car_by_element([&query](const car& c) {
                    return c.get_name_brand().find(query) != string::npos;
                    });
                break;
            }
            case 0:
                break;

            default:
                cout << "Invalid choice in search menu.\n";
                break;
            }

            cout << endl;
            system("pause");
            break;
        }

        case 4: {
            if (isEmpty(d)) {
                system("pause");
                break;
            }

            int fieldChoice = menu_fieldChoice();
            int orderChoice = menu_orderChoice();
            bool ascending = (orderChoice == 1);

            d.sort_cars_by_element([&ascending, &fieldChoice](const car& a, const car& b) {
                switch (fieldChoice) {
                case 1:
                    if (ascending) 
                        return a.get_name() < b.get_name();
                    else 
                        return a.get_name() > b.get_name();
                case 2:
                    if (ascending) 
                        return a.get_year() < b.get_year();
                    else 
                        return a.get_year() > b.get_year();
                case 3:
                    if (ascending) 
                        return a.get_engineVolume() < b.get_engineVolume();
                    else 
                        return a.get_engineVolume() > b.get_engineVolume();
                case 4:
                    if (ascending) 
                        return a.get_price() < b.get_price();
                    else 
                        return a.get_price() > b.get_price();
                case 5:
                    if (ascending) 
                        return a.get_name_brand() < b.get_name_brand();
                    else 
                        return a.get_name_brand() > b.get_name_brand();
                default:
                    return false;
                }
                });

            cout << "Cars have been sorted.\n";
            d.print_cars();
            cout << endl;
            system("pause");
            break;
        }

        case 5: {
            if (isEmpty(d)) {
                system("pause");
                break;
            }

            string query;
            cout << "Enter delete query (name / year / engine / price / brand): ";
			cin.ignore();
            getline(cin, query);

            int removed = d.delete_car_by_element([&query](const car& c) {
                return car_finder_indentifi(c, query);
                });

            if (removed == 0)
                cout << "No cars matched your query.\n";
            else
                cout << removed << " car(s) deleted.\n";

            cout << endl;
            system("pause");
            break;
        }

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
            Sleep(1000);
            break;
        }

    } while (choice != 0);

    return 0;
}
