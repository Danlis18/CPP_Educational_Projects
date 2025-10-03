#include <iostream>
using namespace std;
#define TRAIN_NUM 100
#define TRAIN_NAME 100

void line(int count) {
    cout << "\n";
    for (int i = 0; i < count; i++)
        cout << "-";
    cout << "\n";
}

class train {

private:
    char* train_number;
    char* train_name;
    int* carriage;
    int count_carriage;

public:
    train() {
        train_number = new char[TRAIN_NUM];
        train_name = new char[TRAIN_NAME];
        carriage = nullptr;
        count_carriage = 0;
    }

    train(const train& other) {
        this->train_number = new char[strlen(other.train_number) + 1];
        strcpy_s(this->train_number, strlen(other.train_number) + 1, other.train_number);

        this->train_name = new char[strlen(other.train_name) + 1];
        strcpy_s(this->train_name, strlen(other.train_name) + 1, other.train_name);

        this->carriage = new int[other.count_carriage];
        this->count_carriage = other.count_carriage;

        for (int i = 0; i < count_carriage; i++) {
            this->carriage[i] = other.carriage[i];
        }
    };

    void set() {
        cout << "--Set Train--" << endl;
        cout << "Entre Train Number: ";
        gets_s(train_number, TRAIN_NUM);
        cout << "Entre Train Name: ";
        gets_s(train_name, TRAIN_NAME);

        cout << "Entre Number Of Carriages: ";
        (cin >> count_carriage).get();
        carriage = new int[count_carriage];

        for (int i = 0; i < count_carriage; i++)
        {
            carriage[i] = rand() % 101;
        }
    }

    void print() {
        line(100);
        cout << "--Print Train--" << endl;
        cout << "Train Number: " << train_number << endl;
        cout << "Train Name: " << train_name << endl;
        cout << "Number Of Carriages: " << count_carriage << endl;
        for (int i = 0; i < count_carriage; i++)
        {
            cout << "Number Of People in Carriage - " << i + 1 << ": " << carriage[i] << endl;
        }
        cout << "Max people in carriage - " << max_people() << endl;
        cout << "Min people in carriage - " << min_people() << endl;
        cout << "Sum people in train - " << sum_people();
        line(100);
    }

    int get_count_carriage() {
        return count_carriage;
    }

    int max_people() {
        int max_index = 0;
        int max = carriage[0];
        for (int i = 1; i < count_carriage; i++) {
            if (carriage[i] > max) {
                max = carriage[i];
                max_index = i;
            }
        }
        return max_index + 1;
    }

    int min_people() {
        int min_index = 0;
        int min = carriage[0];

        for (int i = 1; i < count_carriage; i++) {
            if (carriage[i] < min) {
                min = carriage[i];
                min_index = i;
            }
        }
        return min_index + 1;
    }

    int sum_people() {
        int sum_index = 0;
        int sum = carriage[0];

        for (int i = 0; i < count_carriage; i++) {
            sum = carriage[i];
            sum_index += sum;
        }
        return sum_index;
    }


    ~train() {
        delete[] train_number;
        delete[] train_name;
        delete[] carriage;
    }
};

int max_people_train(train* trains, int count) {
    int max_index = 0;
    int max = trains[0].sum_people();
    for (int i = 1; i < count; i++) {
        if (trains[i].sum_people() > max) {
            max = trains[i].sum_people();
            max_index = i;
        }
    }
    return max_index + 1;
}

int min_people_train(train* trains, int count) {
    int min_index = 0;
    int min = trains[0].sum_people();

    for (int i = 1; i < count; i++) {
        if (trains[i].sum_people() < min) {
            min = trains[i].sum_people();
            min_index = i;
        }
    }
    return min_index + 1;
}


int main() {
    setlocale(LC_CTYPE, "ukr");
    srand(time(0));

    int n;
    cout << "Value of trains: ";
    (cin >> n).get();
    cout << endl;

    train* trains = new train[n];
    for (int i = 0; i < n; i++) {
        trains[i].set();
        trains[i].print();
    }
    cout << "Max people in train - " << max_people_train(trains, n) << endl;
    cout << "Min people in train - " << min_people_train(trains, n) << endl;
    delete[] trains;

    //êîï³þº
   /* train t2 = t1;
    t2.print();*/

    return 0;
}