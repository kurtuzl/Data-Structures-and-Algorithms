#include <iostream>
using namespace std;

int main() {
    int variant;  // To choose between chocolate or milk variant
    /*bool cleanBowl;  // Whether the bowl and spoon are available
    bool microwaveAvailable;  // Whether the microwave is available*/
    
    // STEP 1: Choose variant
    cout << "Choose the variant of oats (1 for Chocolate, 2 for Milk): ";
    cin >> variant;

    // STEP 2: Get a bowl and spoon
    cout << "Get a bowl and a spoon." << endl;

    // STEP 3: Tear the sachet and pour oats into the bowl
    cout << "Tear the sachet and pour the oats into the bowl." << endl;
    cout << "Add the right amount of water to the bowl." << endl;

    // STEP 4: Place the bowl in the microwave
    cout << "Place the bowl in the microwave for 2 minutes on medium-high heat." << endl;
    
    // Assuming microwave is always available for simplicity
    //microwaveAvailable = true;

    /* Check if microwave is available
    if (!microwaveAvailable) {
        cout << "Microwave is not available. Stopping process." << endl;
        return 0;
    }*/

    // STEP 5:
    cout << "After 2 minutes, take out the bowl carefully (it may be hot) and stir the oats." << endl;

    // STEP 6:
    cout << "Let the oats sit for about 1 minute to cool slightly." << endl;

    // STEP 7:
    cout << "Enjoy your breakfast!" << endl;

    // End the process
    return 0;
}
