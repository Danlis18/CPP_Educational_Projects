#include <iostream>
using namespace std;

void line(int count) {
    cout << "\n";
    for (int i = 0; i < count; i++)
        cout << "-";
    cout << "\n";
}

class my_string {
private:
    char* str;
    int length;

    void copy_str(const char* str) {
        this->length = strlen(str);
        this->str = new char[this->length + 1];

        for (int i = 0; i < this->length; i++)
        {
            this->str[i] = str[i];
        }
        this->str[this->length] = '\0';
    }

public:
    my_string() {
        this->str = nullptr;
        this->length = 0;
    }

    my_string(const char* str) {
        copy_str(str);
    }

    my_string(const my_string& other) {
        copy_str(other.str);
    }

    void print()const {
        cout << str << endl;
    }


    int get_length() const {
        return length;
    }

    char* get_str() const {
        return str;
    }

    void set() {
        cin >> str;
    }

    ~my_string() {
        delete[] str;
    }
};


int main() {
 
    my_string s1("Hello World");
    s1.print();

    my_string s2 = s1;
    s2.print();

    return 0;
}