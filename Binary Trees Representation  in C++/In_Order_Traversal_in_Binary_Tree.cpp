#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *left;
    node *right;
    int data;
};

node *createnode(int number) // for creating the node
{
    node *root = new node;
    root->data = number;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void InOrderTraversal(node *root)
{
    if (root != NULL)
    {
        InOrderTraversal(root->left);
        cout<<root->data<<endl;
        InOrderTraversal(root->right);
    }
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
    InOrderTraversal(head); // function calling for the InOrderTraversal.

    return 0;
}