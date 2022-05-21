#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class Circular_linkedList
{
    Node *head = NULL;

public:
    void Insertion_at_a_given_Position();
    void Deletion_at_a_given_Position();
    void Deletion_of_a_given_value();
    void LinkedList_Creation();
    void Display();
};

void Circular_linkedList::LinkedList_Creation()
{
    Node *ptr = new Node;
    int Number_of_nodes;
    int information;
    cout << "Enter the Number of Nodes you want to create: ";
    cin >> Number_of_nodes;
    for (int i = 0; i < Number_of_nodes; i++)
    {
        Node *currentNode = new Node; // for creating the new node for creating the LinkedList etc.
        cout << "Enter the data of the node " << i + 1 << " : ";
        cin >> information;
        if (head == NULL)
        {
            head = ptr = currentNode;
        }
        currentNode->data = information;
        currentNode->next = NULL;
        ptr->next = currentNode;
        ptr = currentNode;
    }
    ptr->next = head;
}

void Circular_linkedList ::Insertion_at_a_given_Position()
{
    int data, position;
    Node *temp = head;
    Node *insertNode = new Node;

    cout << "Enter the position you want to enter the element: ";
    cin >> position;
    cout << "Enter the data for the node:";
    cin >> data;
    insertNode->data = data;

    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }
    if (position == 1)
    {
        Node *ptr = head;
        ptr = ptr->next;
        while (ptr->next != head) // it will place the ptr node just before the next node.
        {
            ptr = ptr->next;
        }

        insertNode->next = ptr->next;
        ptr->next = insertNode;
        head = ptr->next;
    }
    else
    {
        insertNode->next = temp->next;
        temp->next = insertNode;
    }
}

void Circular_linkedList::Display()
{
    Node *ptr = head; // ptr pointer is used for checking Numbers of nodes in the linked list.
    do
    {
        cout << ptr->data;
        ptr = ptr->next;
        if (ptr == head)
        {
            cout << "";
        }
        else
        {
            cout<<",";
        }

    } while (ptr != head);
    cout<<endl;
}

void Circular_linkedList ::Deletion_at_a_given_Position()
{
    int position;
    Node *temp = head;
    Node *forwardTemp = head;
    cout << "Enter the given position: ";
    cin >> position;

    if (position == 1)
    {
        Node *ptr = head;
        Node *temp = head;
        ptr = ptr->next;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = head->next;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        for (int i = 0; i < position - 2; i++)
        {
            temp = temp->next;
            forwardTemp = temp->next;
        }

        temp->next = forwardTemp->next;
        forwardTemp->next = NULL;
        delete forwardTemp;
    }
}

void Circular_linkedList ::Deletion_of_a_given_value()
{
    int data, position, count = 0;
    bool flag = false;
    cout << "Enter the data Which you want to delete: ";
    cin >> data;
    Node *temp = head;
    temp = temp->next;
    if (head->data == data) // for checking the condition whether the head pointer contain the given data or not.
    {
        Node *ptr = head;
        Node *temp = head;
        ptr = ptr->next;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = head->next;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else if (head->data != data)
    {
        Node *temp = head;
        temp = temp->next;
        Node *ptr = head;
        while (temp != head)
        {
            if (temp->data == data)
            {
                break;
            }
            else if (temp->data != data && temp->next == head)
            {
                break;
            }
            temp = temp->next; // for doing  the traversal of the data.
        }
        while (ptr->next != temp)
        {
            ptr = ptr->next;
        }

        if (temp->next == head && temp->data != data)
        {
            cout << "Element Not Found Terminating !!!!!!!!" << endl; // for checking the condition whether or not we have put the value which is not available in the Circular linked list or not.
        }
        else
        {

            ptr->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }
}

int main()
{
    int choice;
    Circular_linkedList operations;
    do
    {
        cout << "1. Create the Linked List" << endl;
        cout << "2. Display the Linked List" << endl;
        cout << "3. Insert at a given position" << endl;
        cout << "4. Deletion at a given position" << endl;
        cout << "5. Deletion of a given value" << endl;
        cout << "6. Exit";
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            operations.LinkedList_Creation();
            break;
        }
        case 2:
        {
            operations.Display();
            break;
        }
        case 3:
        {
            operations.Insertion_at_a_given_Position();
            break;
        }
        case 4:
        {
            operations.Deletion_at_a_given_Position();
            break;
        }
        case 5:
        {
            operations.Deletion_of_a_given_value();
            break;
        }

        case 6:
        {

            break;
        }

        default:
            cout << "WRONG CHOICE !!!!!!!!!!!!!!!!!!!!!";
            break;
        }
    } while (choice != 6);

    return 0;
}