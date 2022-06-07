// to check if the array is sorted in the strictly increasing order or not.
#include <bits/stdc++.h>
using namespace std;
int counter = 1, updatedValue = -1, index = 0;
bool flag = false;
void checkSort(int arr[], int length)
{
    // base condition for the termination of the recursion when all the things is true.
    if (index == length - 1)
    {
        if (flag)
        {
            cout << "The given array is the sorted array !!!!!!!" << endl;
        }
        index = 0;
        return;
    }

    if (arr[index] < arr[index + 1])
    {
        flag = true;
    }
    else
    {
        flag = false;

        cout << "The given array is not sorted array !!!!!!!!" << endl;
        index = 0;
        return;
    }
    index++;
    checkSort(arr, length); // recursion procedure for  checking forh the sorted array.
}
int main()
{
    int length;
    cout << "Enter the length of the array:- ";
    cin >> length;
    int arr[length];
    cout << "Enter the elements of the array:- ";
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
    checkSort(arr, length);

    return 0;
}