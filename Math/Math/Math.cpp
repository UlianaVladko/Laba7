
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include<windows.h>
#include <string>
using namespace std;

void separator() {
    cout << "---------------------" << endl;
}

int main() {

    setlocale(LC_ALL, "");

    float rad;
    cout << "Enter radius of circle\t";
    cin >> rad;

    cout << "Length of circle\t" << trunc((2 * M_PI * rad) * 1000 + 0.5) / 1000 << endl;


    separator();


    string path = "msg.txt";

    fstream fin;

    fin.exceptions(fstream::badbit | fstream::failbit);

    try {
        cout << "Trying to open a file!" << endl;
        fin.open(path);
        cout << "The file is open!" << endl << endl;
        fin.close();
    }

    catch (const fstream::failure& ex) {
        cout << "File opening error!" << endl;
        cout << ex.what() << endl;
        cout << ex.code() << endl;

        return 0;
    }

    fstream fs;

    fs.open(path, fstream::in | fstream::out | fstream::app);

    string msg;
    string inver;

    SetConsoleCP(1251);

    cout << "Enter your message!" << endl;
    cin.seekg(cin.eof());   // "пробежаться" до конца буфера
    getline(cin, msg);

    fs << msg << endl;

    while (fs.is_open()) {

        cout << endl << "Enter your new message or command!" << endl;
        getline(cin, msg);

        if (msg == "exit") { fs.close(); cout << endl << "Bye-Bye" << endl; break; }

        if (msg == "read") {

            fstream openfile(path);
            cout << endl << "File:" << endl;
            while (getline(openfile, inver)) { cout << inver << endl; }

            openfile.close();

            continue;
        }

        if (msg == "erase") {

            fstream erase(path, fstream::trunc);
            erase.close();

            cout << endl << "Messages were deleted!" << endl;

            continue;
        }

        fs << msg << endl;
    }

    SetConsoleOutputCP(866);

    fs.close();

    /*//Пробник

    if (!fs.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {

        string msg;
        int value;

        cout << "Файл открыт!" << endl;
        cout << "1 - ввести сообщение" << endl << "2 - вывести содержимое файла" << endl << endl;
        cout << "Введите команду\t";
        cin >> value;

        if (value == 1) {
            cout << "Введите ваше сообщение!" << endl;

            SetConsoleCP(1251);

            cin.ignore(cin.rdbuf()->in_avail());    // игнор численных символов
            getline(cin, msg);
            fs << msg << "\n";

            SetConsoleOutputCP(866);
        }

        if (value == 2) {
            cout << "Чтение данных из файла!" << endl;

            while (!fs.eof()) {
                msg = "";
                getline(fs, msg);
                cout << msg << endl;

                break;
            }
        }
    }
    fs.close();*/
}
