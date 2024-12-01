
#include <iostream>

using namespace std;



int main() {

    //variables

    float fahrenheit, celsius, choice;
    char input1;
    double input2;

    // INPUT
    cout << "Choose an option! Enter (C or c) if you want to convert Fahrenheit to Celsius  and Enter (F or f) if you want to convert Celsius to Fahrenheit: \n";
    cin >> input1;


    if (input1 == 'c')
    {
    // INPUT
      cout << "Celsius to Fahrenheit: ";
      cin >> input2;
      cout << endl; 
    // OUTPUT
      cout << "Fahrenheit to Celsius: " << (input2 - 32) * (5.0/9.0) << endl;
    }

    else if (input1 == 'C')
    {
    // INPUT
      cout << "Celsius to Fahrenheit: ";
      cin >> input2;
      cout << endl;
    // OUTPUT
      cout << "Fahrenheit to Celsius: " << (input2 - 32) * (5.0/9.0) << endl;
    }

    if (input1 == 'f')
  {
    // INPUT
    cout << "Fahrenheit to Celsius: ";
    cin >> celsius;
    //FORMULA
    fahrenheit = (celsius * 9.0) / 5.0 + 32;
    // OUTPUT
    cout << "Celsius to Fahrenheit: " << fahrenheit << endl;
  }



  else if (input1 == 'F')
  {
    cout << "Fahrenheit to Celsius: ";
    cin >> input2;
    cout << endl;
    cout << "Celsius to Fahrenheit: " << (input2 * 1.8) + (32) << endl;
  }

    return 0;

}