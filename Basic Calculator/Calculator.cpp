#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void printMenu()
{

    cout << "\n\n";
    cout << "Welcome to Simple Calculator" << endl;
    cout << "----------------------------" << endl;
    cout << endl;

    cout << "Choose one of the following operations:" << endl;
    cout << "1. Addition (a+b)" << endl;
    cout << "2. Subtraction (a-b)" << endl;
    cout << "3. Multiplication (a*b)" << endl;
    cout << "4. Division (a/b)" << endl;
    cout << "5. Exponentiation (a^b)" << endl;
    cout << "6. Logarithm (log_a(b))" << endl;
    cout << "7. Factorial (n!)" << endl;
    cout << "8. Power (a^n)" << endl;
    cout << "9. Modulus (a % b)" << endl;
    cout << endl;
}

int main()
{
    printMenu();

    int choice;
    cout << "Enter you choice: ";
    cin >> choice;
    int numNumbers = choice == 7 ? 1 : 2;

    double result;
    switch (choice)
    {
    case 1:
    {
        double a, b;
        cout << "Enter two numbers (space separated): ";
        cin >> a >> b;
        result = a + b;
        break;
    }
    case 2:
    {
        double a, b;
        cout << "Enter two numbers (space separated): ";
        cin >> a >> b;
        result = a - b;
        break;
    }
    case 3:
    {
        double a, b;
        cout << "Enter two numbers (space separated): ";
        cin >> a >> b;
        result = a * b;
        break;
    }
    case 4:
    {
        double a, b;
        cout << "Enter two numbers (space separated): ";
        cin >> a >> b;
        result = a / b;
        break;
    }
    case 5:
    {
        double a, b;
        cout << "Enter two numbers (space separated): ";
        cin >> a >> b;
        result = pow(a, b);
        break;
    }
    case 6:
    {
        double a, b;
        cout << "Enter two numbers (space separated): ";
        cin >> a >> b;
        result = log(b) / log(a);
        break;
    }
    case 7:
    {
        int n;
        cout << "Enter a number: ";
        cin >> n;
        result = 1;
        for (int i = 1; i <= n; i++)
        {
            result *= i;
        }
        break;
    }
    case 8:
    {
        double a, n;
        cout << "Enter two numbers (space separated): ";
        cin >> a >> n;
        result = pow(a, n);
        break;
    }
    case 9:
    {
        double a, b;
        cout << "Enter two numbers (space separated): ";
        cin >> a >> b;
        result = fmod(a, b);
        break;
    }
    default:
        cout << "Invalid choice" << endl;
        return 1;
    }

    cout << "Result: " << result << endl;

    cout << "Do you want to perform another operation? (y/n): ";
    char ch;
    cin >> ch;
    if (ch == 'y')
    {
        main();
    }

    return 0;
}