#include<iostream>
#include<string>
#include<vector>
using namespace std;

// STL(Standart Template Library)

// vector
// list
// queue
// stack
// map, multi_map, set, multi_set

// контейнер
// ітератори - це сутності які потрібні для взаємодії з елементами та меодами контейнера
// алгоритми
// функтори

template<class T>
void print_vector(vector<T> v) {
	for (T el : v) {
		cout << el << " ";
	}
	cout << "\n";
}

//void print_vector(vector<int> v) {
//	//for (int element : v) { //rage-based loop
//	//	cout << element << " ";
//	//}
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//}

template<class T>
class my_vector : public vector<T> {

public:
	void print_vector() {
		for (int i = 0; i < this->size(); i++)
		{
			cout << (*this)[i] << " ";
		}
	}
};


class point {
	int x, y;
public:
	point() {
		x = y = 0;
	}

	point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	friend ostream& operator << (ostream& os, const point& obj);
};


ostream& operator << (ostream& os, const point& obj) {
	os << "x = " << obj.x << ", " << "y = " << obj.y << "\n";
	return os;
}



int main() {
	//ІТЕРАТОР
	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	int i = 0;
	for (vector<int>::iterator it = v.begin(); i < v.size(); i++) {
		cout << *(it + i) << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	cout << *(it + 3) << endl;*/

	//ІТЕРАТОР КОНСТАНТНИЙ - тільки для щитвання данних.
	/*for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;*/


	//VECTOR базові методи:
	/*vector<int> v = { 10, -3, 0, 4, 11, 3, 9 };

v.push_back(100);
print_vector(v);
cout << endl;

v[3] = 100;
print_vector(v);
cout << endl;

v.pop_back();
print_vector(v);
cout << endl;

my_vector<int> v2;
v2.push_back(423);
cout << endl;*/

	//VECTOR (advance, distance, insert)
	/*vector<int> v = { 10, -3, 0, 4, 11, 3, 9 };
	vector<int>::iterator it = v.begin();
	advance(it, 5);
	cout << distance(v.begin(), it);

	it += 5;
	v.insert(it, 500);

	v.insert(v.begin() + 5, 500);
	print_vector(v);
	cout << endl;

	v.erase(v.begin() + 3);
	print_vector(v);*/

	//VECTOR String
	/*vector<string> countries = { "USA", "Ukraine", "France", "Spain", "Germany" };

	vector<string>::iterator it = countries.begin();

	countries.insert(it, "Italy");

	print_vector(countries);*/

	//VECTOR point
	/*vector<point> points = { point(1, 2), point(4, 5), point(4, 6) };
	print_vector(points);*/


	//Завдання - 1
	/*vector<int> v;
	for (int i = 1; i <= 10; i++)
	{
		v.push_back(pow(i, 2));
	}
	print_vector(v);
	cout << endl;*/

	//Звдання - 2 (двовимірний вектор)
	int rows = 10, cols = 10;
	vector<vector<int>> v(rows);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			v[i].push_back((i + 1) * (j + 1));
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}