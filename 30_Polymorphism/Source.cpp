#include <iostream>
#include <string>
using namespace std;


// Поліморфізм - здатність коду при поcтійному інтерфейсі(зовнішньому вигдяді) працювати по різному, в залежності від ситуації момент виконання програми.
// Раннє зв'язування -  тип об'єкта відомий на етапі компіляції і виклик метода з кодом цього метода зв'язується на етапі компіляції.
// 
// Вказівник на батьківський клас може вказувати на будь-який дочірній клас.

// Якщо зв'язування виклику метода з кодом самого метода відбувається на етапі виконання програми, то зв'язування називається пізнім.


//1
class A {
public:
    virtual void func() {
        cout << "class A, func\n";
    }
};

class B : public A {
public:
    void func() override {
        cout << "class B, func\n";
    }
};

class C : public B {
public:
    void func() override {
        cout << "class C, func\n";
    }
};


//2

//Абстрактний клас - клас описується не для створенняоб'єктів, а для тих класів які його наслідують
class vehicle {
protected:
    string name, color;
public:
    vehicle(string name, string color) {
        this->name = name;
        this->color = color;
    }

    virtual void drive() = 0; // Чисто віртуальна функція
};

class car : public vehicle {
public: 
    car(string name, string color) : vehicle(name, color) {}
    void drive() override {
        cout << "I am driving " << color << " " << name << " car now\n";
    }
};

class bus : public vehicle {
public:
    bus(string name, string color) : vehicle(name, color) {}
    void drive() override {
        cout << "I am driving " << color << " " << name << " bus now\n";
    }
};

class moto : public vehicle {
public:
    moto(string name, string color) : vehicle(name, color) {}
    void drive() override {
        cout << "I am driving " << color << " " << name << " motocycle now\n";
    }
};


//3
class weapon {
public:
    virtual void shoot() {
        cout << "Weapon Shoot!\n";
    }
};

class gun : public weapon {
public:
    void shoot() override {
        cout << "Gun Shoot\n";
    }
};

class rifle : public weapon {
public:
    void shoot() override {
        cout << "Rifle Shoot\n";
    }
};

class machine_gun : public weapon {
public:
    void shoot() override  {
        cout << "Machine gun Shoot!\n";
    }
};

class player {

public:
    void shoot_weapon(weapon* w) {
        w->shoot();
    }

};


//4
class payment {
public:
    virtual void withdrawal() {
        cout << "Withdrawal\n";
    }
};

class crypto : public payment {
public:
    void withdrawal() override {
        cout << "Withdrawal by Crypto\n";
    }
};

class card : public payment {
public:
    void withdrawal() override {
        cout << "Withdrawal by card\n";
    }
};

class nfc : public payment {
public:
    void withdrawal() override {
        cout << "Withdrawal by NFC\n";
    }
};

class bankomat {

public:
    void withdrawal_variant(payment* b) {
        b->withdrawal();
    }

};



//Абстрактні класи

int main() {
    //2
    /*vehicle* v = nullptr;
    car c;
    bus b;
    moto m;

    cout << "1 - car\n";
    cout << "2 - bus\n";
    cout << "3 - moto\n";
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        v = &c;
        break;
    case 2:
        v = &b;
        break;
    case 3:
        v = &m;
        break;
    }

    v->drive();*/


    //1
    /*A objA;
    objA.func();

    B objB;
    objB.func();

    C objC;
    objC.func();*/

    /*A objA;
    B objB;
    C objC;*/

    /*A* pA = &objA;
    B* pB = &objB;
    C* pC = &objC;

    pA->func();
    pB->func();
    pC->func();*/

    /*A* pA = nullptr;
    pA = &objB;
    pA->func();
    pA = &objC;
    pA->func();*/



    //3
    //player p;
    ///*weapon* w = new gun;*/
    //p.shoot_weapon(new gun);
    //p.shoot_weapon(new rifle);
    //p.shoot_weapon(new machine_gun);


    //4
   /* bankomat b;
    b.withdrawal_variant(new crypto);
    b.withdrawal_variant(new nfc);
    b.withdrawal_variant(new card);*/


    /*vehicle* arr[] = { new car, new bus, new moto };

    for (vehicle* v : arr) {
        v->drive();
    }*/


    vehicle* v = new bus("f12", "red");
    v->drive();

    v = new car("ford", "green");
    v->drive();

    v = new moto("volvo", "black");
    v->drive();

    return 0;
}