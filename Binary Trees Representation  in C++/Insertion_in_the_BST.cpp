#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *left;
    int data;
    node *right;
};

node *createnode(int number) // for creating the node
{
    node *root = new node;
    root->data = number;
    root->left = NULL;
    root->right = NULL;
    return root;
}



void postOrderTraversal(node *temp)
{
    if (temp != NULL)
    {
        postOrderTraversal(temp->left);
        postOrderTraversal(temp->right);
        cout << temp->data << endl;
    }
}

void insertion_in_BST(node *root, int value)
{
    node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == value)
        {
            cout << "The Duplicate value is Found and Hence the insertion is not allowed!!!!!!!!!!!" << endl;
            return;
        }
        else if (root->data > value)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    node *newNode = new node;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = value;
    if (value > prev->data)
    {
        prev->right = newNode;
    }
    else
    {
        prev->left = newNode;
    }
    cout << "Insertion Done !!!!!!!!!!!!!!" << endl;
}
int main()
{
    node *head = createnode(12); // root node will be printed in the last in the post order traversal.
    node *p1 = createnode(10);
    node *p2 = createnode(100);
    node *p3 = createnode(9);
    node *p4 = createnode(8);
    node *p5 = createnode(7);
    node *p6 = createnode(6);
    node *p7 = createnode(5);
    node *p8 = createnode(4);

    // for attaching the node with the head node.
    head->left = p1;
    head->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    p3->left = p7;
    p3->right = p8;
    cout << "Traversal Before Insertion" << endl;
    cout << endl;
    postOrderTraversal(head);
    cout << "Traversal After Insertion" << endl;
    cout << endl;
    insertion_in_BST(head, 999);
    postOrderTraversal(head);

    return 0;
}