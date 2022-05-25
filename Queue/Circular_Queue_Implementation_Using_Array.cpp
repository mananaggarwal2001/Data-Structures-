#include <bits/stdc++.h>
using namespace std;
struct C_Queue
{
    int size;
    int front_Pointer;
    int rear_pointer;
    int *arr; // for allocating the dynamic Memory and using it efficiently.
};

class C_Queue_Class
{
    C_Queue *Q;

protected:
    bool isEmpty();
    bool isFull();
    void reset_position();

public:
    C_Queue_Class()
    {
        Q->size = 4; // only n-1 elements will be entered as one block is reserved when both the pointers front and the rear come at the same block etc.
        Q->front_Pointer = -1;
        Q->rear_pointer = -1;
    }
    void enqueue();
    void display_the_Queue();
    void dequeue();
    void Create_Queue();
};

void C_Queue_Class::reset_position()
{
    Q->front_Pointer = Q->rear_pointer = -1; // for resetting the position default value in the circular queue.
}

bool C_Queue_Class::isFull()
{
    // When both the pointer reach to the 0 index then we can say that the Queue is Full etc.
    // When the Queue rear Pointer is just 1 step behind the Q->front_pointer then we can say that the Queue is full.
    if ((Q->rear_pointer + 1) % Q->size == Q->front_Pointer)
    {
        return true; // one value will always be empty in the Queue which when the rear and the front value is empty always etc.
    }
    else
    {
        return false;
    }
}

bool C_Queue_Class::isEmpty()
{
    if (Q->rear_pointer == Q->front_Pointer)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void C_Queue_Class::enqueue()
{
    int value;
    cout << "Enter the value which you want to insert in the circular Queue:- ";
    cin >> value;
    if (isFull())
    {
        cout << "Queue is Full !!!!!!!!!!!!!!!" << endl;
        return;
    }
    else
    {
        Q->rear_pointer = (Q->rear_pointer + 1) % Q->size; // for increamenting the circular queue
        // as when we divide the queue with the last index it will then reset to zero etc.
        Q->arr[Q->rear_pointer] = value; // for inserting the value in the circular queue etc.
    }
}

void C_Queue_Class::dequeue()
{
    int value;
    if (isEmpty())
    {
        cout << "The Queue is Empty!!!!!!!!!!!!!!!!!!!" << endl;
        reset_position();
        return;
    }
    else
    {
        Q->front_Pointer = (Q->front_Pointer + 1) % Q->size; // for removing the element in the array.
        value = Q->arr[Q->front_Pointer];
        cout << "The Dequeued Value is :- " << value << endl;
    }
}

void C_Queue_Class::Create_Queue()
{
    int value;
    char ch = 'y';
    int count = 0;
    Q->arr = new int[Q->size];
    while (ch == 'y' || ch == 'Y')
    {
        if (isFull())
        {
            cout << "Queue is Full !!!!!!!!!!!!!" << endl;
            return;
        }
        else
        {
            cout << "Enter the value " << count + 1 << " :- ";
            cin >> value;
            if (Q->rear_pointer == -1)
            {
                Q->rear_pointer = 0;
                Q->front_Pointer = 0;
                // one space is reserved when both the front pointer and the rearPointer will be at the same posiiton etc.
                // for intializing the value of the front pointer.
                // for pointing out the value to the last element in the circular queue.
                // as due to the index starting from the zero element.
                // one block of element is reserved when both the pointer is at the same position etc.
            }

            Q->rear_pointer = (Q->rear_pointer + 1) % Q->size; // using the circular increament for creating the circular queue.
            Q->arr[Q->rear_pointer] = value;

            cout << "Do you want to enter more value :- ";
            cin >> ch;
            count++;
        }
    }
}

void C_Queue_Class::display_the_Queue()
{
    // the number of  the elements in the queue is the n-1 as one element is reserved for when the both the
    // front pointer and  the rear pointer will be at the same position and this indicate that  the queue empty.
    cout << "The value in the circular Queue is :- ";
    for (int i = Q->front_Pointer + 1; i <= Q->rear_pointer; i++)
    {
        cout << Q->arr[i];
        if (i == Q->rear_pointer)
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

int main()
{
    int choice;
    C_Queue_Class obj;
    do
    {
        cout << "1. Create the Circular Queue" << endl;
        cout << "2. Display the Queue" << endl;
        cout << "3. Perform the Enqueue Operation" << endl;
        cout << "4. Perform the Dequeue Operation" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "Enter your choice:- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.Create_Queue();
            break;
        case 2:
            obj.display_the_Queue();
            break;
        case 3:
            obj.enqueue();
            break;
        case 4:
            obj.dequeue();
            break;
        case 5:
            break;

        default:
            cout << "Wrong Choice !!!!!!!!!!!!!!!!!!!!!!" << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}