#include <iostream>
#include <limits>

using namespace std;

// Function to validate numerical input
double getValidatedInput() {
    double num;
    while (true) {
        cin >> num;
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a numerical value: ";
        } else {
            return num;
        }
    }
}

// Function to display the menu and get the user's choice
int displayMenu() {
    int choice;
    cout << "\nDigital Calculator Menu:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
    cin >> choice;
    return choice;
}

// Function to perform the chosen operation
void performOperation(int choice) {
    double num1, num2;
    cout << "Enter the first number: ";
    num1 = getValidatedInput();
    cout << "Enter the second number: ";
    num2 = getValidatedInput();

    switch (choice) {
        case 1:
            cout << "Result: " << num1 + num2 << endl;
            break;
        case 2:
            cout << "Result: " << num1 - num2 << endl;
            break;
        case 3:
            cout << "Result: " << num1 * num2 << endl;
            break;
        case 4:
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }
}

int main() {
    int choice;
    while (true) {
        choice = displayMenu();
        if (choice == 5) {
            cout << "Exiting the calculator. Goodbye!\n";
            break;
        }
        performOperation(choice);
    }
    return 0;
}