#include <bits/stdc++.h>
using namespace std;
int counter = 0; // for tracking the index variable
void reverse(string str, int length)
{
    string reversedString;
    if (length==-1)
    {
        return;
    }
    else
    {
        reversedString[counter]= str[length];
        cout<<reversedString[counter];
        counter++;
        reverse(str,length-1); // recursion is used for reversing the string
    }
}
int main()
{
    string givenString, resultantString;
    cout << "Enter the given String:- ";
    cin >> givenString;
    int length = givenString.length();
    reverse(givenString, length);
    return 0;
}