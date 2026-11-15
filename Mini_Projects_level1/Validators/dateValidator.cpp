#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string DATE = "2026/02/24";
    bool isValid = true;
    bool validFormat = false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31};

    if (!DATE.empty() && DATE.length() == 10)
    {
        char separator = DATE[4];
        if ((separator == '/' || separator == '-') && DATE[7] == separator)
        {
            validFormat = true;
            for (string::size_type i = 0; i < DATE.length(); i++)
            {
                if (i == 4 || i == 7)
                {
                    if (DATE[i] != separator)
                    {
                        validFormat = false;
                        break;
                    }
                }
                else if (!isdigit(static_cast<unsigned char>(DATE[i])))
                {
                    validFormat = false;
                    break;
                }
            }
        }
        else
        {
            validFormat = false;
        }
    }

    if (validFormat)
    {
        string Year = DATE.substr(0, 4);
        string Month = DATE.substr(5, 2);
        string Day = DATE.substr(8, 2);

        int yearNum = stoi(Year);
        int monthNum = stoi(Month);
        int dayNum = stoi(Day);

        if (yearNum < 1 || yearNum > 9999)
        {
            isValid = false;
        }

        if ((yearNum % 400 == 0) || (yearNum % 4 == 0 && yearNum % 100 != 0))
        {
            daysInMonth[1] = 29;
        }

        if (monthNum <= 12 && monthNum >= 1)
        {
            int maxDays = daysInMonth[monthNum - 1];
            if (dayNum < 1 || dayNum > maxDays)
            {
                isValid = false;
            }
        }
        else
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
        cout << "DATE is valid: " << DATE << endl;
    }
    else
    {
        cout << "DATE is not valid: " << DATE << endl;
    }
    return 0;
}