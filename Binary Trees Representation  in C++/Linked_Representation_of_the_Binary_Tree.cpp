#include <bits/stdc++.h>
using namespace std;
// we will use the doubly linked list for representation of the binary tree using the dynamic memory etc.
struct node
{
    int data;
    node *left;  // for handling the left part of the tree
    node *right; // for handling the right part of the tree.
};
// self referencial structure.

node *createNode(int data)
{
    node *head = new node; // creating the new node
    head->data = data;     // setting the data
    head->left = NULL;     // setting the left and right children to null etc.
    head->right = NULL;
    return head; // finally returning the created node.
}

int main()
{
    /*
    // In c language we will allocate the memory by using.
    // node* head= (node*)malloc(sizeof(node));
    node *head = new node; // we will use the new operator for allocating the dynamic memory.
    head->data = 2;
    head->left = NULL;
    head->right = NULL;
    // root node is formed for the binary trees.

    // we will form the 2 nodes namely p1 and p2
    // p1 node is formed.
    node *p1 = new node;
    p1->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    // p2 node is formed

    node *p2 = new node;
    p2->data = 4;
    p2->left = NULL;
    p2->right = NULL;

    // we will link the node of the left and right children.
    head->left = p1;
    head->right = p2;
    */

    // calling the createnode function for creating the node
    // To avoid repetition we have make the function for creating the node.
    struct node *head = createNode(10);
    struct node *p1 = createNode(10);
    struct node *p2 = createNode(10);
    head->left = p1; // same procedure as done above.
    head->right = p2;
    return 0;
}