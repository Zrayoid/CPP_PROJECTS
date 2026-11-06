#include <iostream>
#include <random>
using namespace std;

// updated way
mt19937 gen(random_device{}());

int random_number_generator()
{
    // random_device rd; // my way
    // mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100);
    return dist(gen);
}

bool numberCheck(int randomNumber)
{

    int guess = 0;
    cout << " Guess the number(1 - 100): ";

    while (true)
    {
        if (cin >> guess)
        {
            if( guess < 1 || guess > 100)
            {
                cout << "Enter number between 1 to 100: ";
                continue;
            }
            if (randomNumber == guess)
            {
                cout << " \nConguratulation you won.";
                return true;
            }
            else if (randomNumber > guess)
            {
                if (randomNumber - guess >= 20)
                {
                    cout << " TOO LOW: ";
                }
                else if (randomNumber - guess >= 10)
                {
                    cout << " Low, go higher: ";
                }
                else if (randomNumber - guess >= 5)
                {
                    cout << " close, go higher: ";
                }
                else
                    cout << " very very close, a bit higher: ";
            }
            else if (randomNumber < guess)
            {
                if (guess - randomNumber >= 20)
                {
                    cout << " TOO high: ";
                }
                else if (guess - randomNumber >= 10)
                {
                    cout << " High, go low: ";
                }
                else if (guess - randomNumber >= 5)
                {
                    cout << " Close, go lower: ";
                }
                else
                    cout << " very very close, a bit lower: ";
            }
        }
        else
        {
            cout << " invalid input.";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nEnter integers: ";
        }
    }

    return false;
}

void playGame()
{
    char choice = 'y';
    int count = 1;
    while (choice == 'Y' || choice == 'y')
    {
        numberCheck(random_number_generator());

        cout << "\nWana play Round "<< ++count << " Y/N: ";
        cin >> choice;
        
    } 

    cout << " Bye bye.";
}

int main()
{

    playGame();

    return 0;
}