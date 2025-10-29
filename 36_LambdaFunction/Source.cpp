#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


void print_vector(vector<int> v, function<bool(int)> fn) {
    for (int el : v) {
        if (fn(el))
            cout << el << " ";
    }
    cout << "\n";
}

int count_vector(vector<int> v, function<bool(int)> fn) {
    int count = 0; 
    for (int el : v) {
        if (fn(el))
            count ++;
    }
    return count;
}


int getLenght(int a) {
    int count = 0;
    while (a) {
        a /= 10;
        count++;
    }
    return count;
}

bool is_odd(int a) {
    return a % 2 != 0;
}

bool isSimple(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool is_negative(int a) {
    return a < 0;
}


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


class student {
    string name;
    string surname;
    string curs;
    double avarange_value;
public:
    student(string name, string surname, double avarange_value, string curs) {
        this->name = name;
        this->surname = surname;
        this->curs = curs;
        this->avarange_value = avarange_value;
    }

    void print() const {
        cout << "Name: " << name << " || Surname: " << surname << " || Curs: " << curs << " || Avarange Value: " << avarange_value << "\n";
    }

    double get_avarange_value() const {
        return avarange_value;
    }

    string get_curs() const {
        return curs;
    }
};


//void my_sort(vector<int>& v, function<bool(int, int)> fn) {
//    for (int i = 0; i < v.size() - 1; i++) {
//        for (int j = v.size() - 1; j > i; j--) {
//            if (fn(v[j], v[j - 1]))
//                swap(v[j], v[j - 1]);
//        }
//    }
//}

bool operator<(const employee& a, const employee& b) {
    return a.get_name() < b.get_name();
}

int main() {



    /*vector<int> v = { 10, 1, 6, -2, 3, 23, -3, 22, -97, 33, -11, 100, -2 };
    print_vector(v, is_even);
    print_vector(v, is_odd);
    print_vector(v, isSimple);
    print_vector(v, is_negative);*/



    //Анонімні(лямда функціїї)
    // [](){}

    /*function<void(int)> f = [](int a) {
        cout << "Value: " << a;
        };
    f(32);*/

    /*[](int a) {
        cout << "Value: " << a;
        }(32);*/


    //Завдання 1
    /*vector<int> b = { 10, 1, 6, -2, 3, 23, -3, 22, -97, 33, -11, 100, -2 };
    cout << count_vector(b, [] (int a) {return a % 2 == 0;}) << endl;
    cout << count_vector(b, [] (int a) {return a > 0;}) << endl;
  
    int n, b;
    cout << "Value of count number: ";
    cin >> n;
    int count = count_vector(b, [&n, b](int a) {return getLenght(a) == n;}); //&n - створюємо посилання на n || всі зміні по значеню =.
    cout << count; */
   
 
    //Алгоритм
    /*vector<int> v = { 10, 1, 6, -2, 3, 23, -3, 22, -97, 33, -11, 100, -2 };
    int count = count_if(v.begin() + 2, v.end(), [](int a) {return a % 2 != 0;});
    cout << count;*/

    vector<employee> employees = {
        employee("Alice Smith", 60000.00),
        employee("Bob Johnson", 75000.50),
        employee("Charlie Brown", 50000.00),
        employee("Diana Prince", 90000.25),
        employee("Eve Adams", 65000.00),
        employee("Arank White", 72000.75),
        employee("Grace Kelly", 88000.00),
        employee("Henry Ford", 55000.50),
        employee("Avy Green", 68000.00),
        employee("Jack Taylor", 80000.10)
    };
  
    cout << count_if(employees.begin(), employees.end(), [](const employee& e) {return e.get_salary() >= 60000; });
    //sort(employees.begin(), employees.end(), [](employee a, employee b) {return a.get_salary() > b.get_salary(); });

    sort(employees.begin(), employees.end());
    

    cout << count_if(employees.begin(), employees.end(), [](const employee& e) {return e.get_name()[0] == 'A'; });
    for_each(employees.begin(), employees.end(), [](const employee& e) {e.print(); });

    //Функція яка викликає кожний елемент.
    /*for_each(employees.begin(), employees.end(), [](const employee& e) {e.print(); }*/
    
    /*vector<int> v = { 10, 1, 6, -2, 3, 23, -3, 22, -97, 33, -11, 100, -2 };
    int sum = 0;
    for_each(v.begin(), v.end(), [&sum](int el) {
        sum += el;
    });
    cout << endl << sum;*/



    //Завдання 2
    /*vector<student> students = {
          student("John", "Smith", 12, "Programming"),
          student("Emily", "Johnson", 10, "Natural Sciences"),
          student("Michael", "Williams", 8, "Mathematics"),
          student("Sarah", "Brown", 9, "Physics"),
          student("David", "Jones", 11, "Programming"),
          student("Jessica", "Garcia", 7, "Biology"),
          student("James", "Martinez", 6, "Chemistry"),
          student("Laura", "Hernandez", 5, "Literature"),
          student("Daniel", "Lopez", 12, "Programming"),
          student("Mia", "Gonzalez", 10, "History")
    };

    cout << "Value of propusk student: " << count_if(students.begin(), students.end(), [](const student& s) {return s.get_avarange_value() >= 9 && s.get_curs() == "Programming"; }) << endl;
    for_each(students.begin(), students.end(), [](const student& e) {e.print(); });*/






    /*vector<int> v = { 10, 1, 6, -2, 3, 23, 3, -11, 22, 97, 33, 11, 100, -2 };

    my_sort(v, [](int a, int b) {return a < b; });

    sort(v.begin(), v.end(), [](int a, int b) {return a < b;});

    for (int el : v) {
        cout << el << " ";
    }*/




    return 0;
}