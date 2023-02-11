#include <bits/stdc++.h>
#include <map>
#include <string>

using namespace std;

map<pair<string, char>, string> transition_function;

void initialize_transition_function()
{
    transition_function[make_pair("q0", 'i')] = "q1";
    transition_function[make_pair("q1", 'n')] = "q2";
    transition_function[make_pair("q2", 'g')] = "q3";

    for (char c = 'a'; c <= 'h'; c++)
    {
        transition_function[make_pair("q0", c)] = "q0";
        transition_function[make_pair("q1", c)] = "q0";
        transition_function[make_pair("q2", c)] = "q0";
    }

    for (char c = 'j'; c <= 'z'; c++)
    {
        transition_function[make_pair("q0", c)] = "q0";
        transition_function[make_pair("q1", c)] = "q0";
        transition_function[make_pair("q2", c)] = "q0";
    }
}

bool is_accepted(string input_string)
{
    string current_state = "q0";
    for (int i = 0; i < input_string.size(); i++)
    {
        char current_char = input_string[i];
        current_state = transition_function[make_pair(current_state, current_char)];
    }
    return (current_state == "q3");
}

int main()
{
    initialize_transition_function();
    string input_string;
    cout << "Enter the input string: ";
    cin >> input_string;
    if (is_accepted(input_string))
    {
        cout << "Accepted" << endl;
    }
    else
    {
        cout << "Rejected" << endl;
    }
    return 0;
}
