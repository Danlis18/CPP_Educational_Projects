#include<iostream>
#include<string>
#include<list>
using namespace std;


//LIST


void print_list(list<int> l) {
	for (int el : l)
	{
		cout << el << " ";
	}
}

int main() {
	srand(time(0));

	/*list<int> l = { 4, 5, 6, 3, 23, 23, 8 };
	l.push_back(432);
	l.push_front(100);
	l.pop_back();
	l.pop_front();
	l.clear();

	list<int>::iterator it = l.begin();

	advance(it, 5);
	l.insert(it, 10);
	print_list(l);

	cout << endl;
	advance(it, 1);
	l.erase(it);
	print_list(l);

	cout << endl;
	l.reverse();
	print_list(l);

	cout << endl;
	l.sort();
	print_list(l);*/



	list<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(rand() % 10);
	}

	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;


	return 0;
}