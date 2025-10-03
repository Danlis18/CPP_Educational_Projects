#include <iostream>
using namespace std;

//Template Functions (шаблонні функції) - це шаблон у який можна підставити любий однаковий тип данних

template<class T>
T sum(T a, T b) {
    return a + b;
}

template<class R>
R sum_r(R* arr, const int size) {
    R sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    const int size = 5;
    int arr1[size] = {3, 1, 5, 2, 7};
    double arr2[size] = { 3.4, 1.1, 5.0, 2.9, 7.5 };
    int res1 = sum_r(arr1, size);
    double res2 = sum_r(arr2, size);
    cout << res1 << " | " << res2;


    int res = sum(4, 1);
    //cout << res;

    return 0;
}