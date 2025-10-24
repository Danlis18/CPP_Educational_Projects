#include<iostream>
#include<string>
#include<vector>
using namespace std;


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
};


class trainSystem {
	vector<train> trains;
public:

	void print_trains() {
		train.print_train();
	}
	//вивід всіх поїздів
	//пошук поїзда
	
};


int main() {

	


	return 0;
}