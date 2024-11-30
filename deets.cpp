#include <iostream>
 
using namespace std;

int main()
{

    // variable
    string name;
    string age;
    string occupation;

    // input
    cout << "Enter your Name: ";
    getline(cin, name);
    cout << "Enter your Age: ";
    getline(cin, age);
    cout << "Enter your Occupation: ";
    getline(cin, occupation);

    // printing the output
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Occupation: " << occupation << endl;

    return 0;
}
