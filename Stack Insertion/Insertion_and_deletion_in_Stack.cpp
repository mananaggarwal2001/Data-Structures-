#include <bits/stdc++.h>
using namespace std;
struct Stack // Implementation of the stack using the structure.
{
    int size;
    int top;
    int *arr; // for allocating the value in the heap memory rathar than the stack memory.
};

class Stack_Class
{
    Stack *object;

protected:
    bool isEmpty(); // for checking the condition whether the stack is empty or full.
    bool isFull();

public:
    void creation();
    void push();
    void pop();
    void display();
    void peek();
    void Stack_top_bottom_operation();
};

void Stack_Class::Stack_top_bottom_operation()
{
    if (isEmpty())
    {
        cout << "Stack UnderFlow !!!!!!!!!!!!!!!!" << endl;
    }
    else
    {
        int stack_top = object->arr[object->top];
        int stack_bottom = object->arr[0];
        cout << "The value of the stack top is: " << stack_top << endl;
        cout << "The value of the stack bottom is: " << stack_bottom << endl;
    }
}

void Stack_Class ::peek() // peek operation in the stack is used to find the value at the given index with respect to the top variable which is used for finding the index.
{
    int position;
    cout << "Start Entering the position from the 1 not from the 0!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    cout << "Enter the position of the element you want in stack from the top: ";
    cin >> position;
    if ((object->top-position +1)<0)
    {
        cout << "Invalid position entered try again!!!!!!! "<<endl;
    }
    else
    {
        int var = object->arr[object->top - position + 1];                               // for checking the value at the given index with respect from the top index value.
        cout << "The value of the stack at the " << position << " position is: " << var; // for showing the value contained in the given position.
    }
    cout << endl;
    // we have done the +1 in the formula int var = object->arr[object->top - position + 1]
    // because we are starting the value from the 1 not from the 0 in the peek operation so that  the layman value can understand what was happening and the noob person can also understand etc.
    // This formula was made considering the top element as the 1st element not 0 etc.
}

bool Stack_Class ::isEmpty()
{
    if (object->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack_Class ::isFull()
{
    if (object->top == object->size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack_Class ::creation()
{
    int s;
    char ch = 'y';
    object->top = -1;
    cout << "Enter the size of the stack: ";
    cin >> s;
    object->size = s;
    object->arr = new int[object->size]; // for allocating the dynamic Memory for storing the values in the stack.
    while (ch == 'y' || ch == 'Y')
    {
        if (isFull())
        {
            cout << "The Stack is Full" << endl;
            break;
        }
        else
        {

            object->top++;
            cout << "Enter the element " << object->top << " : ";
            cin >> object->arr[object->top];
            cout << endl;
            cout << "Do you want to enter more: ";
            cin >> ch;
        }
    }
}

void Stack_Class::display()
{
    for (int i = 0; i <= object->top; i++)
    {
        cout << object->arr[i] << " ";
    }
    cout << endl;
}

void Stack_Class ::push()
{
    if (isFull())
    {
        cout << "Stack OverFlow!!!!!!!!!!!" << endl;
    }
    else
    {
        int element;
        cout << "Enter the element which you want to insert in the Stack: ";
        cin >> element;
        object->top++; // for increamenting the index in the array for performing the push operation.
        object->arr[object->top] = element;
    }
}

void Stack_Class ::pop()
{
    if (isEmpty())
    {
        cout << "Stack UnderFlow!!!!!!!!!!!!" << endl;
    }
    else
    {
        int value = object->arr[object->top]; // for storing the value of the index position top in the value variable.
        object->top--;
        cout << "The Popped out value is :- " << value << endl;
    }
}
int main()
{
    int choice;
    Stack_Class operations;
    do
    {
        cout << "1. Enter the array" << endl;
        cout << "2. Display the stack" << endl;
        cout << "3. Push the element into the stack" << endl;
        cout << "4. pop the value in the stack" << endl;
        cout << "5. Showing the particular value of the stack" << endl;
        cout << "6. Stack top and bottom values display" << endl;
        cout << "7. Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            operations.creation();
            break;
        }
        case 2:
        {
            operations.display();
            break;
        }
        case 3:
        {
            operations.push();
            break;
        }
        case 4:
        {
            operations.pop();
            break;
        }
        case 5:
        {
            operations.peek();
            break;
        }
        case 6:
        {
            operations.Stack_top_bottom_operation();
            break;
        }
        case 7:
        {

            break;
        }

        default:
        {
            cout << "WRONG CHOICE !!!!!!!!!" << endl;
            break;
        }
        }
    } while (choice != 7);
    return 0;
}