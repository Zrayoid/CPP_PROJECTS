#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    string email = " asadfd@mailg.com";
    string localPart;
    string domain;

    bool dotAtBeginning = false;
    bool dotAtEnd = false;
    bool isValid = true;

    string::size_type atPos = email.find("@");
    if (atPos != string::npos)
    {
        string::size_type atPos2 = email.find("@", atPos + 1);
        if (atPos2 != string::npos)
        {
            isValid = false;
        }
        else
        {
            localPart = email.substr(0, atPos);
            domain = email.substr(atPos + 1);
        }
    }
    else
    {
        isValid = false;
    }

    if (localPart.empty())
    {
        isValid = false;
    }

    if (domain.empty())
    {
        isValid = false;
    }

    if (domain.back() == '.')
    {
        dotAtEnd = true;
        isValid = false;
    }

    if (domain.front() == '.')
    {
        dotAtBeginning = true;
        isValid = false;
    }

    bool consecutiveDots = false;
    for (string::size_type i = 0; i + 1 < domain.length(); i++)
    {
        // checks if the domain has consecutive dots
        if (domain[i] == '.' && domain[i + 1] == '.')
        {
            consecutiveDots = true;
            isValid = false;

            break;
        }
    }

    string::size_type lastDot = domain.rfind('.');

    if (lastDot != string::npos)
    {
        string::size_type characterAfterDot = domain.length() - lastDot - 1;

        if (characterAfterDot < 2)
        {
            isValid = false;
        }
    }
    else
    {
        isValid = false;
    }

    if (isValid)
    {
        cout << "Valid Email\n";
    }
    else
    {
        cout << "Invalid Email\n";
    }

    return 0;
}
