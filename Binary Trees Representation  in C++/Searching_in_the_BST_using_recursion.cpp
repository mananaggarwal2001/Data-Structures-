#include <bits/stdc++.h>
using namespace std;
// checking if the binary tree is the BST or not
struct node
{
    node *left;
    int data;
    node *right;
};

void inOrderTraversal(node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        cout << root->data << endl;
        inOrderTraversal(root->right);
    }
}

bool is_BST_checking(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {

        is_BST_checking(root->left);
        if (prev != NULL && root->data <= prev->data)
        {
            return false;
        }
        prev = root;
        is_BST_checking(root->right);
    }
    return true;
}

void search_in_BST(node *root, int key)
{
    if (root == NULL)
    {
        cout << "Given value is not Present in the binary search tree" << endl;
        return;
    }
    else
    {
        if (root->data == key)
        {
            cout << "The Given value is Present in the Binary Search Tree!!!!!!" << endl;
            return;
        }
        else if (root->data > key)
        {
            search_in_BST(root->left, key); // recursion call for the left side of the tree.
        }
        else
        {
            search_in_BST(root->right, key); // recursion call for the right side of the tree.
        }
    }
}

node *createnode(int number) // for creating the node
{
    node *root = new node;
    root->data = number;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int main()
{
    node *head = createnode(5);
    node *p1 = createnode(3);
    node *p2 = createnode(6);
    node *p3 = createnode(1);
    node *p4 = createnode(4);

    // created  the binary search tree.
    head->left = p1;
    head->right = p2;

    p1->left = p3;
    p1->right = p4;
    inOrderTraversal(head);  // checking whether the given tree is the binary search tree or not.
    search_in_BST(head, 10); // function call to the search in Binary Search Tree.
    return 0;
}