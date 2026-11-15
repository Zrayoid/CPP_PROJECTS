#include <iostream>
#include <string>
using namespace std;

int main()
{
    string URL = "https://google.com";
    string domain;
    string protocol;
    bool isValid = true;

    // 1.url must not be empty
    if (URL.empty())
    {
        isValid = false;
    }

    string::size_type protocolLength =
        URL.substr(0, 7) == "http://" ? 7 : URL.substr(0, 8) == "https://" ? 8
                                                                           : 0;

    if (protocolLength != 0)
    {
        domain = URL.substr(protocolLength);

        // 3. domain Cannot be empty
        if (!domain.empty())
        {
            // 5. domain must not contain the dot in the front
            if (domain.front() == '.')
            {
                isValid = false;
            }

            // 6.domain must not contain the dot in the end
            if (domain.back() == '.')
            {
                isValid = false;
            }
        }
        else
        {
            isValid = false;
        }

        // 7.domain must not contain consecutive dots
        for (string::size_type i = 0; i + 1 < domain.length(); i++)
        {
            if (domain[i] == '.' && domain[i + 1] == '.')
            {
                isValid = false;
            }
        }

        // 8.Must Contain at least 1 dot and Characters after dot must be 2 or greater thatn 2
        string::size_type lastdot = domain.rfind('.');
        if (lastdot != string::npos)
        {
            string::size_type characterAfterDot = domain.length() - lastdot - 1;
            if (characterAfterDot < 2)
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
        cout << "URL is valid: " << URL << endl;
    }
    else
    {
        cout << "URL is not valid: " << URL << endl;
    }
    return 0;
}