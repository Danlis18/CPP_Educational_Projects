#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <iomanip>

using namespace std;

class employee {
    string name;
    double salary;
public:
    employee(string name, double salary) {
        this->name = name;
        this->salary = salary;
    }

    void print() const {
        cout << "Name: " << name << "\n";
        cout << "Salary: " << salary << "\n";
    }


    double get_salary() const {
        return salary;
    }

    string get_name() const {
        return name;
    }
};





int main() {



    //find_if: 
    /*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 22, 97, 33, 11, 100, -2 };*/
	/*auto res = find(v.begin(), v.end(), 97);
    if (res != v.end()) {
        cout << "Found: " << *res;
    }
    else {
        cout << "Not found";
    }*/

    /*auto res = find_if(v.begin(), v.end(), [](int a) {
        return a < 0;
        });
    if (res != v.end()) {
        cout << "Found!" << *res;
    }
    else {
        cout << "Not found";
    }*/

    //find_if:
    /*vector<employee> employees = {
        employee("Alice Smith", 60000.00),
        employee("Bob Johnson", 75000.50),
        employee("Charlie Brown", 50000.00),
        employee("Diana Prince", 90000.25),
        employee("Eve Adams", 65000.00),
        employee("Frank White", 72000.75),
        employee("Arace Kelly", 88000.00),
        employee("Henry Ford", 55000.50),
        employee("Ivy Green", 68000.00),
        employee("Jack Taylor", 80000.10)
    };
    
    char s = 'D';
    auto res = find_if(employees.begin(), employees.end(), [&s](const employee& e) {
        return e.get_name()[0] == s;
	});
	res->print();*/



	//copy_if:
    /*vector<employee> result;

    copy_if(employees.begin(),
        employees.end(), 
		back_inserter(result), //поміщаємо в кінець вектора result усі потрібні нам елементи
        [](const employee& e) {
			return e.get_name()[0] == 'A';
            //return e.get_salary() >= 70000;
		});
	for (employee& e : result) {
        e.print();
        cout << "------------------\n";
    }*/

    /*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 22, 97, 33, 11, 100, -2 };
    vector<int> result;

    copy_if(v.begin(), v.end(),
        back_inserter(result), 
        [](int a) {
			return a % 2 == 0;
        });

    for (int& a : result) {
		cout << a << ", ";
    }*/



    /*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 3,  22, 3, 97, 33, 11, 100, -2 };*/
	//remove: - не моожна передавати лямбда функцію
    /*auto it = remove(v.begin(), v.end(), 3);

	v.erase(it, v.end());

    for (int el : v) {
        cout << el << " ";
    }*/

	//remove_if: можна передавати лямбда функцію
    /*auto it = remove(v.begin(), v.end(), [](int a) {
		    return a < 0;
    });

    v.erase(it, v.end());

    for (int el : v) {
        cout << el << " ";
    }*/

    /*vector<employee> employees = {
        employee("Alice Smith", 60000.00),
        employee("Bob Johnson", 75000.50),
        employee("Charlie Brown", 50000.00),
        employee("Diana Prince", 90000.25),
        employee("Eve Adams", 65000.00),
        employee("Frank White", 72000.75),
        employee("Arace Kelly", 88000.00),
        employee("Henry Ford", 55000.50),
        employee("Ivy Green", 68000.00),
        employee("Jack Taylor", 80000.10)
    };

    int salary = 80000;

    auto it = remove_if(employees.begin(), employees.end(), [&salary](employee e) {
        return e.get_salary() >= salary;
        });

    employees.erase(it, employees.end());

    for (employee& e : employees) {
        e.print();
        cout << "------------------\n";
    }*/



	//min_element / max_element and minmax_element:
    /*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 3,  22, 3, 97, 33, 11, 100, -2 };
	auto min_it = min_element(v.begin(), v.end());  
	auto max_it = max_element(v.begin(), v.end());
    cout << *max_it << " | " << *min_it;*/

    /*vector<employee> employees = {
        employee("Alice Smith", 60000.00),
        employee("Bob Johnson", 75000.50),
        employee("Charlie Brown", 50000.00),
        employee("Diana Prince", 90000.25),
        employee("Eve Adams", 65000.00),
        employee("Frank White", 72000.75),
        employee("Arace Kelly", 88000.00),
        employee("Henry Ford", 55000.50),
        employee("Ivy Green", 68000.00),
        employee("Jack Taylor", 80000.10)
    };

    auto max_employees = max_element(employees.begin(), employees.end(), [](const employee& e1, const employee& e2) {
        return e1.get_salary() < e2.get_salary();
           });

    max_employees->print();
    cout << endl;

    auto res = minmax_element(employees.begin(), employees.end(), [](const employee& e1, const employee& e2) {
        return e1.get_salary() < e2.get_salary();
        });

    res.first->print();
    cout << "-- -- -- -- --\n";
    res.second->print();*/


 //дефолтна поведінка сума (можна зробити усі дії математичні)
/*vector<int> v = { 10, 1, -6, 4, 7, 9, 11};

int res = accumulate(
    v.begin(),
    v.end(),
    1,
    [](int prev, int current) {
         //if(current % 2 == 0)
            //return prev + current;
          return prev;
        return current % 2 == 0 ? prev + current : prev; //: двокрапки це відділення умови іфа від елса
    });

cout << res; */


vector<employee> employees = {
        employee("Alice Smith", 60000.00),
        employee("Bob Johnson", 75000.50),
        employee("Charlie Brown", 50000.00),
        employee("Diana Prince", 90000.25),
        employee("Eve Adams", 65000.00),
        employee("Frank White", 72000.75),
        employee("Arace Kelly", 88000.00),
        employee("Henry Ford", 55000.50),
        employee("Ivy Green", 68000.00),
        employee("Jack Taylor", 80000.10)
};


int res = accumulate(
    employees.begin(),
    employees.end(),
    1,
    [](double prev, employee current) {
        return prev + current.get_salary();
        
    });
    cout << fixed << setprecision(20) << res;

}
