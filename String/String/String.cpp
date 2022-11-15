#include<Windows.h>
#include <iostream>
#include<string>
using namespace std;

void print(string str) {
    cout << str << endl;
}

int main()
{
    setlocale(LC_ALL, "");

    string str;
    cout << "Введите набор символов" << endl;
    cin >> str;

    print(str.substr(1, 3));

    int index = str.find("a");

    if (index == -1) {
        cout << "Символа 'a' не найдено" << endl;
    }
    else {
        print(to_string(index));
    }
}