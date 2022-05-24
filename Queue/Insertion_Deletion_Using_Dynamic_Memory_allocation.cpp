#include <bits/stdc++.h>
using namespace std;
struct SampleQueue
{
    int size;
    int frontpointer;
    int rearPointer;
    int *ptr; // for allocating the dynamic Memory and to store the address for the particular element in the queue.
};

class S_Queue
{
    SampleQueue *Q;

protected:
    bool isEmpty();
    bool isFull();
    void reset_position();

public:
    S_Queue() // constructor is made for allocating the values of the queue etc.
    {
        Q->size = 1000;
        Q->frontpointer = -1; // for showing the array as the empty array.
        Q->rearPointer = -1;
    }
    void create_queue();
    void enqueue();
    void Dequeue();
    void Display_the_Queue();
};

bool S_Queue::isEmpty()
{
    if (Q->frontpointer > Q->rearPointer)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool S_Queue::isFull()
{
    if (Q->rearPointer == Q->size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void S_Queue::reset_position()
{
    if (Q->frontpointer == Q->rearPointer)
    {
        Q->frontpointer = Q->rearPointer = -1; // for resetting the values to the original value in the queue.
    }
}

void S_Queue::create_queue()
{
    char choice = 'y';
    Q->ptr = new int[Q->size]; // for allocating the dynamic memory.
    int value;
    int count = 0;
    while (choice == 'y' || choice == 'Y')
    {
        if (isFull())
        {
            cout << "Queue is Full !!!!!!!!!!!!" << endl; // for checking whether the queue is full or not.
            return;
        }
        else
        {
            cout << "Enter the value " << count + 1 << " :- ";
            cin >> value;
            if (Q->rearPointer == -1)
            {
                Q->rearPointer++;
                Q->ptr[Q->rearPointer] = value;
                Q->frontpointer=0;
            }
            else
            {
                Q->rearPointer++;
                Q->ptr[Q->rearPointer] = value;
            }
            cout << "Do you want to insert more value:- ";
            cin >> choice;
            count++;
        }
    }
}

void S_Queue::Display_the_Queue()
{
    cout << "The value inside the Queue is :- ";
    for (int i = Q->frontpointer; i <= Q->rearPointer; i++)
    {
        cout << Q->ptr[i];
        if (i == Q->rearPointer)
        {
            cout << "";
        }
        else
        {
            cout << ",";
        }
    }
    cout << endl;
}

void S_Queue::enqueue()
{
    int value;
    if (isFull())
    {
        cout << "Queue is Full !!!!!!!!!" << endl;
    }
    else
    {
        cout << "Enter the value which you want to insert in the Queue:- ";
        cin >> value;
        // enqueue operation will always occur from the rearside of the queue.
        Q->rearPointer++;
        Q->ptr[Q->rearPointer] = value;
        cout << endl;
    }
}

void S_Queue::Dequeue()
{
    int value;
    if (isEmpty())
    {
        cout << "Queue is Empty !!!!!!!!!!!!!" << endl;
        reset_position();
    }
    else
    {
        value = Q->ptr[Q->frontpointer];
        cout << "The Removed Value is :- " << value;
        Q->frontpointer++;
    }

    cout<<endl;
}

int main()
{
    int choice;
    S_Queue obj;

    do
    {

        cout << "1. Queue Creation with elements" << endl;
        cout << "2. Display the Queue" << endl;
        cout << "3. Perform Enqueue Operation" << endl;
        cout << "4. Perform Dequeue Operation" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "Enter your Choice:- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.create_queue();
            break;
        case 2:
            obj.Display_the_Queue();
            break;
        case 3:
            obj.enqueue();
            break;
        case 4:
            obj.Dequeue();
            break;
        case 5:
            break;

        default:
            cout << "Wrong Choice !!!!!!!!!!!!!!!" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}