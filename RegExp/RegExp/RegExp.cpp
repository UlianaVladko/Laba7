#include<regex>
#include<string>
#include <iostream>
#include <windows.h>
using namespace std;

bool isValidName(string name) {
    regex reg("[A-ZА-Я][a-zа-я]{2,32}");
    return regex_search(name, reg);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    string name;

    cout << "Enter your name in English or in Russian\t";
    cin >> name;
    
    if (isValidName(name)) {
        cout << "Your name is\t"<<name << endl<<endl;
    }
    else {
        cout << "\nThe name is spelled incorrectly"<<endl<<endl;
    }

    //REGEX_MATCH    

    /*cout << "Enter your name in English or in Russian\t";
    cin >> name;

    regex regular("([A-ZА-Я]{1,})""([a-zа-я]{2,31})");

    if (regex_match(name.c_str(),regular)) {
        cout << "Your name is\t" << name << enmdl;
    }
    else {
        cout << "\nThe name is spelled incorrectly" << endl<<endl;
    }*/

    //REGEX_INTERATOR

    string text = " было две электронные почты : pazoubuwonoi52@gmail.com - для работы, breumeissekubi83@mail.ru - для личного пользования\n";
    cout << "У "<<name<<text << endl;

    cmatch result;
    regex regular("([\\w-]+)(@)([\\w-]+)(\.)([a-z]{2,5})");
    auto words_begin = sregex_iterator(text.begin(), text.end(), regular);
    auto words_end = sregex_iterator();

    for (sregex_iterator it = words_begin; it != words_end; ++it)
        cout << it->str()<<endl ;
}