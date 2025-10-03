#include <string>
#include <iostream>
#include <fstream> 
#include <stdexcept>
#include <windows.h> // Sleep
using namespace std;

string concat_with_space(string str1, string str2) {
	return str1 + " " + str2;
}

class file_utils {
public:
	/**
	 * @brief Зчитує весь вміст файлу в рядок.
	 *
	 * @param file_path Шлях до файлу.
	 * @return std::string Вміст файлу.
	 * @throws std::runtime_error якщо файл не вдалося відкрити.
	 */
	static string read_file_to_string(const string& file_path) {
		ifstream file_stream(file_path);

		if (!file_stream.is_open()) {
			throw runtime_error("Can`t read the string: " + file_path);
		}

		return string((istreambuf_iterator<char>(file_stream)),
			istreambuf_iterator<char>());
	}

	/**
	 * @brief Записує рядок у файл.
	 *
	 * @param file_path Шлях до файлу. Якщо файл існує, його буде перезаписано.
	 * @param content Рядок, який потрібно записати.
	 * @throws std::runtime_error якщо файл не вдалося відкрити для запису.
	 */
	static void write_string_to_file(const string& file_path, const string& content) {
		ofstream file_stream(file_path);

		if (!file_stream.is_open()) {
			throw runtime_error("Can`t open the fail to write: " + file_path);
		}

		file_stream << content;
	}
};

int menu() {
	cout << "1 - show text\n";
	cout << "2 - calculate elements\n";
	cout << "3 - search your word\n";
	cout << "4 - change word to another word\n";
	cout << "5 - dalete word\n";
	cout << "6 - reverse text\n";

	int choice;
	cout << endl << "Enter your choice: ";
	(cin >> choice).get();
	return choice;
}



void reslut_word(string& search, string& text) {
	string search = "all";
	int pos = text.find(search);

	if (pos == -1)
	{
		cout << "Not found!";
	}
	else {
		while (pos != -1) {
			cout << pos << " ";
			text.erase(pos, search.length());
			pos = text.find(search, pos + 1);
		}
	}
	cout << text;
}

int main() {

	/*string s1;
	string s2 = "hello";
	string s3(s2);
	string s4(100, '*');
	cout << s4;*/


	/*string str1 = "hello";
	string str2 = "world";
	string str3 = str1 + " " + str2;
	cout << str3;*/


	/*string str1 = "hello";
	string str2 = "world";
	// string str3 = str1 + " " + str2;
	string str3 = concat_with_space(str1, str2);
	cout << str3;*/


	/*string str1 = "hello";
	string str2 = "world";
	str1 += str2;
	str1.append(str2);
	cout << str1 << "\n";
	cout << str2;*/


	/*string str = "hello world";
	cout << str[4];
	str[4] = 'a';
	cout << str;*/


	/*string str1 = "hello";
	string str2 = "hello";*/
	/*if (str1 == str2) {
		cout << "Equals";
	}
	else {
		cout << "Not Equals";
	}*/
	/*if (str1 > str2) {
		cout << "First is Bigger";
	}
	else {
		cout << "Second is Bigger";
	}*/


	//string str = "Hello all World all kolim all korlo bogimo";
	//insert
	//str.insert(6, "all "); //вставляє підпстрічку в нашу чтрічку в потрібну нам позицію (в данному випадку в 6 позицію).
	//cout << str << endl;


	//erase
	//str.erase(2, 3); //Видаляє з позиції елементи (з 2-гої позиції видпляє 3 елемента).
	//cout << str << endl;


	//replace
	//str.replace(6, 5, "All"); //Заміняє з 6 позиції 5 елементів на слово "All".
	//cout << str << endl;


	//length
	//cout << str.length() << endl; //Показує скіьки символів (\n - рахується теж 1 символом).


	//find
	//str.find("all", 10); //Повертає позицію початку слова (в даному випадку позицію букви "a"), а другй пераметир це позицію з якої починається пошук.
	//cout << str << endl;
	/*string search = "all";
	int pos = str.find(search);

	if (pos == -1)
	{
		cout << "Not found!";
	}
	else {
		while (pos != -1) {
			cout << pos << " ";
			str.erase(pos, search.length());
			pos = str.find(search, pos + 1);
		}
	}
	cout << str;*/


	//substr
	/*string res = str.substr(6, 3); //повертає починаючи з 6 позиції 3 символа стрічки.
	cout << res; */


	//empty
	/*string str_empty;
	if (str_empty.empty()) {
		cout << "String is empty";
	}*/


	//getline
	//string str_sin;
	///*cin >> str;*/ //дозволяє вводити тільки одне слово до пробілу
	//getline(cin, str_sin);
	//cout << str;


	//TASK - 1: видалення усіх "z" зі стрічик та вставлення ABS в середину стірчки.
	/*string str_task = "Helzlo azzzzzzzll Wozrld all kzzlim alzl korzlo z bozgimo";
	string search = "z";
	int pos = str_task.find(search);

	while (pos != -1) {
		str_task.erase(pos, search.length());
		pos = str_task.find(search, pos);
	}
	int avarange_pos = str_task.length() / 2;
	str_task.insert(avarange_pos, "ABS");
	cout << str_task;*/


	//TASK - 2:
	string fail_path = "data.txt";
	string text = file_utils::read_file_to_string(fail_path);

	setlocale(LC_CTYPE, "ukr");
	srand(time(0));

	int finish = 0;
	string search_word;

	do {
		cout << endl << "-- System comand --";


		int choice = menu();
		if (!choice) break;

		switch (choice)
		{
		case 0:
			finish = -1;
			break;
		case 1:
			cout << text;
			Sleep(3000);
			break;
		case 2:
			cout << text.length() << endl;
			Sleep(3000);
			break;
		case 3:
			getline(cin, search_word);
			reslut_word(search_word, text);
			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;

		default:
			cout << "Incorrect input";
			Sleep(3000);
			break;
		}

	} while (finish != -1);
	file_utils::write_string_to_file(fail_path, text);



	return 0;
}