#include <bits/stdc++.h>
using namespace std;
int counter = 0;
void printNumber(int number)
{
    if (counter == number)
    {
        cout << number;
        counter = 0;
        return;
    }
    else
    {
        cout << counter << ",";
        counter++;
        printNumber(number); // performing the recursion for printing the number.
    }
}

int main()
{
    int number;
    cout << "Enter the given number:- ";
    cin >> number;
    printNumber(number);
    return 0;
}