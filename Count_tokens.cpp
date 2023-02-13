#include <iostream>
#include <string>
#include <fstream>
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

bool is_identifier(const string &token)
{
    if (!isalpha(token[0]) && token[0] != '_')
    {
        return false;
    }

    for (int i = 1; i < token.size(); i++)
    {
        if (!isalnum(token[i]) && token[i] != '_')
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ifstream input_file("Count_tokens.cpp");
    
    if (!input_file.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    int keyword_count = 0;
    int identifier_count = 0;
    string token;
    while (input_file >> token)
    {
        if (is_keyword(token))
        {
            keyword_count++;
        }
        else if (is_identifier(token))
        {
            identifier_count++;
        }
    }

    cout << "Number of keywords: " << keyword_count << endl;
    cout << "Number of identifiers: " << identifier_count << endl;

    input_file.close();
    return 0;
}
