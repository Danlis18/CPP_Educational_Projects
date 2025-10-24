#include <iostream>
#include <windows.h> 
#include <string>
#include <map>
using namespace std;




int main() {
	map<int, string> m; //створюємо об'єкт m типу map, де ключем є ціле число, а значенням - рядок.

	pair<int, string> p1 = make_pair(1, "One"); //створюємо пару p1 з ключиком 1 і значенням "One".

	m.insert(p1); //додаємо елемент з ключиком 1 і значенням "One".
	m.insert(make_pair(2, "Two")); //додаємо елемент з ключиком 2 і значенням "Two".

	m.insert({ 5, "Wellcom" }); //доступаємося до елемента з ключикоам 5 і йому приствоється значення "Wellcom".
	m[4] = "Four"; //доступаємося до елемента з ключикоам 4 і йому приствоється значення "Four".

	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
		cout << it->first << " : " << it->second << endl; //first - ключ, second - значення
	}

	/*m.erase(5);*/ //видаляємо елемент з ключиком 5.

	/*cout << endl;
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}*/


	/*cout << m[4] << endl;
	m.find(5);*/ //шукаємо елемент з ключиком 5.

	/*auto it = m.find(5);*/ //шукаємо елемент з ключиком 2.
	/*if (it != m.end()) 
		cout << it->first << " : " << it->second << endl;
	else
		cout << "Not found!" << endl;*/


	map<string, double> employees{ //створюємо об'єкт employees типу map, де ключем є рядок, а значенням - число з плаваючою крапкою.
		{"John", 4500.50},
		{"Alice", 5200.75},
		{"Bob", 3900.00},
	};

	cout << "Your salary: " << employees["Alice"] << endl; //виводимо на екран значення, яке відповідає ключику "Alice".


    return 0;
}