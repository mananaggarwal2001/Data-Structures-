#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class D_NodeOperations
{
    Node *nextLink;
    Node *prevLink;
    Node *head;
    Node *left;
    Node *right;

protected:
    void reset_Position()
    {
        left = right = head;
    }

public:
    void LinkedList_creation();
    void traversal_both_directions();
};
void D_NodeOperations::LinkedList_creation()
{
    int Number_of_Nodes, New_data;
    cout << "Enter the number of the nodes: ";
    cin >> Number_of_Nodes;
    for (int i = 0; i < Number_of_Nodes; i++)
    {
        Node *currentNode = new Node;
        cout << "Enter the data " << i + 1 << " for the linked List: " << endl;
        cin >> New_data;
        currentNode->data = New_data;
        currentNode->prev = NULL;
        currentNode->next = NULL;
        if (i == 0)
        {
            nextLink = head = currentNode = prevLink;
        }
        nextLink->next = currentNode;
        nextLink = currentNode;
        nextLink->prev = prevLink;
        prevLink = prevLink->next;
    }
}
void D_NodeOperations::traversal_both_directions()
{
    reset_Position();
    cout << "Forward Direction Display:" << endl;
    while (right != NULL)
    {
        right = right->next;
        cout << left->data << " ";
        left = left->next;
    }

    cout << "Reverse Direction Display: " << endl;
    while (right != head)
    {
        cout << right->data << " ";
        right = right->prev;
    }
    cout << endl;
}

int main()
{
    int choice;
    D_NodeOperations operations;
    do
    {
        cout << "1.Create the doubly Linked List: " << endl;
        cout << "2.Display the doubly Linked List in both Directions" << endl;
        cout << "3.Exit";
        cout << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            operations.LinkedList_creation();
            break;
        }
        case 2:
        {
            operations.traversal_both_directions();
            break;
        }
        case 3:
        {

            break;
        }

        default:
        {
            cout << "Wrong Choice !!!!!!!!!!!!!!!!!!";
            break;
        }
        }
    } while (choice != 3);

    return 0;
}