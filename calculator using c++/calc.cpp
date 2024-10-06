#include <iostream>
using namespace std;

void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    double num1, num2, result;
    char op;

    displayMenu();


    cout << "Enter the first number: ";
    cin >> num1;

 
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

  
    cout << "Enter the second number: ";
    cin >> num2;

    
    switch (op) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            if (num2 != 0) {
                result = divide(num1, num2);
            } else {
                cout << "Error: Division by zero is not allowed!" << endl;
                return 1; 
            }
            break;
        default:
            cout << "Error: Invalid operator!" << endl;
            return 1; 
    }

   
    cout << "Result: " << num1 << " " << op << " " << num2 << " = " << result << endl;

    return 0;
}


void displayMenu() {
    cout << "Simple Calculator" << endl;
    cout << "==================" << endl;
    cout << "You can use the following operators: " << endl;
    cout << "+ : Addition" << endl;
    cout << "- : Subtraction" << endl;
    cout << "* : Multiplication" << endl;
    cout << "/ : Division" << endl;
    cout << "==================" << endl << endl;
}


double add(double a, double b) {
    return a + b;
}


double subtract(double a, double b) {
    return a - b;
}


double multiply(double a, double b) {
    return a * b;
}


double divide(double a, double b) {
    return a / b;
}
