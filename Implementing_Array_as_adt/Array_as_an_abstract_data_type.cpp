#include <bits/stdc++.h>
using namespace std;
class ArrayAdt
{
private:
    int total_size;
    int used_size;
    int *ptr;

public:
    ArrayAdt() {}
    ArrayAdt(int tsize, int usize)
    {
        total_size = tsize;
        used_size = usize;
        ptr = new int(total_size * sizeof(int)); // new operator instance for requesting the memory from the heap and *ptr will start  pointing out that memory address.
    }

    void display();
    void setValue();
    void insert(int element, int position);
};

void ArrayAdt::display()
{
    int totalSize;
    int usedSize;
    int remaingSize;
    for (int i = 0; i < used_size; i++)
    {
        // cout<<&ptr[i]<<endl; // it will give the address of the memory
        cout << ptr[i] << endl;
    }

    totalSize = total_size;
    usedSize = used_size;
    remaingSize = total_size - used_size;

    cout << "Total Size is: " << totalSize << endl;
    cout << "Used size is: " << usedSize << endl;
    cout << "remaing size is: " << remaingSize << endl;
}

void ArrayAdt::setValue()
{
    for (int i = 0; i < used_size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> ptr[i];
    }
}

void ArrayAdt::insert(int element, int position)
{
    
    for (int i = 0; i < used_size+1; i++)
    {
        if(i==position){

        }
    }

    ptr[position]=element;
}

int main()
{
    int totalsize;
    int usedSize;
    cout << "Enter the Total Size of abs of array: ";
    cin >> totalsize;
    cout << "Enter the size to be used  of abs of array: ";
    cin >> usedSize;
    ArrayAdt inputValue(totalsize, usedSize);
    cout << "We are running the SetVal now" << endl;
    inputValue.setValue();
    cout << "We are running the show now " << endl;
inputValue.insert(100,2);
    inputValue.display();
    return 0;
}