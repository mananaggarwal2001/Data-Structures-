#include <bits/stdc++.h>
using namespace std;
int firstOccurance = -1, lastOccurace = -1;
void F_LOccurance(string str, int length, char character)
{

    if (str[length] == character)
    {
        if (lastOccurace == -1)
        {
            lastOccurace = length;
        }
        else
        {
            firstOccurance = length;
        }
    }

    if (length == -1) // base condition for ending of the recursion
    {
        cout << "The First Occurance of the given character is :- " << firstOccurance << endl;
        cout << "The Last Occurance of the given Character is :- " << lastOccurace << endl;
        firstOccurance = -1;
        lastOccurace = -1;
        return;
    }
    F_LOccurance(str, length - 1, character); // recursive call is made for finding  the element.
}
int main()
{
    string givenString, resultantString;
    char character;
    cout << "Enter the given String:- ";
    cin >> givenString;
    cout << "Enter the character which you want to find the occurance in the given string from the first and the last position:- ";
    cin >> character;
    int length = givenString.length();
    F_LOccurance(givenString, length, character);
    return 0;
}