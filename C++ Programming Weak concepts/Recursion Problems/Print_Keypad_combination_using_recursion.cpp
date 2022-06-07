#include <bits/stdc++.h>
using namespace std;
string arr[] = {".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
string combinedString;
void print_keypad_combination(string givenString, int givenIndex, int index, string newString)
{
    int mapper_number = int(givenString[givenIndex]);
    int originalnumber = mapper_number - '0';
    if (index == combinedString.length()+1)
    {
        cout << newString << endl;
        return;
    }
    if (givenIndex != givenString.length())
    {
        combinedString += arr[originalnumber];
        print_keypad_combination(givenString, givenIndex + 1, index, newString);
    }
    else
    {
        // choice no 1:- we have to include the given character of the string.
        print_keypad_combination(givenString, givenIndex, index + 1, newString + combinedString[index]);
        // choice no 2:- we do not have to include the given character of the string.
        print_keypad_combination(givenString, givenIndex, index + 1, newString);

    }
}

int main()
{
    string numberEntered;
    cout << "Enter the number for which you want the given combination:- ";
    cin >> numberEntered;
    print_keypad_combination(numberEntered, 0, 0, "");
    return 0;
}