#include <bits/stdc++.h>
using namespace std;

void array_insertion(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element " << i + 1 << " in the array: ";
        cin >> array[i];
        cout << endl;
    }
}

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void insertion_from_the_end(int array[], int size, int element_to_be_inserted)
{
    int big_array[size + 1];
    for (int i = 0; i < size; i++)
    {
        big_array[i] = array[i];
    }

    big_array[size] = element_to_be_inserted;
    display(big_array, size + 1);
}

void insertion_of_element_from_beginning(int array[], int size, int element_to_be_inserted)
{
    int big_array[size + 1];
    for (int i = 0; i < size; i++)
    {
        big_array[i + 1] = array[i];
    }

    big_array[0] = element_to_be_inserted;
    display(big_array, size + 1);
}

void insertion_of_element_at_randompos(int array[],int size, int element_to_be_inserted,int position){
    int big_array[size+1];
    int pos;
    for(int i=0;i<size+1;i++){
        if(i!=position){
            big_array[i]=array[i];
        }else{
            break;
        }
    }

    big_array[position]=element_to_be_inserted;
    for(int i=position,j=position+1;i<size,j<size+1;i++,j++){
        big_array[j]=array[i];
    }

    display(big_array,size+1);
}
int main()
{
    int element_end_insert;
    int choice, size,position;
    int array[size];
    do
    {

        cout << "1. Enter the array" << endl;
        cout << "2. Insertion of the element from the end" << endl;
        cout << "3. Insertion of the element from the beginning" << endl;
        cout << "4. Insertion of the element in the random position" << endl;
        cout << "5. exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter the size of the  array: ";
            cin >> size;
            array_insertion(array, size);

            break;
        }
        case 2:
        {
            cout << "Enter the element that you want to insert in the end: ";
            cin >> element_end_insert;
            insertion_from_the_end(array, size, element_end_insert);
            size += 1;

            break;
        }
        case 3:
        {
            cout << "Enter the element that you want to insert in the end: ";
            cin >> element_end_insert;
            insertion_of_element_from_beginning(array, size, element_end_insert);
            size += 1;

            break;
        }
        case 4:
        {
            cout<<"Enter the position you want to insert the Value: ";
            cin>>position;
            cout<<"Enter the element you want to insert in the array: ";
            cin>>element_end_insert;
            insertion_of_element_at_randompos(array,size,element_end_insert,position);


            break;
        }
        case 5:
        {
            break;
        }
        default:
            cout << "WRONG CHOICE!!!!!!!!!!!!!!!!!!!!!!";
        }
    } while (choice != 5);
}