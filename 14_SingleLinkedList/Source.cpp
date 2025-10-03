#include <iostream>
using namespace std;


//������� ��������� �����(���) - �� ��������� ������, ���'��� ��� ���� ������������ �� �����������.
// 
//Vector - �� ����� ������ 
//������(������'����� - �� ����� ��'����, �����'�����)
//����
//�����(������, ʳ������, ����� � ���������, ���)
//������(������� ������)


//������'����� ������ - �� ��� � ����� ����� ����������� �� ��������, �� ������ ����� ���������� � �������� �� ����� �������
struct element {
    int data;
    element* next = nullptr;
};

class list {
    element* head, * tail;
    int size;

public:
    list() {
        head = tail = nullptr;
        size = 0;
    }

    void add_head(int value) {
        element* new_element = new element;
        new_element->data = value;

        if (size == 0) {
            head = tail = new_element;
        }
        else {
            new_element->next = head;
            head = new_element;
            new_element = nullptr;
        }
        size++;
    }

    void add_tail(int value) {
        element* new_element = new element;
        new_element->data = value;

        if (size == 0) {
            head = tail = new_element;
        }
        else {
            tail->next = new_element;
            tail = new_element;
            new_element = nullptr;
        }
        size++;
    }

    void print() const{
        element* tmp = head;

        while (tmp)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }
};



int main() {

    list l;
    l.add_head(100);
    l.add_head(43);
    l.add_head(540);
    l.add_head(109);
    l.add_tail(888);
    l.print();


    return 0;
}