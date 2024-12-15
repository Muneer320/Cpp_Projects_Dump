#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;


class helper{
    string name, email, userName, password;
    string searchName, searchEmail, searchUserName, searchPass;
    string database = "terminalLoginDatabase.txt";
    fstream file;
    public:
    void login();
    void sign_up();
    void forgot_password();
}obj;


void printMessage(const string &message)
{
    int length = message.length();
    int boxWidth = length + 6; // 3 spaces on each side of the message

    cout << endl;
    // Print top border
    cout << "\t\t"; // Left Margin
    cout << "+";
    for (int i = 0; i < boxWidth - 2; ++i)
    {
        cout << "-";
    }
    cout << "+" << endl;

    // Print message with padding
    cout << "\t\t"; // Left Margin
    cout << "|  " << message << "  |" << endl;

    // Print bottom border
    cout << "\t\t"; // Left Margin
    cout << "+";
    for (int i = 0; i < boxWidth - 2; ++i)
    {
        cout << "-";
    }
    cout << "+" << endl;

    cout << endl;
}


void helper :: login()
{
    printMessage("Login");

    string username;
    cout << "Enter your username: ";
    getline(cin, username);

    string pass;
    cout << "Enter your password: ";
    getline(cin, pass);

    file.open(database,ios :: in);
    int flag = 0;
    while(file >> name >> email >> userName >> password)
    {
        if(userName == username && password == pass)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        cout << "Login Successful" << endl;
        replace(name.begin(), name.end(), '_', ' ');
        cout << "Welcome " << name << endl;
    }
    else
    {
        cout << "Login Failed" << endl;
    }

    file.close();


}

void helper :: sign_up()
{
    printMessage("Sign Up");
    

    string name;
    cout << "Enter your Full Name: ";
    getline(cin, name);
    replace(name.begin(), name.end(), ' ', '_'); // Replacing space with underscore because we are using tab as delimiter


    string email;
    cout << "Enter your Email: ";
    getline(cin, email);

    string username;
    cout << "Enter a username: ";
    getline(cin, username);

    string pass;
    cout << "Enter a password: ";
    getline(cin, pass);


    file.open(database,ios :: out | ios :: app);
    // ToDo: Add a check if username already exists and add some security question for forget password
    file << name << "\t" << email << "\t" << username << "\t" << pass << endl;

    cout << "Account Created Successfully" << endl;

    file.close();

    login();
}

void helper :: forgot_password()
{
    printMessage("You have selected Forgot Password");

    string username;
    cout << "Enter your username: ";
    getline(cin, username);

    file.open(database,ios :: in);
    int flag = 0;
    while(file >> name >> email >> userName >> password)
    {
        if(userName == username)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        // ToDo: Add some security questions and checks
        cout << "Your password is: " << password << endl;
        login();
    }
    else
    {
        cout << "Username not found" << endl;
    }

}



int main()
{

    cout << "\n\n";
    // cout << "\t\t+---------------------------------+" << endl;
    // cout << "\t\t| Welcome to Terminal Login page. |" << endl;
    // cout << "\t\t+---------------------------------+" << endl;
    printMessage(" Welcome to Terminal Login page. ");
    cout << "\n\n";

    cout << "Please enter your choice [1/2/3/4]" << endl;
    cout << "1. Login" << endl;
    cout << "2. Sign Up" << endl;
    cout << "3. Forgot Password" << endl;
    cout << "4. Exit" << endl;
    cout << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cin.ignore();
        cout << endl;
        // cout << "You have selected Login" << endl;
        obj.login();
        break;
    case 2:
        cin.ignore();
        cout << endl;
        obj.sign_up();
        // cout << "You have selected Sign Up" << endl;
        break;
    case 3:
        cin.ignore();
        cout << endl;
        obj.forgot_password();
        // cout << "You have selected Forgot Password" << endl;
        // break;
    case 4:
        cin.ignore();
        cout << endl;
        cout << "Have a wonderful day ahead.\nExiting..." << endl;
        exit(0);
    default:
        cout << endl;
        cout << "Invalid choice" << endl;
        break;
    }

    return 0;
}