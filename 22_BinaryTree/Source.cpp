#include <iostream>
#include <windows.h> // Sleep
#include <string>
using namespace std;

// Бінарне дерево - це ДСД, яка складається із вузлів,
// кожен з яких крім даних містить посилання на декілька інших вузлів
// а саме:
// - посилання на лівого нащадка
// - посилання на правого нащадка
// - посилання на предка

// Алгоритм побудови бінарного дерева:
// Перший елемент вставляється в корінь дерева.
// Якщо наступний елемент більший за попередній,
// то він вставляється в праву гілку,
// якщо менший, то в ліву

struct element {
	int key;
	element* left, * right, * perent;

	element() {
		key = 0;
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

	void insert(int key) {
		element* node = new element;
		node->key = key;
		element* ptr = nullptr, * tmp = root;

		while (tmp) { //шукали батьківський елемент цим циклом.
			ptr = tmp;
			if (node->key < tmp->key)
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
			cout << node->key << " ";
			print(node->right);
		}
	}

	element* get_root() const {
		return root;
	}
};


int main() {
	srand(time(0));


	tree t;
	t.insert(100);
	t.insert(95);
	t.insert(107);
	t.insert(12);
	t.insert(99);
	t.insert(102);
	t.insert(108);

	t.print(t.get_root());

	element* min = t.minimum(t.get_root());
	if (min)
		cout << endl << "Min: " << min->key;
	else
		cout << "No elements";

	element* max = t.maximum(t.get_root());
	if(max)
		cout << endl << "Max: " << max->key;
	else
		cout << "No elements";


	element* result = t.search(t.get_root(), 95);
	if (result) {
		cout << endl << "RES: " << result->key;
	}
	else {
		cout << "Not found";
	}

	return 0;
}