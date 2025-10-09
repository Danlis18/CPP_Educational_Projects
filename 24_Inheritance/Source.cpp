#include <iostream>
#include <string>
using namespace std;
#define SIZE 10

void line(int num) {
	cout << endl;
	for (int i = 0; i < num; i++)
	{
		cout << "-";
	}
	cout << endl;
}
// Наслідування - це механізм, при якому об'єкти одного класу
// отримують властивості об'єкта іншого класу,
// і добавляються властивості, які характерні тільки йому.

// Наслідування - це розширення одного класу іншим класом.

// Людина(прізвище, імя, вік) (базовий, батьківський, супер)
// Працівник(зар.плата, посада) (похідний, дочірній, сабкласи)

class person {
protected:
	string name, surname;
	int age;

public:
	person() {
		this->name = "No set name";
		this->surname = "No set surname";
		this->age = 0;
	}

	person(string name, string surname, int age) {
		this->name = name;
		this->surname = surname;
		this->age = age;
	}


	void set_name(string name) {
		this->name = name;
	}

	void set_surname(string surname) {
		this->surname = surname;
	}

	string get_name() const {
		return name;
	}

	string get_surname() const {
		return surname;
	}

	void set_age(int age) {
		this->age = age;
	}

	int get_age() const {
		return age;
	}

	void print() const {
		cout << "Name: " << name << "\n";
		cout << "Surname: " << surname << "\n";
		cout << "Age: " << age << "\n";
	}
};

class employee : public person {
	int salary;

public:
	employee() : person() {
		this->salary = 0;
	}

	employee(string name, string surname, int age, int salary)
		: person(name, surname, age){
		this->salary = salary;
	}

	void set_salary(int salary) {
		this->salary = salary;
	}

	int get_salary() const {
		return salary;
	}

	void print() const {
		person::print();
		//cout << "Surname: " << surname; //за допомогою protected
		cout << "Salary: " << salary;
	}
};

class boss : public employee {
	string position;

public:
	boss() : employee() {
		this->position = "No set position";
	}

	boss(string name, string surname, int age, int salary, string position)
		: employee(name, surname, age, salary) {
		this->position = position;
	}

	void set_position(int salary) {
		this->position = position;
	}

	string get_class_name() const {
		return position;
	}

	void print() const {
		employee::print();
		//cout << "Surname: " << surname; //за допомогою protected
		cout << endl << "Position: " << position;
	}
};

class student : public person {
	string class_name;
	int marks[SIZE];

public:
	student() : person() {
		this->class_name = "No set surname";
	}

	student(string name, string surname, int age, string class_name, int* marks)
		: person(name, surname, age) {
		this->class_name = class_name;
		for (int i = 0; i < SIZE; i++)
		{
			this->marks[i] = marks[i];
		}
	}

	double average() {
		int sum = 0;
		for (int i = 0; i < SIZE; i++)
		{
			sum += marks[i];
		}
		return (double)sum / SIZE;
	}

	void set_class_name(string class_name) {
		this->class_name = class_name;
	}

	string get_class_name() const {
		return class_name;
	}

	void print() const {
		person::print();
		cout << "Class_name: " << class_name;
	}
};

class aspirant : public student {
	string diploma_name;
	int diploma_mark;
public:
	aspirant(string name, string surname, int age, string class_name, int* marks, string diploma_name, int diploma_mark)
		:student(name, surname, age, class_name, marks) {

		this->diploma_name = diploma_name;
		this->diploma_mark = diploma_mark;

	}

	bool pass(int mark) {
		return average() + diploma_mark >= mark;
	}

};

//class pensioner : public person {
//	int pension;
//
//public:
//	pensioner(string name, string surname, int age, int salary)
//		: person(name, surname, age) {
//		this->pension = pension;
//	}
//
//	void set_pension(int pension) {
//		this->pension = pension;
//	}
//
//	int get_pension() const {
//		return pension;
//	}
//
//	void print() const {
//		person::print();
//		cout << "Pension: " << pension;
//	}
//};





int main() {
	srand(time(0));

	//employee e("john", "snow", 30, 1000);
	///*e.set_name("john");
	//e.set_surname("snow");
	//e.set_age(30);
	//e.set_salary(1000);*/
	//e.print();

	//line(20);

	//student s("Zombi", "Wsqa", 32, "Gok");
	///*s.set_name("fdseqhn");
	//s.set_surname("snfdow");
	//s.set_age(43);
	//s.set_class_name("MV34");*/
	//s.print();
	//                        
	//line(20);

	///*pensioner p;
	//p.set_name("rewrw");
	//p.set_surname("sada");
	//p.set_age(323);
	//p.set_pension(3200);
	//p.print();*/

	//boss b("GDDS", "hfgh", 54, 8000, "boss");
	//b.print();

	int arr[SIZE] = { 10, 12, 7, 8, 9, 4,10, 5, 12, 12 };

	aspirant a("Danylo", "Lisnichuk", 25, "p45", arr, "C++ Diploma", 10);
	cout << a.pass(18);




	return 0;
}