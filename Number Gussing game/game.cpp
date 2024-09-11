#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    cout << "Welcome to the number guessing game: \n";
    srand(static_cast<unsigned>(time(0)));

    while (true)
    {
        int randomnumber = 1 + (rand() % 100);
        cout << "Enter the level of difficulty \n";
        cout << "Enter 1 for easy level\n";
        cout << "Enter 2 for medium level \n";
        cout << "Enter 3 for difficult level \n";
        cout << "Enter 0 to exit the game \n";
        int num;
        cin >> num;

        if (num == 0)
        {
            cout << "Game exit" << endl;
            break;
        }

        int attempts;
        switch (num)
        {
            case 1:
                attempts = 10;
                break;
            case 2:
                attempts = 7;
                break;
            case 3:
                attempts = 5;
                break;
            default:
                cout << "Invalid option. Please try again.\n";
                continue;
        }

        while (attempts > 0)
        {
            int guessnumber;
            cout << "Enter the number, left attempts " << attempts << endl;
            cin >> guessnumber;

            if (guessnumber == randomnumber)
            {
                cout << "Congratulations, you won the game!" << endl;
                break;
            }
            else if (guessnumber > randomnumber)
            {
                cout << "Entered number is greater than the guess number \n";
            }
            else
            {
                cout << "Entered number is smaller than the guess number \n";
            }

            --attempts;

            if (attempts == 0)
            {
                cout << "The guess number was " << randomnumber << endl;
                cout << "You lose the game, Please try again" << endl;
            }
        }
    }

    return 0;
}
