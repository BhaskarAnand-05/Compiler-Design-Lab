#include <bits/stdc++.h>
#include <string>

using namespace std;

bool is_single_line_comment(string line)
{
    return (line[0] == '/' && line[1] == '/');
}

bool is_multiline_comment_start(string line)
{
    return (line[0] == '/' && line[1] == '*');
}

bool is_multiline_comment_end(string line)
{
    return (line[line.length() - 2] == '*' && line[line.length() - 1] == '/');
}

bool is_comment(string line)
{
    return is_single_line_comment(line) ||
           is_multiline_comment_start(line) ||
           is_multiline_comment_end(line);
}

int main()
{
    string line;
    cout << "Enter a line: ";
    getline(cin,line);

    if (is_comment(line))
    {
        cout << "This is a comment." << endl;
    }
    else
    {
        cout << "This is not a comment." << endl;
    }

    return 0;
}
