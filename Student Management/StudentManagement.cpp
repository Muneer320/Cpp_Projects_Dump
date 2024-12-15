#include <iostream>
#include <fstream>
#include <iomanip> // For tabular display
using namespace std;

class StudentManagementSystem {
    string rollNum, name, fName, address, search;
    fstream file;

public:
    void addStudent();
    void viewStudents();
    void searchStudent();
} obj;

void printMessage(const string &message) {
    int length = message.length();
    int boxWidth = length + 6; // 3 spaces on each side of the message

    cout << endl;
    // Print top border
    cout << "\t\t"; // Left Margin
    cout << "+";
    for (int i = 0; i < boxWidth - 2; ++i) {
        cout << "-";
    }
    cout << "+" << endl;

    // Print message with padding
    cout << "\t\t"; // Left Margin
    cout << "|  " << message << "  |" << endl;

    // Print bottom border
    cout << "\t\t"; // Left Margin
    cout << "+";
    for (int i = 0; i < boxWidth - 2; ++i) {
        cout << "-";
    }
    cout << "+" << endl;

    cout << endl;
}

int main() {
    char choice;

    while (true) {
        printMessage("Student Management System");
        cout << "1 - Add Student Record" << endl;
        cout << "2 - View All Student Records" << endl;
        cout << "3 - Search Student Record" << endl;
        cout << "4 - Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1':
                obj.addStudent();
                break;
            case '2':
                obj.viewStudents();
                break;
            case '3':
                obj.searchStudent();
                break;
            case '4':
                printMessage("Exiting the program. Goodbye!");
                return 0;
            default:
                cout << "\nInvalid Choice...!" << endl;
        }
    }
}

void StudentManagementSystem::addStudent() {
    printMessage("Add Student Record");

    cout << "Enter Student Roll Number: ";
    getline(cin, rollNum);
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Student Father's Name: ";
    getline(cin, fName);
    cout << "Enter Student Address: ";
    getline(cin, address);

    file.open("stuData.txt", ios::out | ios::app);
    if (!file) {
        cout << "\tUnable to open file for writing." << endl;
        return;
    }
    file << rollNum << "*" << name << "*" << fName << "*" << address << endl;
    file.close();

    cout << "\n\tRecord added successfully!" << endl;
}

void StudentManagementSystem::viewStudents() {
    printMessage("Student Records");

    file.open("stuData.txt", ios::in);
    if (!file) {
        ofstream newFile("stuData.txt"); // Create empty file
        newFile.close();
        cout << "\tNo entries yet." << endl;
        return;
    }

    bool isEmpty = true;
    cout << left << setw(15) << "Roll Number" << setw(20) << "Name"
         << setw(20) << "Father's Name" << setw(30) << "Address" << endl;
    cout << string(85, '-') << endl;

    while (getline(file, rollNum, '*') && getline(file, name, '*') &&
           getline(file, fName, '*') && getline(file, address, '\n')) {
        cout << left << setw(15) << rollNum << setw(20) << name
             << setw(20) << fName << setw(30) << address << endl;
        isEmpty = false;
    }

    file.close();

    if (isEmpty) {
        cout << "\tNo entries found." << endl;
    }
}

void StudentManagementSystem::searchStudent() {
    printMessage("Search Student Record");

    cout << "Enter Student Roll Number to Search: ";
    getline(cin, search);

    file.open("stuData.txt", ios::in);
    if (!file) {
        cout << "\tUnable to open file for reading." << endl;
        return;
    }

    bool found = false;
    while (getline(file, rollNum, '*') && getline(file, name, '*') &&
           getline(file, fName, '*') && getline(file, address, '\n')) {
        if (rollNum == search) {
            cout << "\nStudent Found:" << endl;
            cout << "Roll Number: " << rollNum << endl;
            cout << "Name: " << name << endl;
            cout << "Father's Name: " << fName << endl;
            cout << "Address: " << address << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "\tNo record found for Roll Number: " << search << endl;
    }
}
