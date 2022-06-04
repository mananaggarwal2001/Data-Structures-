#include <bits/stdc++.h>
using namespace std;

// number printing using the recursion from the given number to the 1 number.
void printNumber(int number)
{
    if (number == 1)
    {
        cout << 1;
        return;
    }
    else
    {
        cout << number<<",";
        printNumber(number-1); // recursion function is used for calling the statement.
    }
}

int main()
{
    printNumber(10);
    return 0;
}