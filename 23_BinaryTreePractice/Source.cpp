#include <iostream>
#include <windows.h> // Sleep
#include <string>
using namespace std;

// ������� ������ - �� ���, ��� ���������� �� �����,
// ����� � ���� ��� ����� ������ ��������� �� ������� ����� �����
// � ����:
// - ��������� �� ����� �������
// - ��������� �� ������� �������
// - ��������� �� ������

// �������� �������� �������� ������:
// ������ ������� ������������ � ����� ������.
// ���� ��������� ������� ������ �� ���������,
// �� �� ������������ � ����� ����,
// ���� ������, �� � ���


class bus {
	string number;
	string name;
	string surname;
	string route;
	int number_of_seats;

public:
	bus() {
		string number = "Not set data";
		string name = "Not set data";
		string surname = "Not set data";
		string route = "Not set data";
		int number_of_seats = 0;
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
		element* ptr = nullptr, * tmp = root;

		while (tmp) { 
			ptr = tmp;
			if (node->data.get_number() < tmp->data.get_number())
				tmp = tmp->right;
			else
				tmp = tmp->right;
		}

		if (ptr == nullptr) {
			root = node;
		}
		else if (node->key < ptr->key)
			ptr->left = node;
		else
			ptr->right = node;

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


	element* search(element* node, int key) {
		while (node && node->key != key) {
			if (key < node->key)
				node = node->left;
			else
				node = node->right;
		}
		return node;
	}


	void print(element* node) const {
		if (node) { //if(node != nullptr)
			print(node->left);
			cout << node->key << " "; //����� �������������� cout a�� �������� print ���� bus ��� ������
			print(node->right);
		}
	}

	element* get_root() const {
		return root;
	}
};



int main() {
	srand(time(0));


	bus busOne(); //������� �������� ��� ���� (����� �������� ����������� ��� ���������� ������ � ���� bus).

	tree t;
	t.insert(busOne);
	

	return 0;
}