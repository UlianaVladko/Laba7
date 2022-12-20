
#include<vector>
#include <map>
#include <iostream>
using namespace std;

void print(vector<float>v) {    
    for (float n : v) cout << n << "\t|";
}

class Settings {
private:    
    static map <string, string> MyMap;

public:
    Settings(string key, string value)
    {
        MyMap[key] = value;
    }      

    static void Add(string key, string value)
    {
        MyMap.insert(make_pair(key, value));
    }

    static string get(string key)
    {
        map<string, string>::iterator i;
        i = MyMap.find(key);
        return i->second;
    }

    static void print()
    {
        cout << endl<<endl<<"Map: " << endl;
        for (auto i = MyMap.begin(); i != MyMap.end(); i++) {

            std::cout << i->first << " = " << i->second << "\n";

        }
    }
};

map <string, string> Settings::MyMap;

int main()
{
    setlocale(LC_ALL, "");

    cout << "Vector:" << endl;

    vector<float>v{ 5,2,3,-5,34.13 };
    print(v);
    
    cout << endl;

    auto index = v.begin();
    index+=3;
    v.insert(index, 50.456);
    
    print(v);

    cout << endl;

    index = v.begin();
    index += 5;
    v.erase(index);

    print(v);

    Settings test_static("key", "value");
    test_static.Add("key1", "value1");
    test_static.Add("key2", "value2");
    test_static.print();
    cout << endl<<"Значение, соотвествующее \"key1\": " << test_static.get("key1");
}

