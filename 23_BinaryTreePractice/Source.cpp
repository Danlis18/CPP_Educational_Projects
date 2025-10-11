#include <iostream>
#include <windows.h> // Sleep
#include <string>
using namespace std;


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

	bus(string n, string na, string s, string r, int nos) {
		number = n;
		name = na;
		surname = s;
		route = r;
		number_of_seats = nos;
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

	void print_num()const {
		cout << "Number: " << number << endl;
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


	/*element* search(element* node, int key) {
		while (node && node->data.get_number() != key) {
			if (key < node->data.get_number())
				node = node->left;
			else
				node = node->right;
		}
		return node;
	}*/


	void print(element* node) const {
		if (node) {
			print(node->left);
			node->data.print_num();
			print(node->right);
		}
	}


	element* get_root() const {
		return root;
	}
};



int main() {
	srand(time(0));


	bus busOne("AS32", "Danylo", "Lisnichuk", "Route233", 321); //передаю елементи для баса (треба дописати конструктор для заповнення данних в класі bus).

	tree t;
	t.insert(busOne);
	t.print(t.get_root());
	

	return 0;
}