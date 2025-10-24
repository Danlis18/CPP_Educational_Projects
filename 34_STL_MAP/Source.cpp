#include <iostream>
#include <windows.h> 
#include <string>
#include <map>
using namespace std;




int main() {
	map<int, string> m; //��������� ��'��� m ���� map, �� ������ � ���� �����, � ��������� - �����.

	pair<int, string> p1 = make_pair(1, "One"); //��������� ���� p1 � �������� 1 � ��������� "One".

	m.insert(p1); //������ ������� � �������� 1 � ��������� "One".
	m.insert(make_pair(2, "Two")); //������ ������� � �������� 2 � ��������� "Two".

	m.insert({ 5, "Wellcom" }); //����������� �� �������� � ��������� 5 � ���� ����������� �������� "Wellcom".
	m[4] = "Four"; //����������� �� �������� � ��������� 4 � ���� ����������� �������� "Four".

	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
		cout << it->first << " : " << it->second << endl; //first - ����, second - ��������
	}

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


	map<string, double> employees{ //��������� ��'��� employees ���� map, �� ������ � �����, � ��������� - ����� � ��������� �������.
		{"John", 4500.50},
		{"Alice", 5200.75},
		{"Bob", 3900.00},
	};

	cout << "Your salary: " << employees["Alice"] << endl; //�������� �� ����� ��������, ��� ������� ������� "Alice".


    return 0;
}