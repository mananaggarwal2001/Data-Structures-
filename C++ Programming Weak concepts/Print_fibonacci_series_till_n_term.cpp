#include <bits/stdc++.h>
using namespace std;
int number1 = 0, number2 = 1, sum;
void fibonacci_Series(int number)
{
    if (number == 2)
    {

        return;
    }
    else
    {
        sum = number1 + number2;
        number1 = number2;
        number2 = sum;
        cout << sum <<" ";
        fibonacci_Series(number - 1); // sending the same number for printing the fibonacci series using the recursion.
    }
}
int main()
{
    int num;
    cout << "Enter the number for which you want the fibonacci Series for :- ";
    cin >> num;
    cout << number1 << " ";
    cout << number2 << " ";
    fibonacci_Series(num);

    return 0;
}