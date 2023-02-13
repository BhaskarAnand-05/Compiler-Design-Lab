// #include <bits/stdc++.h>
// #include <map>
// #include <string>

// using namespace std;

// map<pair<string, char>, string> transition_function;

// void initialize_transition_function()
// {
//     transition_function[make_pair("q0", 'i')] = "q1";
//     transition_function[make_pair("q1", 'n')] = "q2";
//     transition_function[make_pair("q2", 'g')] = "q3";

//     for (char c = 'a'; c <= 'h'; c++)
//     {
//         transition_function[make_pair("q0", c)] = "q0";
//         transition_function[make_pair("q1", c)] = "q0";
//         transition_function[make_pair("q2", c)] = "q0";
//     }

//     for (char c = 'j'; c <= 'z'; c++)
//     {
//         transition_function[make_pair("q0", c)] = "q0";
//         transition_function[make_pair("q1", c)] = "q0";
//         transition_function[make_pair("q2", c)] = "q0";
//     }
// }

// bool is_accepted(string input_string)
// {
//     string current_state = "q0";
//     for (int i = 0; i < input_string.size(); i++)
//     {
//         char current_char = input_string[i];
//         cout<<current_char;
//         current_state = transition_function[make_pair(current_state, current_char)];
//     }
//     return (current_state == "q3");
// }

// int main()
// {
//     initialize_transition_function();
//     string input_string;
//     cout << "Enter the input string: ";
//     cin >> input_string;
//     if (is_accepted(input_string))
//     {
//         cout << "Accepted" << endl;
//     }
//     else
//     {
//         cout << "Rejected" << endl;
//     }
//     return 0;
// }
#include <iostream>
#define max 100
int main()
{
    char str[max], f = 'a';
    int i;
    printf("enter the string to be checked: ");
    scanf("%s", str);
    for (i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        switch (f)
        {
        case 'a':
            if (ch == 'i')
                f = 'b';
            else if ((ch >= 'a' && ch < 'i') || (ch > 'i' && ch <= 'z'))
                f = 'a';
            break;
        case 'b':
            if (ch == 'n')
                f = 'c';
            else if (((ch >= 'a' && ch < 'i') || (ch > 'i' && ch <= 'z')) && ((ch >= 'a' && ch < 'n') || (ch > 'n' && ch <= 'z')))
                f = 'a';
            else if (ch == 'i')
                f = 'b';
            break;
        case 'c':
            if (ch == 'g')
                f = 'd';
            else if (((ch >= 'a' && ch < 'i') || (ch > 'i' && ch <= 'z')) && ((ch >= 'a' && ch < 'g') || (ch > 'g' && ch <= 'z')))
                f = 'a';
            else if (ch == 'i')
                f = 'b';
            break;
        case 'd':
            if ((ch >= 'a' && ch <= 'z'))
                f = 'a';
            break;
        }
    }
    if (f == 'd')
        printf("String is accepted", f);
    else
        printf("String is not accepted", f);
    return 0;
}