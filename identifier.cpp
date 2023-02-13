#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool is_valid(const string &identifier)
{
    if (!isalpha(identifier[0]) && identifier[0] != '_')
    {
        return false;
    }

    for (int i = 1; i < identifier.size(); i++)
    {
        if (!isalnum(identifier[i]) && identifier[i] != '_')
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string identifier;
    cout << "Enter an identifier: ";
    cin >> identifier;

    if (is_valid(identifier))
    {
        cout << "Valid identifier" << endl;
    }
    else
    {
        cout << "Invalid identifier" << endl;
    }

    return 0;
}
