#include <iostream>
#include <windows.h> 
#include <string>
#include <map>
#include <windows.h> // ������� ��� SetConsoleCP �� SetConsoleOutputCP
using namespace std;




int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);


	map<string, string> dictionary{
		{"book", "�����"},
		{"pen", "�����"},
		{"notebook", "�����"},
		{"pencil", "������"},
	};

	for (map<string, string>::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}

	string search_key;
	cout << "������ �����, ��� ������: ";
	cin >> search_key;
	dictionary.find(search_key);
	auto it = dictionary.find(search_key);
	cout << it->first << " : " << it->second << endl;

	//m.insert(p1); //������ ������� � �������� 1 � ��������� "One".
	//m.insert(make_pair(2, "Two")); //������ ������� � �������� 2 � ��������� "Two".

	//m.insert({ 5, "Wellcom" }); //����������� �� �������� � ��������� 5 � ���� ����������� �������� "Wellcom".
	//m[4] = "Four"; //����������� �� �������� � ��������� 4 � ���� ����������� �������� "Four".

	//for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
	//	cout << it->first << " : " << it->second << endl; //first - ����, second - ��������
	//}

	/*m.erase(5);*/ //��������� ������� � �������� 5.

	/*cout << endl;
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}*/


	/*cout << m[4] << endl;
	m.find(5);*/ //������ ������� � �������� 5.

	/*auto it = m.find(5);*/ //������ ������� � �������� 2.
	/*if (it != m.end())
		cout << it->first << " : " << it->second << endl;
	else
		cout << "Not found!" << endl;*/


	return 0;
}