#include <iostream>
#include <windows.h>  // для Sleep()
#include <string>
#include <map>
#include <fstream>
#include <limits>

using namespace std;

static string trim(const string& s) {
    size_t b = s.find_first_not_of(" \t\r\n");
    if (b == string::npos) return "";
    size_t e = s.find_last_not_of(" \t\r\n");
    return s.substr(b, e - b + 1);
}

static void loadDictionary(map<string, string>& dict, const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) return;
    string line;
    while (getline(in, line)) {
        line = trim(line);
        if (line.empty()) continue;
        size_t tabPos = line.find('\t');
        string key = (tabPos == string::npos) ? line : line.substr(0, tabPos);
        string val = (tabPos == string::npos) ? "" : line.substr(tabPos + 1);
        dict[trim(key)] = trim(val);
    }
}

static bool saveDictionary(const map<string, string>& dict, const string& filename) {
    ofstream out(filename);
    if (!out.is_open()) return false;
    for (auto it = dict.begin(); it != dict.end(); ++it)
        out << it->first << '\t' << it->second << '\n';
    return true;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    const string filename = "dictionary.txt";
    map<string, string> dictionary{
        {"book", "книга"},
        {"pen", "ручка"},
        {"notebook", "зошит"},
        {"pencil", "олівець"},
    };

    loadDictionary(dictionary, filename);

    while (true) {
        system("cls");
        cout << "=== СЛОВНИК ===\n"
            << "1) Показати слова\n"
            << "2) Пошук слова\n"
            << "3) Додати слово\n"
            << "4) Видалити слово\n"
            << "5) Редагувати переклад\n"
            << "6) Зберегти у файл\n"
            << "0) Вихід\n"
            << "Ваш вибір: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << endl << "Помилка вводу!";
            Sleep(1000);
            continue;
        }
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');

        switch (choice) {
        case 0:
            saveDictionary(dictionary, filename);
            cout << endl << "Вихід...";
            Sleep(1000);
            return 0;
        case 1:
            for (auto& kv : dictionary) cout << endl << kv.first << " : " << kv.second << endl;
            Sleep(2000);
            break;
        case 2: {
            string key;
            cout << "Введіть слово: ";
            getline(cin, key);
            auto it = dictionary.find(key);
            if (it != dictionary.end()) cout << it->first << " = " << it->second << endl;
            else cout << endl << "Не знайдено.\n";
            Sleep(2000);
            break;
        }
        case 3: {
            string key, val;
            cout << endl << "Нове слово: ";
            getline(cin, key);
            cout << "Переклад: ";
            getline(cin, val);
            dictionary[key] = val;
            cout << "Додано!\n";
            Sleep(1000);
            break;
        }
        case 4: {
            string key;
            cout << endl << "Слово для видалення: ";
            getline(cin, key);
            dictionary.erase(key);
            cout << "Готово!\n";
            Sleep(1000);
            break;
        }
        case 5: {
            string key, val;
            cout << endl << "Слово для редагування: ";
            getline(cin, key);
            if (dictionary.find(key) != dictionary.end()) {
                cout << "Новий переклад: ";
                getline(cin, val);
                dictionary[key] = val;
                cout << "Оновлено!\n";
            }
            else cout << endl << "Не знайдено.\n";
            Sleep(1000);
            break;
        }
        case 6:
            saveDictionary(dictionary, filename);
            cout << endl << "Збережено!\n";
            Sleep(1500);
            break;
        default:
            cout << endl << "Невірний вибір!\n";
            Sleep(1000);
        }
    }
}
