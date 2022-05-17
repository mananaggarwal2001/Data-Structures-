#include <bits/stdc++.h>
using namespace std;
int main()
{
    int mid, high, low, number, elementToBeSearch, position = 0;
    bool flag = false;
    cout << "Enter the number of elements in the array:- ";
    cin >> number;
    int array[number];
    for (int i = 0; i < number; i++)
    {
        cout << "Enter the element " << i + 1 << " in the array:- ";
        cin >> array[i];
    }
    int n = sizeof(array) / sizeof(array[0]); // for finding the number of elements which we are taking in the array.
    sort(array, array + n);                   // for sorting the array.
    for (int i = 0; i < number; i++)
    {
        cout << array[i] ;
        if (i == number - 1)
        {
            cout << " ";
        }
        else
        {
            cout<<",";
        }
    }
    cout << endl;

    // cout<<"Enter the Element you want to search:-";
    // cin>> elementToBeSearch;
    low = 0;
    high = number;
    cout << "Enter the Element to be searched:- ";
    cin >> elementToBeSearch;
    while (low <= high)
    {
        // keep searching until the low and the high converges.
        // if not found then return flag value as the false otherwise return the flag value true.

        mid = (high + low) / 2;
        if (elementToBeSearch < array[mid]) // In this the mid element is finding the element in the array etc.
        {
            high = mid - 1;
        }
        else if (elementToBeSearch > array[mid])
        {
            low = mid + 1;
        }
        else if (elementToBeSearch == array[mid])
        {
            flag = true;
            position = mid;
            break;
        }
    }
    if (flag)
    {
        cout << "Position of the element "<< elementToBeSearch <<" is:- " << position << endl;
    }
    else
    {
        cout << "Element Not Found Terminating !!!!!!!!!!!!!!";
    }
}
