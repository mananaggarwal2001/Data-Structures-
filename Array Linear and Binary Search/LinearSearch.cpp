#include <bits/stdc++.h>
using namespace std;
int main()
{
    int number, elementToBeSearched, position;
    bool flag = false;
    cout << "Enter the Number of Elements in the array :-";
    cin >> number;
    int array[number];
    for (int i = 0; i < number; i++)
    {
        cout << "Enter the " << i << " Element:- ";
        cin >> array[i];
    }
    cout << "Enter the Element to be Searched:-";
    cin >> elementToBeSearched;
    for (int i = 0; i < number; i++)
    {
        if (elementToBeSearched == array[i])
        {
            flag = true;
            position = i;
            break;
        }
    }

    if (flag)
    {
        cout << "Element is found at position:-" << position+1;
    }
    else
    {
        cout<<"Element is not found! Srry try new element";
    }

    
}