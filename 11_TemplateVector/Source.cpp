#include <iostream>
#include <windows.h> // Sleep
using namespace std;


void line(int count) {
    cout << "\n";
    for (int i = 0; i < count; i++)
        cout << "-";
    cout << "\n";
}

class Menu {
public:
    int show() {
        cout << "0 - Exit\n";
        cout << "1 - Add End\n";
        cout << "2 - Add Start\n";
        cout << "3 - Add Position\n";
        cout << "4 - Delete End\n";
        cout << "5 - Delete Start\n";
        cout << "6 - Delete Position\n";
        cout << "7 - Delete Search Element\n";
        cout << "8 - Delete Elements From Position\n";
        cout << "9 - Delete All Array\n";
        cout << "10 - Change element by value\n";
        cout << "11 - Change element by position\n";
        cout << "12 - Reverse\n";
        cout << "13 - Generate rondom array\n";
        cout << "14 - Info Size\n";
        cout << "15 - Info Min\n";
        cout << "16 - Info Max\n";
        cout << "17 - Info Index\n";
        cout << "18 - Sort Ascending\n";
        cout << "19 - Sort Descending\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        return choice;
    }
};

template<class T>
class vector {
private:
    T* data;
    int size;

public:
    vector() {
        data = nullptr;
        size = 0;
    }

    vector(const vector<T>& other) {
        this->data = new T[other.size];
        this->size = other.size;

        for (int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
            // *(this->data + i) = *(other.data + i);
        }
    }

    void print_v() const {
        line(100);
        for (int i = 0; i < size; i++)
            cout << *(data + i) << " ";
        line(100);
    }

    void add_element_start(T number) {
        T* p = new T[size + 1];

        for (int i = 1; i < size + 1; i++)
            *(p + i) = *(data + i - 1);

        p[0] = number;

        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    void add_element_end(T number) {
        T* p = new T[size + 1];

        for (int i = 0; i < size; i++)
            *(p + i) = *(data + i);

        p[size] = number;
        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    void add_element_need(int wher, T number) {
        T* p = new T[size + 1];

        for (int i = 0; i < wher; i++) {
            p[i] = data[i];
        }

        p[wher] = number;

        for (int i = wher; i < size; i++) {
            p[i + 1] = data[i];
        }

        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    void deletee_element_last() {
        size--;
        int* p = new int[size];

        for (int i = 0; i < size; i++) {
            p[i] = data[i];
        }

        delete[] data;
        data = p;
        p = nullptr;
    }

    void deletee_element_first() {
        size--;
        int* p = new int[size];

        for (int i = 0; i < size; i++) {
            p[i] = data[i + 1];
        }

        delete[] data;
        data = p;
        p = nullptr;
    }

    void delete_element_position(int position) {
        int* p = new int[size - 1];

        for (int i = 0, j = 0; i < size; i++) {
            if (i != position) {
                p[j++] = data[i];
            }
        }

        delete[] data;
        data = p;
        size--;
        p = nullptr;
    }

    int search_element_position(int element) {
        for (int i = 0; i < size; i++)
            if (data[i] == element)
                return i;
        return -1;
    }

    void delete_search_element(int element) {
        int position = search_element_position(element);
        if (position != -1)
            delete_element_position(position);
        else {
            cout << "Element not found";
            Sleep(3000);
        }
    }

    void delete_elements_from_position(int count, int position) {
        for (int i = 0; i < count; i++)
            delete_element_position(position);
    }

    void delete_array() {
        delete[] data;
        data = nullptr;
        size = 0;
    }

    void change_element_by_value(int number, int change_number) {
        int position = search_element_position(number);
        if (position != -1)
            data[position] = change_number;
        else {
            cout << "Not found";
            Sleep(2000);
        }
    }

    void change_element_by_position(int position, int change_number) {
        data[position] = change_number;
    }

    void reverse_array() {
        for (int i = 0; i < size / 2; i++) {
            swap(data[i], data[size - i - 1]);
        }
    }

    int get_max() {
        if (size == 0) {
            cout << "Array is empty\n";
            Sleep(2000);
            return 0;
        }
        int max_val = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] > max_val)
                max_val = data[i];
        return max_val;
    }

    int get_min() {
        if (size == 0) {
            cout << "Array is empty\n";
            Sleep(2000);
            return 0;
        }
        int min_val = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] < min_val)
                min_val = data[i];
        return min_val;
    }

    int get_size() const {
        return size;
    }

    int get_element(int index) {
        if (index < 0 || index >= size) {
            cout << "Incorrect index!\n";
            Sleep(2000);
            return 0;
        }
        return data[index];
    }

    void sort_asc() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1])
                    swap(data[j], data[j + 1]);
            }
        }
    }

    void sort_desc() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] < data[j + 1])
                    swap(data[j], data[j + 1]);
            }
        }
    }

    void print() {
        line(100);
        for (int i = 0; i < size; i++)
            cout << *(data + i) << " ";
        line(100);
    }

    void print_info_max() {
        cout << "\n======= ARRAY INFO =======\n";

        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Max element: " << get_max() << endl;
        Sleep(3000);
    }

    void print_info_min() {
        cout << "\n======= ARRAY INFO =======\n";

        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Min element: " << get_min() << endl;
        Sleep(3000);
    }

    void print_info_size() {
        cout << "\n======= ARRAY INFO =======\n";

        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Size: " << size << endl;
        Sleep(3000);
    }

    void print_info_index() {
        if (size == 0) {
            cout << "Array is empty!\n";
            Sleep(2000);
            return;
        }
        cout << "\n======= ARRAY INFO =======\n";
        int index;
        cout << "Enter index: ";
        cin >> index;

        int value = get_element(index);
        cout << "Element at index " << index << " is: " << value << endl;
        Sleep(3000);
    }




    vector<T> operator=(const vector<T>& other) {
        if (this == &other)
            return *this;

        if (this->data) {
            delete[] this->data;
        }
        this->data = new T[other.size];

        for (int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
        }
        this->size = other.size;

        return *this;
    }

    //int& get_element_by_index(unsigned int index) {
    //    if (index >= size)
    //        throw exception("index out of range");
    //    return data[index];
    //}

    vector<T>& operator[](unsigned int index) {
        if (index >= size)
            throw exception("index out of range");

        return data[index];
    }




    ~vector() {
        delete[] data;
    }
};

template<class T>
ostream& operator<< (ostream& os, const vector<T>& obj) {
    obj.print_v();
    return os;
}

template<class T>
istream& operator>> (istream& is, vector<T>& obj) {
    obj.set_random(10);
    return is;
}


template<class T>
class point {
    T x, y, z;
public:
    point(T x, T y, T z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void print() const {
        cout << "X: " << x << "Y: " << y << "Z: " << x << "\n";
    }

};

template<class T>
ostream& operator<< (ostream& os, const point<int>& obj) {
    obj.print();
    return os;
}



int main() {
    setlocale(LC_CTYPE, "ukr");
    srand(time(0));

    vector<point<float>> points;
    points.add_element_end(point<float>(3.5, 4, 6));
    points.add_element_end(point<float>(9, 3.7, 6));
    points.add_element_end(point<float>(-3.8, 1, 6));
    points.add_element_end(point<float>(-11.9, 4, 6));
    points.add_element_end(point<float>(7, 1.8, 6));
    points.print();

    /*vector<int> v;
    Menu m;
    int a, b;

    do {
        system("cls");
        v.print();
        int choice = m.show();
        if (!choice) break;

        switch (choice) {
        case 1:
            cout << "Enter number: "; cin >> a;
            v.add_element_end(a);
            break;
        case 2:
            cout << "Enter number: "; cin >> a;
            v.add_element_start(a);
            break;
        case 3:
            cout << "Enter position: "; cin >> a;
            cout << "Enter number: "; cin >> b;
            v.add_element_need(a, b);
            break;
        case 4:
            v.deletee_element_last();
            break;
        case 5:
            v.deletee_element_first();
            break;
        case 6:
            cout << "Enter position: "; cin >> a;
            v.delete_element_position(a);
            break;
        case 7:
            cout << "Enter element: "; cin >> a;
            v.delete_search_element(a);
            break;
        case 8:
            cout << "Enter count: "; cin >> a;
            cout << "Enter position: "; cin >> b;
            v.delete_elements_from_position(a, b);
            break;
        case 9:
            v.delete_array();
            break;
        case 10:
            cout << "Enter number to find: "; cin >> a;
            cout << "Enter new value: "; cin >> b;
            v.change_element_by_value(a, b);
            break;
        case 11:
            cout << "Enter position: "; cin >> a;
            cout << "Enter new value: "; cin >> b;
            v.change_element_by_position(a, b);
            break;
        case 12:
            v.reverse_array();
            break;
        case 13:
            cout << "Enter array size: "; cin >> b;
            v.set_random(b);
            break;
        case 14:
            v.print_info_size();
            break;
        case 15:
            v.print_info_min();
            break;
        case 16:
            v.print_info_max();
            break;

        case 17:
            v.print_info_index();
            break;
        case 18:
            v.sort_asc();
            break;
        case 19:
            v.sort_desc();
            break;
        default:
            cout << "Incorrect input!\n";
            Sleep(2000);
            break;
        }
    } while (true);*/

    /*vector v1(10);
    v1.print_v();

    vector v2(100);
    v1 = v2;
    v2.print_v();*/

    //vector v3;
    //v3.print();

    ///*cout << v3.get_element_by_index(2);
    //v3[3] = 1000;
    //v3.print();*/

    //cout << v3;
    //cin >> v3;
    //cout << v3;

    return 0;
}