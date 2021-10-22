#include <bits/stdc++.h>
using namespace std;
void PrintArray(int array[], int size)
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
    cout<<endl;
}

int partition(int Array[], int low, int high)
{
    int pivot = Array[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (Array[i] <= pivot) // we have to find  the element larger than pivot element .
        {
            i++;
        }
        while (Array[j] > pivot) // we have to find the element smaller than pivot element.
        {
            j--;
        }
        if (i < j)
        {
            temp = Array[i];
            Array[i] = Array[j];
            Array[j] = temp;
        }
        /* code */
    } while (i < j);

    temp = Array[low];
    Array[low] = Array[j];
    Array[j] = temp;
    return j;
}

void Quick_Sort(int Array[], int low, int high,int size)
{
    int partitionIndex; // Index of the pivot after partition.
    if (low < high)
    {
        partitionIndex = partition(Array, low, high);
        PrintArray(Array,size);
        Quick_Sort(Array, low, partitionIndex - 1,size);  // sort left sub array.
        Quick_Sort(Array, partitionIndex + 1, high,size); // sort right sub array.
    }
}
int main()
{
    int size;
    cout << "Enter the Numbers of the elements in the array:- ";
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element " << i + 1 << " : ";
        cin >> array[i];
    }

    cout << "Unsorted Array:-" << endl;
    PrintArray(array, size);
    Quick_Sort(array,0,size-1,size);
    cout << "Sorted Array is:-" << endl;
    PrintArray(array, size);

    return 0;
}