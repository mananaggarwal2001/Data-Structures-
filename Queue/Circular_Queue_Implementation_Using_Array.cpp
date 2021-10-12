#include <bits/stdc++.h>
using namespace std;
class Queue_Circular
{
    array<int, 4> arr;
    int frontInd = 0;
    int rearInd = 0;

protected:
    bool isEmpty();
    bool isFull();
    void reset_pos2(); // when the array is ended then we will use the reset_pos2
public:
    void insertion_elements();
    void enque();
    void dequeue();
    void display();
};

void Queue_Circular::dequeue()
{
    if (isEmpty())
    {
        cout << "The Queue is Empty" << endl;
        frontInd = rearInd = 0;
        return;
    }
    else
    {
        int element = arr[frontInd];
        cout << "The Element Which is deleted is: " << element << endl;
        frontInd++;
    }
}

void Queue_Circular::enque()
{
    if (isFull())
    {
        cout<<"The Queue is Full"<<endl;
        rearInd++;
        return;
    }
    else
    {
        int element;
        cout << "Enter the element which you want to insert in the Circular queue: ";
        cin >> element;

        arr[rearInd] = element;
        rearInd++;
    }
}

void Queue_Circular::display()
{

    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {

        cout << "The elements in the Array: ";
        for (int i = frontInd; i < rearInd; i++)
        {
            if (i == rearInd - 1)
            {
                cout << arr[i] << " ";
            }
            else
            {
                cout << arr[i] << ",";
            }
        }
    }
    cout << endl;
}

void Queue_Circular::insertion_elements()
{
    char ch = 'y';
    int element;
    int count = 0;
    while (ch == 'y' || ch == 'Y')
    {
        if (isFull())
        {
            cout << "Queue is Full";
            rearInd++;
            return;
        }
        else
        {
            cout << "Enter the element " << count + 1 << " in the Circular Queue: ";
            cin >> element;
            if ((frontInd == 0 && rearInd == 0))
            {
                arr[rearInd] = element;
                rearInd++;
                count++;
            }
            else
            {
                arr[rearInd] = element;
                rearInd = (rearInd + 1) % (arr.size()); // circular Increament in the queue.
                count++;
            }

            cout << "Do you want to enter more: ";
            cin >> ch;
        }
    }
}

bool Queue_Circular::isEmpty()
{
    if (frontInd == rearInd)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Queue_Circular::isFull()
{
    if (rearInd == arr.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Queue_Circular::reset_pos2()
{
    frontInd = rearInd = -1;
}

int main()
{
    int choice;
    Queue_Circular operations;
    do
    {
        cout << "1. Insertion in the circular Queue" << endl;
        cout << "2. Display in the Circular Queue" << endl;
        cout << "3. Perform the Enqueue Operation in Circular Queue" << endl;
        cout << "4. Perform the Dequeue in Circular Queue" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            operations.insertion_elements();
            break;
        }
        case 2:
        {
            operations.display();
            break;
        }
        case 3:
        {
            operations.enque();
            break;
        }
        case 4:
        {
            operations.dequeue();
            break;
        }
        case 5:
        {

            break;
        }

        default:
        {
            cout << "WRONG CHOICE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
            break;
        }
        }

    } while (choice != 5);

    return 0;
}