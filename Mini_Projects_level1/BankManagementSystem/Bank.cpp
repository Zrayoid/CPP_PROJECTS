
#include <iostream>
#include <limits>
using namespace std;

void createAccount(int AccountNumber[], float Balance[], int &AccountCount)
{
    int accountNumber;
    float Money;

    if (AccountCount >= 100)
    {
        cout << "Account storage is Full, cannot create an account.\n";
        return;
    }

    bool valid = false;

    // Validate account number
    do
    {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        if (cin.fail())
        {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (accountNumber <= 0)
        {
            cout << "Account number must be positive.\n";
        }
        else
        {
            bool exists = false;

            for (int i = 0; i < AccountCount; i++)
            {
                if (AccountNumber[i] == accountNumber)
                {
                    exists = true;
                    break;
                }
            }

            if (exists)
            {
                cout << "Account number already exists.\n";
            }
            else
            {
                valid = true;
            }
        }

    } while (!valid);

    // Validate initial balance
    valid = false;

    do
    {
        cout << "Enter Initial Amount: ";
        cin >> Money;

        if (cin.fail())
        {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (Money < 0)
        {
            cout << "Amount cannot be negative.\n";
        }
        else
        {
            valid = true;
        }

    } while (!valid);

    AccountNumber[AccountCount] = accountNumber;
    Balance[AccountCount] = Money;
    AccountCount++;

    cout << "Account created successfully.\n";
}

void depositeMoney(int AccountNumber[], float Balance[], int ACcount)
{
    float Money;
    int accountNumber;
    int accountIndex = -1;

    if (ACcount == 0)
    {
        cout << "No accounts available. Create an account first.\n";
        return;
    }

    bool valid = false;

    // Find a valid account
    do
    {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        if (cin.fail())
        {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            for (int i = 0; i < ACcount; i++)
            {
                if (accountNumber == AccountNumber[i])
                {
                    accountIndex = i;
                    valid = true;
                    break;
                }
            }

            if (!valid)
            {
                cout << "Account not found. Try again.\n";
            }
        }

    } while (!valid);

    // Validate deposit amount
    valid = false;

    do
    {
        cout << "Enter Amount to Deposit: ";
        cin >> Money;

        if (cin.fail())
        {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (Money <= 0)
        {
            cout << "Amount must be greater than zero.\n";
        }
        else
        {
            valid = true;
        }

    } while (!valid);

    Balance[accountIndex] += Money;

    cout << "Deposit successful.\n";
    cout << "Updated Balance: " << Balance[accountIndex] << endl;
}

void withdrawMoney(int AccountNumber[], float Balance[], int ACcount)
{
    float Money;
    int accountNumber;
    int accountIndex = -1;

    if (ACcount == 0)
    {
        cout << "No accounts available. Create an account first.\n";
        return;
    }

    bool valid = false;

    // Find a valid account
    do
    {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        if (cin.fail())
        {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            for (int i = 0; i < ACcount; i++)
            {
                if (accountNumber == AccountNumber[i])
                {
                    accountIndex = i;
                    valid = true;
                    break;
                }
            }

            if (!valid)
            {
                cout << "Account not found. Try again.\n";
            }
        }

    } while (!valid);

    // Validate withdrawal amount
    valid = false;

    do
    {
        cout << "Enter Amount to Withdraw: ";
        cin >> Money;

        if (cin.fail())
        {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (Money <= 0)
        {
            cout << "Amount must be greater than zero.\n";
        }
        else if (Money > Balance[accountIndex])
        {
            cout << "Insufficient Balance. Enter a smaller amount.\n";
        }
        else
        {
            valid = true;
        }

    } while (!valid);

    Balance[accountIndex] -= Money;

    cout << "Withdrawal successful.\n";
    cout << "Remaining Balance: " << Balance[accountIndex] << endl;
}

void CheckBalance(int AccountNumber[], float Balance[], int AccountCount)
{
    int accountNumber;
    int accountIndex = -1;

    if (AccountCount == 0)
    {
        cout << "No accounts available. Create an account first.\n";
        return;
    }

    bool valid = false;

    // Find a valid account
    do
    {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        if (cin.fail())
        {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            for (int i = 0; i < AccountCount; i++)
            {
                if (accountNumber == AccountNumber[i])
                {
                    accountIndex = i;
                    valid = true;
                    break;
                }
            }

            if (!valid)
            {
                cout << "Account not found. Try again.\n";
            }
        }

    } while (!valid);

    cout << "\nAccount Number: " << AccountNumber[accountIndex] << endl;
    cout << "Account Balance: " << Balance[accountIndex] << endl;
}

void ControlCenter(int AccountNumber[], float Balance[], int &AccountCount)
{
    int choice = 0;

    while (choice != 5)
    {
        cout << "\n<------------Menu-------------->\n"
             << "Press 1 to create Account\n"
             << "Press 2 to Deposit Money\n"
             << "Press 3 to Withdraw Money\n"
             << "Press 4 to Check Account Balance\n"
             << "Press 5 to Exit.\n";

        bool valid = false;

        do
        {
            cout << "Enter your choice: ";
            cin >> choice;

            if (cin.fail())
            {
                cout << "Invalid input. Enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (choice < 1 || choice > 5)
            {
                cout << "Choose a number between 1 and 5.\n";
            }
            else
            {
                valid = true;
            }

        } while (!valid);

        switch (choice)
        {
        case 1:
            createAccount(AccountNumber, Balance, AccountCount);
            break;

        case 2:
            depositeMoney(AccountNumber, Balance, AccountCount);
            break;

        case 3:
            withdrawMoney(AccountNumber, Balance, AccountCount);
            break;

        case 4:
            CheckBalance(AccountNumber, Balance, AccountCount);
            break;

        case 5:
            cout << "Exiting program.\n";
            break;
        }
    }
}

int main()
{
    int AccountNumber[100];
    float Balance[100];
    int AccountCount = 0;

    ControlCenter(AccountNumber, Balance, AccountCount);

    return 0;
}
