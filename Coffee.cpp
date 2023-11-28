#include <iostream>
#include <iomanip>

using namespace std;


// Function to display the menu and get user input

int showMenu() {
    cout << "==== Coffee Shop Menu ====" << endl;
    cout << "1. Espresso" << endl;
    cout << "2. Latte" << endl;
    cout << "3. Cappuccino" << endl;
    cout << "4. Americano" << endl;
    cout << "5. Quit" << endl;


    int choice;
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    return choice;
}


// Function to calculate the cost based on the coffee type and size

double calculateCost(int coffeeType, int size) {
    double baseCost = 0.0;

    switch (coffeeType) {
    case 1: // Espresso
        baseCost = 2.5;
        break;
    case 2: // Latte
        baseCost = 3.0;
        break;
    case 3: // Cappuccino
        baseCost = 3.5;
        break;
    case 4: // Americano
        baseCost = 2.0;
        break;
    default:
        break;
    }


    // Adjust cost based on size

    switch (size) {
    case 1: // Small
        baseCost *= 1.0;
        break;
    case 2: // Medium
        baseCost *= 1.2;
        break;
    case 3: // Large
        baseCost *= 1.5;
        break;
    default:
        break;
    }

    return baseCost;
}


int main() {
    int coffeeType, size;
    double totalCost = 0.0;

    cout << "Welcome to the Coffee Shop!" << endl;

    while (true) {
        int choice = showMenu();

        if (choice == 5) {
            // Exit the loop if the user chooses to quit
            break;
        }

        if (choice < 1 || choice > 4) {
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            continue;
        }


        cout << "Select the size:" << endl;
        cout << "1. Small" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Large" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> size;

        if (size < 1 || size > 3) {
            cout << "Invalid size. Please enter a number between 1 and 3." << endl;
            continue;
        }


        // Calculate and display the cost

        totalCost += calculateCost(choice, size);
        cout << fixed << setprecision(2);
        cout << "Cost so far: $" << totalCost << endl;
    }


    cout << "Thank you for ordering. Your total cost is: $" << totalCost << endl;

    return 0;
}
