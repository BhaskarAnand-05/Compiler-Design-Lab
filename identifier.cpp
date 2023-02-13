#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;
const vector<string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "inline", "int", "long", "register", "restrict", "return",
    "short", "signed", "sizeof", "static", "struct", "switch",
    "typedef", "union", "unsigned", "void", "volatile", "while"};

bool is_keyword(const string &token)
{
    for (const auto &keyword : keywords)
    {
        if (token == keyword)
        {
            return true;
        }
    }

    return false;
}
bool is_valid(const string &identifier)
{
    if(is_keyword(identifier))
    {
        return false;
    }
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
