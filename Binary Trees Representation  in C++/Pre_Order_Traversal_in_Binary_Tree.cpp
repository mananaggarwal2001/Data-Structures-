#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *left;
    int data;
    node *right;
}; // self referencial Structure.
void preOrderTraversal(node *root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        preOrderTraversal(root->left); // doing the recursion operation for the given binary tree.
        preOrderTraversal(root->right);
    }
}

int main()
{
    node *head = new node;
    head->left = NULL;
    head->right = NULL;
    head->data = 12;

    node *p1 = new node;
    p1->left = NULL;
    p1->right = NULL;
    p1->data = 13;

    node *p2 = new node;
    p2->left = NULL;
    p2->right = NULL;
    p2->data = 14;
    node *p6 = new node;
    p6->left = NULL;
    p6->right = NULL;
    p6->data = 18;
    node *p3 = new node;
    p3->left = NULL;
    p3->right = NULL;
    p3->data = 15;
    node *p4 = new node;
    p4->left = NULL;
    p4->right = NULL;
    p4->data = 16;
    node *p5 = new node;
    p5->left = NULL;
    p5->right = NULL;
    p5->data = 17;

    head->left = p1;
    head->right = p2;

    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right= p6;
    preOrderTraversal(head);

    return 0;
}