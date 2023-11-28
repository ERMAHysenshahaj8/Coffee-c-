#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;


// Class to represent a coffee order

class CoffeeOrder {
public:
    string coffeeType;
    string size;
    vector<string> options;
    double cost;


    // Constructor to initialize order details

    CoffeeOrder(string type, string coffeeSize, vector<string> coffeeOptions, double orderCost)
        : coffeeType(type), size(coffeeSize), options(coffeeOptions), cost(orderCost) {}
};


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


// Function to customize the order with additional options

void customizeOrder(vector<string>& options) {
    cout << "Would you like to add any additional options? (Y/N): ";
    char addOptions;
    cin >> addOptions;

    if (toupper(addOptions) == 'Y') {
        cout << "Available options: Sugar, Milk, Whipped Cream" << endl;

        while (true) {
            cout << "Enter the option you want to add (or type 'done' to finish): ";
            string option;
            cin >> option;

            if (option == "done") {
                break;
            }

            options.push_back(option);
        }
    }
}


// Function to display the receipt for a given order

void displayReceipt(const CoffeeOrder& order) {
    cout << "\n===== Receipt =====" << endl;
    cout << "Coffee Type: " << order.coffeeType << endl;
    cout << "Size: " << order.size << endl;

    if (!order.options.empty()) {
        cout << "Options: ";
        for (const string& option : order.options) {
            cout << option << ", ";
        }
        cout << endl;
    }

    cout << fixed << setprecision(2);
    cout << "Cost: $" << order.cost << endl;
}


int main() {
    vector<CoffeeOrder> orders;
    double totalCost = 0.0;

    cout << "Welcome to the Coffee Shop!" << endl;

    while (true) {
        int choice = showMenu();

        if (choice == 5) {
            // Display receipts and total cost, then exit the loop if the user chooses to quit
            for (const auto& order : orders) {
                displayReceipt(order);
            }
            cout << "\nTotal Cost for all orders: $" << totalCost << endl;
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
        int size;
        cin >> size;

        if (size < 1 || size > 3) {
            cout << "Invalid size. Please enter a number between 1 and 3." << endl;
            continue;
        }

        vector<string> options;
        customizeOrder(options);


        // Calculate and display the cost

        double cost = calculateCost(choice, size);
        for (const string& option : options) {
            // Additional cost for each option
            cost += 0.5;
        }


        // Create a CoffeeOrder object and store it in the vector

        CoffeeOrder order("", "", vector<string>(), 0.0);
        switch (choice) {
        case 1:
            order = CoffeeOrder("Espresso", to_string(size), options, cost);
            break;
        case 2:
            order = CoffeeOrder("Latte", to_string(size), options, cost);
            break;
        case 3:
            order = CoffeeOrder("Cappuccino", to_string(size), options, cost);
            break;
        case 4:
            order = CoffeeOrder("Americano", to_string(size), options, cost);
            break;
        default:
            break;
        }


        orders.push_back(order);
        totalCost += cost;

        cout << "\nOrder placed successfully! Current total cost: $" << totalCost << "\n" << endl;
    }


    return 0;
}


