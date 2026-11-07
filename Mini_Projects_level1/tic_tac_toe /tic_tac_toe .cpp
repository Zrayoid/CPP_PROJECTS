#include <iostream>
using namespace std;

void Board(char (*arr)[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

int SomeoneWon(char (*array)[3])
{
    int Xcount = 0;
    int Ocount = 0;

    for (int i = 0; i < 3; i++)
    {
        Xcount = 0;
        Ocount = 0;
        for (int j = 0; j < 3; j++)
        {

            if (array[i][j] == 'X')
            {
                Xcount++;
                if (Xcount == 3)
                {
                    return 1;
                }
            }
            if (array[i][j] == 'O')
            {
                Ocount++;
                if (Ocount == 3)
                {
                    return 2;
                }
            }
        }
    }
    for (int j = 0; j < 3; j++)
    {
        Xcount = 0;
        Ocount = 0;
        for (int i = 0; i < 3; i++)
        {
            if (array[j][i] == 'X')
            {
                Xcount++;
                if (Xcount == 3)
                {
                    return 1;
                }
            }
            if (array[j][i] == 'O')
            {
                Ocount++;
                if (Ocount == 3)
                {
                    return 2;
                }
            }
        }
    }

    Xcount = 0;
    Ocount = 0;
    for (int i = 0; i < 3; i++)
    {

        if (array[i][i] == 'X')
        {
            Xcount++;
            if (Xcount == 3)
            {
                return 1;
            }
        }
        if (array[i][i] == 'O')
        {
            Ocount++;
            if (Ocount == 3)
            {
                return 2;
            }
        }
    }

    Xcount = 0;
    Ocount = 0;

    for (int i = 0; i < 3; i++)
    {
        if (array[i][2 - i] == 'X')
        {
            Xcount++;
            if (Xcount == 3)
            {
                return 1;
            }
        }
        if (array[i][2 - i] == 'O')
        {
            Ocount++;
            if (Ocount == 3)
            {
                return 2;
            }
        }
    }

    return 0;
}

void turn(int count)
{
    if (count % 2 == 0)
    {
        cout << " X's turn.\n";
    }
    else
        cout << " O's turn.\n";
}

int inputvalidation(int *count)
{

    int value = 0;
    turn(*count);
    cout << " Cout enter the position: ";
    if (cin >> value)
    {
        if (value >= 10 || value < 0)
        {
            cout << " Invalid input: \n";
        }
        else
        {
            return value;
        }
    }
    else
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << " wrong input.\n";
    }

    return 0;
}

int InputOnBoard(char (*ptrArray)[3], int *count)
{
    int winVal = 0;
    while ( winVal != 1 && winVal != 2 && *count != 9 )
    {
        int value = inputvalidation(count);
        if (value == 0)
        {
            cout << "Enter a valid input.\n";
        }
        else
        {
            int row, column;
            row = (value - 1) / 3;
            column = (value - 1) % 3;
            if (ptrArray[row][column] == 'X' || ptrArray[row][column] == 'O')
            {
                cout << " position taken enter a different one.\n";
            }
            else
            {
                if (*count % 2 == 0)
                {
                    ptrArray[row][column] = 'X';
                    Board(ptrArray);
                    ++*count;
                    winVal = SomeoneWon(ptrArray);
                }
                else
                {
                    ptrArray[row][column] = 'O';
                    Board(ptrArray);
                    ++*count;
                    winVal = SomeoneWon(ptrArray);

                }
            }
        }
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

    if ( result == 1 )
    {
        cout << " X won.";
    }
    else if ( result == 2 )
    {
        cout << " O won.";
    }
    else if ( result == 0)
    {
        cout << " Draw.";
    }

    return 0;
}
