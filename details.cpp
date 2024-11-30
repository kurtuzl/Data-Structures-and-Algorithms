#include <iostream>
 
using namespace std;

int main()
{
    string name;
    string age;
    string occupation;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your age: ";
    getline(cin, age);
    cout << "Enter your occupation: ";
    getline(cin, occupation);

    // printing the output

    cout << name << endl;
    cout << age << endl;
    cout << occupation << endl;

    return 0;
}
