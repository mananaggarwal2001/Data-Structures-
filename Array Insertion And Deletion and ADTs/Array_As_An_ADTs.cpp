#include <bits/stdc++.h>
using namespace std;
struct myArray
{
    int total_size; // used for showing the allocated size
    int used_size;  // used for showing that how much size is used
    int *ptr;       // for pointing out the allocated memory which is the form of the type int.
};

// void createArray(myArray *pointer, int tSize,int USize){
//     (*pointer).total_size=tSize;
//     (*pointer).used_size=USize;
//     // int *ptr= (int*)malloc(tSize * sizeof(int)); malloc is used to allocate the memory the data in the heap in the C Language.
//     int *ptr= new int[tSize]; // In C++ we use the new operator for allocating the memory size in the heap.

// }

class ArrayClass
{

public:
    ArrayClass(myArray *pointer, int tSize, int USize)
    {
        pointer->total_size = tSize;
        pointer->used_size = USize;
        pointer->ptr = new int[tSize]; // we are requesting the memory in the heap because when the function is called then the memory of the stack will destroy as soon as the function is called due to this the memory is allocated in the heap not in the stack.
    }

    void show(myArray *marks);
    void setVal(myArray *sample);
};

void ArrayClass::show(myArray *marks)
{
    for (int i = 0; i < marks->used_size; i++)
    {
        cout << (marks->ptr)[i] << endl; // garbage value is shown as the value is not set in any of these memory location.
    }
}

void ArrayClass::setVal(myArray *sampleArray)
{
    for (int i = 0; i < sampleArray->used_size; i++)
    {
        cout<<"Enter the element "<<i+1<<" :- ";
        cin>> (sampleArray->ptr)[i];
    }

}

int main()
{
    myArray marks;

    ArrayClass A1(&marks, 10, 2); // constructor is working in this class case.
                                    // & is used to send the address of that allocated memory.(address of operator)
                                    // * is used to send the value on that given particular address etc. (value at operator)

    cout<<"We are running the set value Now"<<endl;
    A1.setVal(&marks); // used for setting the value.
    cout<<"We are running the Show Now"<<endl;
    A1.show(&marks); // used for showing the value.
    return 0;
}