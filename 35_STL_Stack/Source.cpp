#include <iostream>
#include <windows.h> 
#include <string>
#include <stack>
using namespace std;




int main() {

	stack<int> s1;

	s1.push(10);
	s1.push(30);
	s1.push(60);
	s1.push(80);
	s1.push(100);

	cout << s1.top() << endl;
	s1.pop(); //видаляємо 100
	cout << s1.top() << endl;
	s1.empty();

	cout << endl;

	stack<int> s2;
	s2.push(900);
	s2.push(43);

	s1.swap(s2); //обмін значеннями між двома стеками
	cout << s1.top() << endl;
	cout << s2.top() << endl; 

	return 0;
}