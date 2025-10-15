#include <iostream>
#include <windows.h> // Sleep
#include <string>
using namespace std;


int menu() {
	cout << "0 - Stop program \n";
	cout << "1 - Add new bus \n";
	cout << "2 - Search by bus number\n";
	cout << "3 - Display all buses\n";

	int choice;
	cout << endl << "Enter your choice: ";
	(cin >> choice).get();
	return choice;
}

void line(int count) {
	cout << "\n";
	for (int i = 0; i < count; i++)
		cout << "-";
	cout << "\n";
}



class bus {
	string number;
	string name;
	string surname;
	string route;
	int number_of_seats;

public:
	bus() {
		number = "NoNumber";
		name = "NoName";
		surname = "NoSurname";
		route = "NoRoute";
		number_of_seats = 0;
	}

	bus(string number, string name, string surname, string route, int number_of_seats) {
		this->number = number;
		this->name = name;
		this->surname = surname;
		this->route = route;
		this->number_of_seats = number_of_seats;
	}

	void set() {
		cout << "Number: ";
		cin >> number;
		cout << "Name: ";
		cin >> name;
		cout << "Surname: ";
		cin >> surname;
		cout << "Route: ";
		cin >> route;
		cout << "Mumber of seats: ";
		cin >> number_of_seats;
	}

	void print() const {
		cout << "Number: " << number << "\nName: " << name
			<< "\nSurname: " << surname << "\nRoute: " << route
			<< "\nSeats: " << number_of_seats << "\n";
	}

	string get_number() {
		return number;
	}
};

struct element {
	bus data;
	element* left, * right, * perent;

	element() {
		left = right = perent = nullptr;
	}
};

class tree {
	element* root;
	int count;

public:
	tree() {
		root = nullptr;
		count = 0;
	}

	void insert(bus data) {
		element* node = new element;
		node->data = data;
		element* ptr = nullptr;
		element* tmp = root;

		// Пошук місця вставки
		while (tmp != nullptr) {
			ptr = tmp;
			if (node->data.get_number() < tmp->data.get_number())
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}

		node->perent = ptr;

		if (ptr == nullptr) {
			root = node;  // перший елемент
		}
		else if (node->data.get_number() < ptr->data.get_number()) {
			ptr->left = node;
		}
		else {
			ptr->right = node;
		}

		count++;
	}



	element* minimum(element* node) const {

		if (node) {
			while (node->left) {
				node = node->left;
			}
		}
		return node;
	}

	element* maximum(element* node) const {
		if (node) {
			while (node->right) {
				node = node->right;
			}
		}

		return node;
	}


	element* search(const string& key) {
		element* current = root;
		while (current && current->data.get_number() != key) {
			if (key < current->data.get_number())
				current = current->left;
			else
				current = current->right;
		}
		return current;
	}


	void print_all(element* node) const {
		if (node) {
			print_all(node->left);
			node->data.print();
			line(30);
			print_all(node->right);
		}
	}



	element* get_root() const {
		return root;
	}
};



int main() {
	setlocale(LC_CTYPE, "ukr");

	tree t;

	int finish = 0;

	do {
		system("cls");
		cout << "-- Bus System Menu --";
		line(50);

		int choice = menu();
		if (choice == 0) break;

		switch (choice) {
		case 1: {
			bus b;
			b.set();
			t.insert(b);
			cout << "Bus added successfully!\n";
			Sleep(1500);
			break;
		}
		case 2: {
			string number;
			cout << "Enter bus number to search: ";
			cin >> number;
			element* found = t.search(number);
			if (found) {
				cout << "Bus found:\n";
				found->data.print();
			}
			else {
				cout << "Bus with number " << number << " not found.\n";
			}
			system("pause");
			break;
		}
		case 3:
			cout << "All buses:\n";
			line(30);
			t.print_all(t.get_root());
			system("pause");
			break;
		default:
			cout << "Incorrect input!";
			Sleep(1500);
			break;
		}

	} while (!finish);

	system("cls");
	cout << "Program terminated. Bye!\n";

	return 0;
}