// Performing the merge sort using the single array.
#include <bits/stdc++.h>
using namespace std;
void PrintArray(int array[], int size) // function used for displaying the array.
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
        if (i == size - 1)
        {
            cout << " ";
        }
        else
        {
            cout << ",";
        }
    }
    cout << endl;
}
void Merge_Sort_procedure(int arr[], int low, int mid, int high)
{
    int T_Arr[high + 1], i, j, k;
    i = low;
    j = mid + 1;
    int count=low;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            T_Arr[count] = arr[i];
            i++;
            count++;
        }
        else if(arr[i] >= arr[j])
        {
            T_Arr[count] = arr[j];
            j++;
            count++;
        }
    }

    while (i <= mid)
    {
        T_Arr[count] = arr[i];
        i++;
        count++;
    }

    while (j <= high)
    {
        T_Arr[count] = arr[j];
        j++;
        count++;
    }

    for (int i = low; i < (high + 1); i++)  // running i from the low will give the answer.
    {
        arr[i] = T_Arr[i]; // while transferring the array the changes would be occur on the same position in the array.
    }
}

void Merge_Sort(int arr[], int low, int high)
{
    int mid;
    if (low<high)
    {
        mid=(low+high)/2; // for doing the partitioning in the array.
        Merge_Sort(arr,low,mid); // for the Sorting of the  left half.
        Merge_Sort(arr,mid+1,high); // for the sorting of the right half.
        Merge_Sort_procedure(arr,low,mid,high); // for the sorting of the array.
    }

}

int main()
{
    int size;
    cout << "Enter the size of the Array: ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element " << i + 1 << " in the Array: ";
        cin >> arr[i];
    }
    Merge_Sort(arr, 0, size-1);
    cout << "Sorted Array is: " << endl;
    PrintArray(arr,size);

    return 0;
}