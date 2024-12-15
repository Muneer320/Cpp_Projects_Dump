#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    cout << "****************************************\n";
    cout << "* Welcome to the Number Guessing Game! *\n";
    cout << "****************************************\n";
    cout << "\n";

    cout << "I've chosen a secret number between 1 and 100.\n";
    cout << "Your goal is to guess the number within 7 attempts.\n";
    cout << "After each guess, I'll give you a hint about how close you are:\n";
    cout << "- The hotter the temperature, the closer you are to the number.\n";
    cout << "- The colder the temperature, the further away you are.\n";
    cout << "Good luck and let's get started!\n";
    cout << "\n";

    srand(time(0)); // Seed for random number generator
    int number = rand() % 100 + 1; // Random number between 1 and 100
    int guess;
    int attempts = 0;

    while (attempts < 7)
    {
        cout << "Enter your guess (Attempt " << attempts + 1 << " of 7): ";
        cin >> guess;

        if (guess == number)
        {
            cout << "Congratulations! You've guessed the number in " << attempts + 1 << " attempts.\n";
            break;
        }
        else
        {
            int diff = abs(number - guess);
            if (diff <= 1)
            {
                cout << "🔥 Burning Hot! You're almost there.\n";
            }
            else if (diff <= 5)
            {
                cout << "💥 Boiling! Getting closer.\n";
            }
            else if (diff <= 10)
            {
                cout << "⚡ Sizzling! You're close.\n";
            }
            else if (diff <= 20)
            {
                cout << "🔥 Hot! You're getting closer.\n";
            }
            else if (diff <= 30)
            {
                cout << "🌡️ Warm! You're still in the right direction.\n";
            }
            else if (diff <= 40)
            {
                cout << "❄️ Cold! You're a bit far.\n";
            }
            else if (diff <= 50)
            {
                cout << "🥶 Chilly! You're pretty far away.\n";
            }
            else
            {
                cout << "❄️ Frozen! You're very far from the number.\n";
            }
        }

        attempts++;
    }

    if (attempts == 7)
    {
        cout << "\nSorry! You've used all 7 attempts.\n";
        cout << "The secret number was " << number << ". Better luck next time!\n";
    }

    return 0;
}
