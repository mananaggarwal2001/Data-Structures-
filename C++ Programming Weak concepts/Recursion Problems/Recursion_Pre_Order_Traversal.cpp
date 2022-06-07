#include <bits/stdc++.h>
using namespace std;
void preOrderTraversal(int number)
{
    cout << number << endl;
    if (number > 2)
    {
        preOrderTraversal(number - 1); // recursive call number 1
        preOrderTraversal(number - 2); // recursive call number 2
        preOrderTraversal(number - 3); // recursive call number 3
    }
}
int main()
{
    int number;
    cout << "Enter the Number for which we want the pre Order traversal:- ";
    cin >> number;
    preOrderTraversal(number);
    return 0;
}