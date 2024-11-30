#include <iostream>
#include <string>
using namespace std;

int main() {
    bool bowlIsClean = true;  
    bool spoonIsClean = true; 
    
    if (bowlIsClean && spoonIsClean) {
        cout << "Bowl and spoon are clean. Proceeding..." << endl;
    } else {
        cout << "Cleaning bowl and spoon..." << endl;
        bowlIsClean = true;
        spoonIsClean = true;
    }

    bool cerealAvailable = true; 
    if (cerealAvailable) {
        cout << "Pouring cereal into the bowl..." << endl;
    } else {
        cout << "Error: No cereal available" << endl;
        return 1;
    }

    bool milkAvailable = true;  
    if (milkAvailable) {
        cout << "Pouring milk into the bowl..." << endl;
    } else {
        cout << "Error: No milk available" << endl;
        return 1;
    }
 
    string addExtras;
    cout << "Do you want to add extras (fruits/sugar)? (yes/no): ";
    cin >> addExtras;
    if (addExtras == "yes") {
        cout << "Adding extras to the cereal..." << endl;
    } else {
        cout << "No extras added." << endl;
    }
 
    cout << "Enjoy your breakfast!" << endl;

    return 0;
}
