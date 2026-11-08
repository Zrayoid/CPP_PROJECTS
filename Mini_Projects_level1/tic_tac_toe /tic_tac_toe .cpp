#include <iostream>
#include <limits>
#include <string>
#include <sstream>
using namespace std;

void Board(char (*arr)[3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << " ";

        for ( int j = 0; j < 3; j++)
        {
            cout << arr[i][j];
            
            if ( j < 2)
                cout << " | ";
        }

        cout << "\n";

        if ( i < 2)
            cout <<  "---+---+---\n";
    }

    cout << "\n";
}

int SomeoneWon(char (*array)[3])
{
    // check rows and columns
    for (int i = 0; i < 3; i++)
    {
        // Horizontal check
        if (array[i][0] == array[i][1] &&
            array[i][1] == array[i][2])
        {
            if (array[i][0] == 'X')
            {
                return 1;
            }
            if (array[i][0] == 'O')
            {
                return 2;
            }
        }

        // Vertical check
        if (array[0][i] == array[1][i] &&
            array[1][i] == array[2][i])
        {
            if (array[0][i] == 'X')
            {
                return 1;
            }

            if (array[0][i] == 'O')
            {
                return 2;
            }
        }
    }
    // Main diagonal
    if (array[0][0] == array[1][1] &&
        array[1][1] == array[2][2])
    {
        if (array[1][1] == 'X')
        {
            return 1;
        }

        if (array[1][1] == 'O')
        {
            return 2;
        }
    }

    // Opposite diagonal
    if (array[0][2] == array[1][1] &&
        array[1][1] == array[2][0])
    {
        if (array[1][1] == 'X')
        {
            return 1;
        }

        if (array[1][1] == 'O')
        {
            return 2;
        }
    }

    return 0;
}

void turn(int count)
{
    cout << ((count % 2 == 0) ? " X's turn.\n" : " O's turn.\n");
}

int inputvalidation(int *count)
{

    int value;
    string line;

    turn(*count);

    cout << " Enter the position: ";
    getline(cin, line);

    stringstream input(line);

    if (!(input >> value))
    {
        cout << " Invalid input. Enter a number.\n";
        return 0;
    }

    input >> ws;

    if (!input.eof())
    {
        cout << " Invalid input. Enter only one integer.\n";
        return 0;
    }

    if (value < 1 || value > 9)
    {
        cout << " Invalid Position choose between 1 and 9.\n";
        return 0;
    }

    return value;
}

int InputOnBoard(char (*ptrArray)[3], int *count)
{
    int winVal = 0;

    while (winVal == 0 && *count < 9)
    {
        int value = inputvalidation(count);

        if (value == 0)
        {
            cout << " Enter a valid input.\n";
            continue;
        }

        int row = (value - 1) / 3;
        int column = (value - 1) % 3;

        if (ptrArray[row][column] == 'X' ||
            ptrArray[row][column] == 'O')
        {
            cout << " position taken. Enter a different one.\n";
            continue;
        }
         
        char symbol = (*count % 2 == 0) ? 'X' : 'O';
        
        ptrArray[row][column] = symbol;

        Board( ptrArray );

        ++(*count);

        winVal = SomeoneWon(ptrArray);
    }

    return winVal;
}

int main()
{

    int counter = 0;
    char arr[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};
    Board(arr);
    int result = InputOnBoard(arr, &counter);

    if (result == 1)
    {
        cout << " X won.";
    }
    else if (result == 2)
    {
        cout << " O won.";
    }
    else if (result == 0)
    {
        cout << " Draw.";
    }

    return 0;
}
