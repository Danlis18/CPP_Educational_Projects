#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>   // for system("cls")
#include <thread>    // for sleep
#include <chrono>    // for chrono::seconds
using namespace std;

void line(int count) {
	cout << "\n";
	for (int i = 0; i < count; i++)
		cout << "-";
	cout << "\n";
}

struct my_time {
	int hour;
	int min;
	int seconds;
public:
	my_time() {
		hour = 0;
		min = 0;
		seconds = 0;
	}

	my_time(int hour, int min, int seconds) {
		this->hour = hour;
		this->min = min;
		this->seconds = seconds;
	}

	void set_my_time() {
		cout << "Enter hour: ";
		cin >> hour;
		cout << "Enter min: ";
		cin >> min;
		cout << "Enter seconds: ";
		cin >> seconds;
	}

	void print_time() const {
		cout << (hour < 10 ? "0" : "") << hour << ":"
			<< (min < 60 ? "0" : "") << min << ":"
			<< (seconds < 60 ? "0" : "") << seconds;
	}
};

class train {
	string number;
	my_time timeDeparture;
	string arivalStation;

public:
	train() {
		string number = "None";
		string arivalStation = "None";
	}

	train(string number, string arivalStation, my_time timeDeparture) {
		this->number = number;
		this->arivalStation = arivalStation;
		this->timeDeparture = timeDeparture;
	}

	void set_train() {
		cout << "Enter train number: ";
		cin >> number;

		cout << "Enter arrival station: ";
		cin >> arivalStation;

		timeDeparture.set_my_time();
	}

	void print_train() const {
		cout << "Train Number: " << number << endl;
		cout << "Arrival Station: " << arivalStation << endl;
		cout << "Departure Time: ";
		timeDeparture.print_time();
		cout << endl;
	}

	string get_number() const {
		return number;
	}
};

class trainSystem {
	vector<train> trains;
public:
	trainSystem() {
		trains = vector<train>();
	}

	void add_train(const train& t) {
		trains.push_back(t);
	}

	void remove_train(const string& train_number) {
		for (auto it = trains.begin(); it != trains.end(); ++it) {
			if (it->get_number() == train_number) {
				trains.erase(it);
				break;
			}
		}
	}

	void find_train(const string& train_number) const {
		for (const auto& t : trains) {
			if (t.get_number() == train_number) {
				t.print_train();
				return;
			}
		}
		cout << "Train with number " << train_number << " not found." << endl;
	}

	void print_all_trains() const {
		for (const auto& t : trains) {
			t.print_train();
			line(20);
		}
	}
};

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>     // system("cls")
#include <windows.h>   // Sleep()

using namespace std;

// Your classes (train, my_time, trainSystem, line) should be above this

void menu(trainSystem& sys) {
	int choice;

	while (true) {
		system("cls"); // Clear screen
		cout << "===== TRAIN SYSTEM MENU =====\n"
			<< "1. Enter data into the system\n"
			<< "2. Display information about all trains\n"
			<< "3. Display information about a specific train\n"
			<< "4. Add a new train\n"
			<< "0. Exit\n"
			<< "Your choice: ";
		cin >> choice;
		line(30);

		switch (choice) {
		case 1: {
			int n;
			cout << "How many trains to add: ";
			cin >> n;
			for (int i = 0; i < n; ++i) {
				cout << "\n--- Train " << (i + 1) << " ---\n";
				train t;
				t.set_train();
				sys.add_train(t);
			}
			cout << "Data entry completed.\n";
			break;
		}
		case 2: {
			cout << "All trains in the system:\n";
			line(20);
			sys.print_all_trains();
			break;
		}
		case 3: {
			cout << "Enter train number to search: ";
			string num;
			cin >> num;
			line(20);
			sys.find_train(num);
			break;
		}
		case 4: {
			cout << "Adding a new train:\n";
			train t;
			t.set_train();
			sys.add_train(t);
			cout << "Train added successfully.\n";
			break;
		}
		case 0:
			cout << "Exiting...\n";
			Sleep(2000); // 2000 milliseconds = 2 seconds
			return;
		default:
			cout << "Invalid choice. Please try again.\n";
		}

		line(30);
		cout << "Returning to menu in 3 seconds...\n";
		Sleep(3000); // 3 seconds
	}
}

int main() {
	trainSystem sys;
	menu(sys);
	return 0;
}
