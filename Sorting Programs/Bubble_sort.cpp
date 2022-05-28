#include <bits/stdc++.h>
using namespace std;
class Bubble_class // Template for the Bubble Sort Algorithm checking.
{

public:
    void bubbleSortProcessShow(int arr[], int size);
    void bubbleSort(int Array[], int size);
    bool Checking_Adaptivity(int Array[], int size);
};

void Bubble_class::bubbleSortProcessShow(int *arr, int size)
{

    int temp;
    for (int i = 0; i < size - 1; i++) // number of passes in the array.
    {
        cout << "Working on pass number : " << i + 1 << endl;
        for (int j = 0; j < size - 1 - i; j++) // for positioning the elements in the array.
                                               // size n-1-i is come for the replacing the elements.
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            for (int k = 0; k < size; k++)
            {
                cout << arr[k];
                if (k == size - 1)
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
    }
}

void Bubble_class::bubbleSort(int *Array, int size)
{
    int temp;
    for (int i = 0; i < size; i++) // number of passes.
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (Array[j] > Array[j + 1])
            {
                temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << Array[i];
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

bool Bubble_class::Checking_Adaptivity(int *Array, int size)
{ // if whole array is sorted and check is one in the one pass only then the array is know to be adaptive array.
    bool isSorted = false;
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (Array[j] > Array[j + 1])
            { // checking for the adaptivity.
                isSorted = true;
                break;
            }
        }
    }

    return isSorted;
}
int main()
{
    Bubble_class obj;
    int size;
    int choice;
    cout << "Enter the Size of the Array:- ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the Element " << i + 1 << " :- ";
        cin >> arr[i];
    }
    cout << endl;
    cout << endl;
    do
    {
        cout << "1. Do the Bubble Sort" << endl;
        cout << "2. Show the Process of the Bubble Sort" << endl;
        cout << "3. Check the Adaptivity of the array" << endl;
        cout << "4. Exit" << endl;
        cout << endl;
        cout << "Enter your Choice:- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            obj.bubbleSort(arr, size);
            break;
        }
        case 2:
        {
            obj.bubbleSortProcessShow(arr, size);
            break;
        }
        case 3:
        {
            bool result;
            result = obj.Checking_Adaptivity(arr, size);
            if (result)
            {
                cout << "The given array is not checked in the one pass and hence non adapatable" << endl;
            }
            else
            {
                cout << "The given array is sorted in one pass and hence adaptive " << endl;
            }
            break;
        }
        case 4:
            break;
        default:
            cout << "Wrong choice !!!!!!!!!!!!!!";
            break;
        }

    } while (choice != 4);
}