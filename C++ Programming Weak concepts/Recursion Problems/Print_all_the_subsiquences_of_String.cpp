#include <bits/stdc++.h>
using namespace std;

char ch;
int supplimentryIndex = 0;
void subsiquence_of_String(string str, int index, string newString)
{
    // base condition 1.
    if (index == str.length())
    {
        cout<<newString<<endl;
        return;
    }

    // to be in the string
    subsiquence_of_String(str, index + 1, newString + str[index]); // doing the string concatenation of the given string.
    // choice for coming for  the value of the given alphabet.
    // to not be in the string

    subsiquence_of_String(str, index + 1, newString);
    // we have not to put that character in the string
    // two calls are going on the simuntanuesly for doing the recursion.
    // choice for not coming of the value of the given alphabet.
}

int main()
{
    string enteredString;
    cout << "Enter the String for finding the subsiquences of the string:- ";
    cin >> enteredString;
    subsiquence_of_String(enteredString, 0, "");
    return 0;
}