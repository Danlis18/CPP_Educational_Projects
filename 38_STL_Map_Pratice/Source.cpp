#include <iostream>
#include <windows.h> 
#include <string>
#include <map>
#include <windows.h> // Потрібно для SetConsoleCP та SetConsoleOutputCP
using namespace std;




int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);


	map<string, string> dictionary{
		{"book", "книга"},
		{"pen", "ручка"},
		{"notebook", "зошит"},
		{"pencil", "олівець"},
	};

	for (map<string, string>::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}

	string search_key;
	cout << "Введіть слово, яке шукаєте: ";
	cin >> search_key;
	dictionary.find(search_key);
	auto it = dictionary.find(search_key);
	cout << it->first << " : " << it->second << endl;

	//m.insert(p1); //додаємо елемент з ключиком 1 і значенням "One".
	//m.insert(make_pair(2, "Two")); //додаємо елемент з ключиком 2 і значенням "Two".

	//m.insert({ 5, "Wellcom" }); //доступаємося до елемента з ключикоам 5 і йому приствоється значення "Wellcom".
	//m[4] = "Four"; //доступаємося до елемента з ключикоам 4 і йому приствоється значення "Four".

	//for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
	//	cout << it->first << " : " << it->second << endl; //first - ключ, second - значення
	//}

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


	return 0;
}