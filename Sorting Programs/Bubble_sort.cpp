#include <bits/stdc++.h>
using namespace std;
void bubbleSortProcessShow(int arr[], int size)
{
    
    int temp;
    for (int i = 0; i < size - 1; i++) // number of passes in the array.
    {
        cout<<"Working on pass number : "<<i+1<<endl;
        for (int j = 0; j < size-1-i; j++) // for positioning the elements in the array.
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
                cout<<arr[k];
                if(k==size-1){
                    cout<<" ";
                }else{
                    cout<<",";
                }

            }

            cout<<endl;

        }
    }
}

void bubbleSort(int Array[],int size){
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-1-i; j++)
        {
            if(Array[j]>Array[j+1]){
                temp=Array[j];
                Array[j]=Array[j+1];
                Array[j+1]=temp;
            }
        }

    }

    for (int i = 0; i < size; i++)
    {
        cout<<Array[i];
        if (i==size-1)
        {
            cout<<" ";
        }else{
            cout<<",";
        }

    }
}

bool Checking_Adaptivity(int Array[],int size){
    bool isSorted=false;
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(Array[j]>Array[j+1]){  // checking for the adaptivity.
                isSorted=true;
                break;
            }
        }

    }

    return isSorted;

}
int main()
{
    int Array[] = {10, 0, 9, 4, 2};
    int A2[]={1,2,3,4,5};
    /*
    pass 1
    {10,0,9,4,2}
    {10,9,0,4,2}
    {10,9,4,0,2}
    {10,9,4,2,0}
    */
    /*
    pass 2
    {10,9,4,2,0} // setting in the decending order .
    */

    int size = 5;
    for (int  i = 0; i < size; i++)
    {
        cout<<Array[i]; // printing the array before sorting.
        if(i==size-1){
            cout<<" ";
        }else{
            cout<<",";
        }
    }
    cout<<endl;
    cout<<"Showing the process of the Bubble Sort: "<<endl;
    bubbleSortProcessShow(Array, size);
    cout<<endl;
    if(Checking_Adaptivity(A2,size)){
        cout<<"The array is not Sorted in one pass"<<endl;
    }else{
        cout<<"The Array is Sorted in one pass"<<endl;
    }
    cout<<"Final Sorted Array is: "<<endl;
    bubbleSort(Array,size);

    return 0;
}