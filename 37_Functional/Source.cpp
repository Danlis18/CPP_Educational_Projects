#include <iostream>
#include <functional>
#include <string>
#include <vector>
using namespace std;


void func1() { //��������� ������� - �� ��'� ������� �� ���� �� ��������� � ��� ����������
    cout << "Func1()";
}
void func2() {
    cout << "Func2()";
}

void printVector(const vector<int> v, function<bool(int)> call_bacl) { //�allback function (������� ����������� �������)
	for (int element : v) {
		if (call_bacl(element)) //��� ������� �������� ������� ��������� ������� call_bacl � ���������� �� ���������
            cout << element << " ";
	}
	cout << endl;
}

bool isEven(int n) {
    return n % 2 == 0;
}

bool isOdd(int n) {
    return n % 2 != 0;
}

bool isPos(int n) {
    return n > 0;
}

bool isSimple(int n) {
    if (n < 2) {
        return false;
    }
	for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return false;
	}
	return true;
}


int main() {
	vector<int> v = { 321 ,-2, 43, 40, 50, 3, 5, 11};
	printVector(v, isEven); //�������� ������� �� ���������
    printVector(v, isOdd);
    printVector(v, isPos);
    printVector(v, isSimple);


	/*function<void()> p; //p - �������� �� �������, ��� ����� �� ������ � ����� �� �������
    p = func1;
    //func1();
    p();

    p = func2;
    p();*/



    return 0;
}