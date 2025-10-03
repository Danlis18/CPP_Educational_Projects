#include <iostream>
using namespace std;

#define NAME_SIZE 100


class stud {
    char* surname;

public:

    stud() {
        surname = new char[NAME_SIZE];

    }

    stud(const char* surname) {

        this->surname = new char[strlen(surname) + 1];
        strcpy_s(this->surname, strlen(surname) + 1, surname);
    }

    //Конструктор копіювання
    stud(const stud& other) {
        this->surname = new char[strlen(other.surname) + 1];
        strcpy_s(this->surname, strlen(other.surname) + 1, other.surname);
    };

    void set() {

        cout << "enter surname: ";
        gets_s(surname, NAME_SIZE);


    }

    void print() {
        cout << "surname: " << surname;

    }

    ~stud() {
        delete[] surname;
    }

};


// - Передача в якості пераметра об'єктаив функціїї або метод о значенню.
//void func1(stud s1) {}

void func2() {
    stud s;
    return s;
}



//Конструктор копіювання викликаєтсья в трьх випадках: (тільки при данамічний пім'яті)
// - Ініціалізація одного об'єкта в іншмй
// - Передача в якості пераметра об'єктаив функціїї або метод о значенню.
// - Повернення об'єта з функціїї або метода по знаенню

// Якщо ми виділяємо динамічну пам'ять і потім в деструкторі її 
// звільняємо, то ми маємо описати свій конструктор копіювання

int main() {

   stud s1("John");
    s1.print();

    stud s2 = s1;
    s2.print(); // 1 впадок

    //func1(s1);
    stud s2 = func2();
    s2.print();

    return 0;
}