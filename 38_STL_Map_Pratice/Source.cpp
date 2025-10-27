#include <iostream>
#include <windows.h>  // ��� Sleep()
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
        {"book", "�����"},
        {"pen", "�����"},
        {"notebook", "�����"},
        {"pencil", "������"},
    };

    loadDictionary(dictionary, filename);

    while (true) {
        system("cls");
        cout << "=== ������� ===\n"
            << "1) �������� �����\n"
            << "2) ����� �����\n"
            << "3) ������ �����\n"
            << "4) �������� �����\n"
            << "5) ���������� ��������\n"
            << "6) �������� � ����\n"
            << "0) �����\n"
            << "��� ����: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << endl << "������� �����!";
            Sleep(1000);
            continue;
        }
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');

        switch (choice) {
        case 0:
            saveDictionary(dictionary, filename);
            cout << endl << "�����...";
            Sleep(1000);
            return 0;
        case 1:
            for (auto& kv : dictionary) cout << endl << kv.first << " : " << kv.second << endl;
            Sleep(2000);
            break;
        case 2: {
            string key;
            cout << "������ �����: ";
            getline(cin, key);
            auto it = dictionary.find(key);
            if (it != dictionary.end()) cout << it->first << " = " << it->second << endl;
            else cout << endl << "�� ��������.\n";
            Sleep(2000);
            break;
        }
        case 3: {
            string key, val;
            cout << endl << "���� �����: ";
            getline(cin, key);
            cout << "��������: ";
            getline(cin, val);
            dictionary[key] = val;
            cout << "������!\n";
            Sleep(1000);
            break;
        }
        case 4: {
            string key;
            cout << endl << "����� ��� ���������: ";
            getline(cin, key);
            dictionary.erase(key);
            cout << "������!\n";
            Sleep(1000);
            break;
        }
        case 5: {
            string key, val;
            cout << endl << "����� ��� �����������: ";
            getline(cin, key);
            if (dictionary.find(key) != dictionary.end()) {
                cout << "����� ��������: ";
                getline(cin, val);
                dictionary[key] = val;
                cout << "��������!\n";
            }
            else cout << endl << "�� ��������.\n";
            Sleep(1000);
            break;
        }
        case 6:
            saveDictionary(dictionary, filename);
            cout << endl << "���������!\n";
            Sleep(1500);
            break;
        default:
            cout << endl << "������� ����!\n";
            Sleep(1000);
        }
    }
}
