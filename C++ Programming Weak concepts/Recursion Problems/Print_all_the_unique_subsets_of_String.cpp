#include <bits/stdc++.h>
using namespace std;
static unordered_set<string> setting; // STL is used for finding the unique string in the given substrings in recursion etc.

void subsiquence_of_unique_String(string str, int index, string newString)
{
    // base condition for the termination of the String.
    if (index == str.length())
    {
        if (setting.find(newString) == setting.end())
        {
            cout << newString << endl;
            setting.insert(newString);
            return;
        }
        else
        {
            return;
        }
    }

    // choice no 1 for recursion which is we have to include substring into the new String:-
    subsiquence_of_unique_String(str, index + 1, newString + str[index]);
    // choice no 2 for recursion which is we have to not include the substring into the new string.
    subsiquence_of_unique_String(str, index + 1, newString);
}
int main()
{
    string enteredString;
    cout << "Enter the String for finding the subsiquences of the string:- ";
    cin >> enteredString;
    subsiquence_of_unique_String(enteredString, 0, "");

    return 0;
}