#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Library {
private:
    string bookId, bookName, authorName, searchId;
    fstream file;

public:
    void addBook();
    void showAllBooks();
    void extractBook();
    void ensureFileExists();
};

int main() {
    Library library;
    char choice;

    library.ensureFileExists();

    while (true) {
        cout << "\n\n";
        cout << "----------------------------------" << endl;
        cout << "1 - Show All Books" << endl;
        cout << "2 - Extract Book" << endl;
        cout << "3 - Add Books (ADMIN)" << endl;
        cout << "4 - Exit" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1':
                library.showAllBooks();
                break;
            case '2':
                library.extractBook();
                break;
            case '3':
                library.addBook();
                break;
            case '4':
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid Choice. Please try again!" << endl;
        }
    }
    return 0;
}

void Library::ensureFileExists() {
    file.open("bookData.txt", ios::in);
    if (!file.is_open()) {
        file.open("bookData.txt", ios::out);
    }
    file.close();
}

void Library::addBook() {
    cout << "\nEnter Book ID: ";
    getline(cin, bookId);
    cout << "Enter Book Name: ";
    getline(cin, bookName);
    cout << "Enter Author's Name: ";
    getline(cin, authorName);

    file.open("bookData.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << bookId << "*" << bookName << "*" << authorName << endl;
        file.close();
        cout << "Book added successfully!\n";
    } else {
        cerr << "Error: Unable to open file for writing.\n";
    }
}

void Library::showAllBooks() {
    file.open("bookData.txt", ios::in);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    cout << "\n\n" << setw(10) << "Book ID" 
         << setw(30) << "Book Name" 
         << setw(30) << "Author's Name" << endl;
    cout << string(70, '-') << endl;

    bool isEmpty = true;
    while (getline(file, bookId, '*') && 
           getline(file, bookName, '*') && 
           getline(file, authorName)) {
        cout << setw(10) << bookId 
             << setw(30) << bookName 
             << setw(30) << authorName << endl;
        isEmpty = false;
    }

    if (isEmpty) {
        cout << "No books found in the library.\n";
    }

    file.close();
}

void Library::extractBook() {
    showAllBooks();

    cout << "\nEnter Book ID to Extract: ";
    getline(cin, searchId);

    bool found = false;
    file.open("bookData.txt", ios::in);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    while (getline(file, bookId, '*') && 
           getline(file, bookName, '*') && 
           getline(file, authorName)) {
        if (searchId == bookId) {
            cout << "\nBook Found:\n";
            cout << setw(10) << "Book ID" 
                 << setw(30) << "Book Name" 
                 << setw(30) << "Author's Name" << endl;
            cout << string(70, '-') << endl;
            cout << setw(10) << bookId 
                 << setw(30) << bookName 
                 << setw(30) << authorName << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book with ID " << searchId << " not found.\n";
    }

    file.close();
}
