// Performing the merge sort using the Multiple Subarray.
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

void Merging(int Sub_Array1[], int Sub_Array2[], int CombinedArray[], int sub_size1, int sub_size2, int combined_size3)
{
    int count_1, i, j, k;
    count_1 = i = j = k = 0;
    while (i < sub_size1 && j < sub_size2)
    {
        if (Sub_Array1[i] <= Sub_Array2[j])
        {
            CombinedArray[count_1] = Sub_Array1[i];
            count_1++;
            i++;
        }
        else if (Sub_Array1[i] >= Sub_Array2[j])
        {
            CombinedArray[count_1] = Sub_Array2[j];
            count_1++;
            j++;
        }
    }

    while (i < sub_size1)
    {
        CombinedArray[count_1] = Sub_Array1[i]; // copy all remaning elements to the resultant array etc.
        count_1++;
        i++;
    }
    while (j < sub_size2)                       // copy all remaning elements to  the resultant array etc.
    {
        CombinedArray[count_1] = Sub_Array2[j];
        count_1++;
        j++;
    }
}
int main()
{
    int size1, size2, combinedSize;
    cout << "Enter the size of the First Array: ";
    cin >> size1;
    cout << "Enter the size of the Second Array: ";
    cin >> size2;
    combinedSize = size1 + size2;
    int arr1[size1], arr2[size2], combined_Arr[combinedSize];
    cout << "Enter the elements for the sub array 1" << endl;
    for (int i = 0; i < size1; i++)
    {
        cout << "Enter the element " << i + 1 << " : ";
        cin >> arr1[i];
    }
    cout << "Enter the elements for the sub array 2" << endl;
    for (int i = 0; i < size2; i++)
    {
        cout << "Enter the element " << i + 1 << " : ";
        cin >> arr2[i];
    }
    Merging(arr1, arr2, combined_Arr, size1, size2, combinedSize);
    cout<<"The Sorted Array is: "<<endl;
    PrintArray(combined_Arr, combinedSize);

    return 0;
}