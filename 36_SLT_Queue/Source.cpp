#include <iostream>
#include <windows.h> 
#include <string>
#include <queue>
#include <vector>

using namespace std;


class client {
	string name;
	int age;

public:

	client() {
		name = "Default";
		age = 0;
	}

	client(string name, int age) {
		this->name = name;
		this->age = age;
	}

	int get_age() const {
		return age;
	}

	string get_name() const {
		return name;
	}
};

ostream& operator<<(ostream& os, const client& obj) {
	os << "Name: " << obj.get_name() << ", Age: " << obj.get_age();
	return os;
}
bool operator<(const client& first, const client& second) {
	return first.get_age() < second.get_age();
}


int main() {
	//×ÅÐÃÀ
	/*queue<int> q1;
	q1.push(10);
	q1.push(12);
	q1.push(14);

	cout << q1.front() << endl;
	q1.pop();
	cout << q1.front() << endl;*/

	//×ÅÐÃÀ Ç ÏÐÈÎÐ²ÒÅÒÎÌ
	/*priority_queue<int, vector<int>, greater<int>> pq1;
	pq1.push(10);
	pq1.push(54);
	pq1.push(20);
	pq1.push(14);

	while (!pq1.empty()) {
		cout << pq1.top() << endl;
		pq1.pop();
	}*/


	//×ÅÐÃÀ Ç 10 ÊË²ªÍÒ²Â, îñáëóãîâóâàííÿ çà ïð³îðèòåòîì
	priority_queue<client> pq;

	pq.push(client("Ivan", 34));
	pq.push(client("Vasilia", 21));
	pq.push(client("Petro", 45));
	pq.push(client("Olena", 19));
	pq.push(client("Stepan", 60));


	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}