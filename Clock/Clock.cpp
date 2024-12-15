#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

int main()
{

    // First ask the user for the time format [12 or 24]
    // Then get the current time and display it in the format the user chose and keep updating it every second
    // Also display the date in the format: "Day, Date Month, Year"
    // Use strftime() to format the time and date
    
    int choice = 2;
    string input;

    cout << "Choose the time format: \n1. 12-hour format\n2. 24-hour format (Default)\n";
    getline(cin, input);

    if (!input.empty()) {
        stringstream ss(input);
        if (!(ss >> choice) || (choice != 1 && choice != 2)) {
            choice = 2; // Set to default if input is invalid
        }
    }

    
    while (true) {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        string time_format = (choice == 1) ? "%I:%M:%S %p" : "%H:%M:%S";
        string date_format = "%A, %d %B, %Y";

        char time_str[100], date_str[100];
        strftime(time_str, sizeof(time_str), time_format.c_str(), ltm);
        strftime(date_str, sizeof(date_str), date_format.c_str(), ltm);

        cout << "Time: " << time_str << endl;
        cout << "Date: " << date_str << endl;

        system("cls"); // Clear the console
    }


    return 0;
}