#include <bits/stdc++.h>
using namespace std;
stack<char> point;
struct Stack
{
    char ch;
    Stack *next;
};
class Stack_Paranthesis
{
    Stack *top = NULL;
    Stack *ptr;

protected:
    void reset_stack();
    bool pop(char ch);
    void push(char ch);
    bool isEmpty();

public:
    void processing_Results();
};

void Stack_Paranthesis::processing_Results()
{
    string Expression; // string is given and we can also treat them as the array.
    int popcount = 0;
    int pushCount = 0;
    bool result;
    cout << "Enter the Expression Using the Multiple Paranthesis: ";
    cin >> Expression;
    for (int i = 0; Expression[i]!='\0'; i++)
    {
        if (Expression[i] == '(' || Expression[i] == '{' || Expression[i] == '[')
        {
            push(Expression[i]);
            pushCount++;
        }
        else if (Expression[i] == ')' || Expression[i] == '}' || Expression[i] == ']')
        {
            if (isEmpty())
            {
                cout << "Stack is Empty as the Expression is Unbalanced " << endl;
                return;
            }
            else
            {
                result = pop(Expression[i]);
                popcount++;
            }
        }
    }

    if (result && (pushCount == popcount))
    {
        cout << "Expression is Unbalanced as the Pop Operation is failed !!!!!!!" << endl;
    }
    else if (!result && (pushCount == popcount))
    {
        cout << "Expression is Balanced !!!!!!!" << endl;
    }
    else if (pushCount != popcount)
    {
        cout << "Expression is not balanced !!!!!!!!" << endl;
    }
}
void Stack_Paranthesis::reset_stack()
{
    while (top != NULL)
    {
        Stack *ptr = top;
        top = top->next;
        delete ptr;
    }
}

bool Stack_Paranthesis::isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack_Paranthesis::push(char ch)
{
    Stack *new_node = new Stack;
    new_node->ch = ch;
    if (top == NULL)
    {
        top = new_node;
    }
    else
    {
        new_node->next = top;
        top = new_node;
    }
}
bool Stack_Paranthesis::pop(char R_ch)
{
    Stack *new_node = top;
    bool flag = false;
    if ((top->ch == '(' && R_ch == ')') || (top->ch == '{' && R_ch == '}') || (top->ch == '[' && R_ch == ']'))
    {
        top = top->next;
        delete new_node;
    }
    else
    {

        flag = true; // when the pop Operation is failed then the value of the flag value is true.
    }
    return flag;
}
int main()
{
    int choice;
    Stack_Paranthesis operations;
    do
    {
        cout << "1. Result of the Given Expression" << endl;
        cout << "2. Exit" << endl;
        cout << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            operations.processing_Results();
            break;
        }
        case 2:
        {
            break;
        }

        default:
            cout << "Wrong Choice !!!!!!!!!!!!!!!!!!!!" << endl;
            break;
        }
    } while (choice != 2);

    return 0;
}