#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip> // For tabular display
using namespace std;



// Configuration variables
string managerName = "X Management System"; // Change this to your name of choice
// Change the menu options as needed (functionality remains the same)
map<int, string> menuOptions = {
    {1, "Add New Entry"},
    {2, "Show All Entries"},
    {3, "Find an Entry"},
    {4, "Delete an Entry"},
    {5, "Exit"}
};

// Change the input prompts as needed. The first string in each pair is the field/variable name, the second string is the prompt message.
vector<pair<string, string>> inputPrompts = {
    {"id", "Enter Book ID"},
    {"name", "Enter Book Name"},
    {"author", "Enter Author Name"}
};
// Change the primary key to any one of the input prompts feilds/variables. 
// This is used for searching and deleting entries, so it needs to be unique.
string primaryKey = "id";
// File to store the data
string dataFile = "data.txt";



// Utility function to print styled titles
void printMessage(const string &message)
{
    int length = message.length();
    int boxWidth = length + 6;

    cout << endl;
    cout << "\t\t" << "+" << string(boxWidth - 2, '-') << "+" << endl;
    cout << "\t\t" << "|  " << message << "  |" << endl;
    cout << "\t\t" << "+" << string(boxWidth - 2, '-') << "+" << endl;
    cout << endl;
}


// Functions for core functionalities
void addEntry()
{
    fstream file;
    file.open(dataFile, ios::out | ios::app);
    if (!file)
    {
        cout << "Error: Unable to open file for writing." << endl;
        return;
    }

    map<string, string> entry;
    for (const auto &field : inputPrompts)
    {
        cout << field.second << ": ";
        getline(cin, entry[field.first]);
    }

    for (size_t i = 0; i < inputPrompts.size(); ++i)
    {
        file << entry[inputPrompts[i].first];
        if (i != inputPrompts.size() - 1)
            file << "*";
        else
            file << "\n";
    }

    file.close();
    cout << "Entry added successfully!" << endl;
}

void showAllEntries()
{
    fstream file;
    file.open(dataFile, ios::in);
    if (!file)
    {
        file.close();
        file.open(dataFile, ios::out);
        file.close();
        cout << "No entries yet." << endl;
        return;
    }

    printMessage("All Entries");

    // Calculate the maximum width for each column
    vector<int> columnWidths(inputPrompts.size(), 15);
    string line;
    while (getline(file, line))
    {
        size_t pos = 0;
        for (size_t i = 0; i < inputPrompts.size(); ++i)
        {
            pos = line.find('*');
            string field = (pos == string::npos ? line : line.substr(0, pos));
            columnWidths[i] = max(columnWidths[i], static_cast<int>(field.length() + 2));
            line = (pos == string::npos ? "" : line.substr(pos + 1));
        }
    }
    file.clear();
    file.seekg(0, ios::beg);

    // Print the headers
    for (size_t i = 0; i < inputPrompts.size(); ++i)
    {
        cout << setw(columnWidths[i]) << inputPrompts[i].first;
    }
    cout << endl;
    for (size_t i = 0; i < inputPrompts.size(); ++i)
    {
        cout << string(columnWidths[i], '-');
    }
    cout << endl;

    // Print the entries
    while (getline(file, line))
    {
        size_t pos = 0;
        for (size_t i = 0; i < inputPrompts.size(); ++i)
        {
            pos = line.find('*');
            cout << setw(columnWidths[i]) << (pos == string::npos ? line : line.substr(0, pos));
            line = (pos == string::npos ? "" : line.substr(pos + 1));
        }
        cout << endl;
    }

    file.close();
}

void findEntry()
{
    cout << "Enter " << inputPrompts[0].second << ": "; // We know "id" is first now
    string searchKey;
    getline(cin, searchKey);

    fstream file;
    file.open(dataFile, ios::in);
    if (!file)
    {
        cout << "Error: Unable to open file for reading." << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line))
    {
        size_t pos = line.find('*');
        string key = line.substr(0, pos);

        if (key == searchKey)
        {
            found = true;
            cout << "Found Entry:" << endl;
            size_t lastPos = 0;
            for (const auto &field : inputPrompts)
            {
                pos = line.find('*', lastPos);
                cout << field.second << ": " << (pos == string::npos ? line.substr(lastPos) : line.substr(lastPos, pos - lastPos)) << endl;
                lastPos = (pos == string::npos ? line.length() : pos + 1);
            }
            break;
        }
    }

    if (!found)
    {
        cout << "No entry found with the given " << inputPrompts[0].first << "." << endl;
    }

    file.close();
}

void deleteEntry()
{
    cout << "Enter " << inputPrompts[0].second << " to delete: "; // "id" is still first
    string deleteKey;
    getline(cin, deleteKey);

    fstream file, tempFile;
    file.open(dataFile, ios::in);
    tempFile.open("temp.txt", ios::out);

    if (!file || !tempFile)
    {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    string line;
    bool deleted = false;
    while (getline(file, line))
    {
        size_t pos = line.find('*');
        string key = line.substr(0, pos);

        if (key == deleteKey)
        {
            deleted = true;
            continue;
        }
        tempFile << line << endl;
    }

    file.close();
    tempFile.close();

    remove(dataFile.c_str());
    rename("temp.txt", dataFile.c_str());

    if (deleted)
    {
        cout << "Entry deleted successfully." << endl;
    }
    else
    {
        cout << "No entry found with the given " << inputPrompts[0].first << "." << endl;
    }
}

// Main function
int main()
{
    while (true)
    {
        printMessage(managerName);

        for (const auto &option : menuOptions)
        {
            cout << option.first << ". " << option.second << endl;
        }

        cout << "Enter your choice: ";
        char choice;
        cin >> choice;
        cin.ignore(); // To handle newline character

        switch (choice)
        {
        case '1':
            addEntry();
            break;
        case '2':
            showAllEntries();
            break;
        case '3':
            findEntry();
            break;
        case '4':
            deleteEntry();
            break;
        case '5':
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }

        cout << "\nEnter 0 to return to the main menu: ";
        string temp;
        getline(cin, temp);
    }

    return 0;
}
