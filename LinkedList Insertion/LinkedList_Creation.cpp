#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int Number;
    Node *nextToPoint; // self referencial structure. and nexttoPoint Pointer is used to store the address of the Next Node which is made in the linked list.
};

void linkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->Number << endl;  // traversal in the Linked List
        ptr = ptr->nextToPoint;
    }
}

int main()
{
    Node *headNode;
    int number;

    // Allocate the Node Memory in the heap

    headNode = new Node;
    Node *firstNode = new Node;
    Node *secondNode = new Node;
    Node *thirdNode= new Node;
    Node *fourthNode = new Node;

    // Link first and the second node.
    headNode->Number = 12;
    headNode->nextToPoint = firstNode;

    // Link Second and the third node.
    firstNode->Number = 23;
    firstNode->nextToPoint = secondNode;

    // Link the third and the fourth Node.
    secondNode->Number=34;
    secondNode->nextToPoint= thirdNode;

    // Link the fourth and the fifth node.
    thirdNode->Number= 45;
    thirdNode->nextToPoint=fourthNode;

    // Link to the fifth and the sixth node
    fourthNode->Number= 100;
    fourthNode->nextToPoint=NULL;

    linkedListTraversal(headNode);
}
