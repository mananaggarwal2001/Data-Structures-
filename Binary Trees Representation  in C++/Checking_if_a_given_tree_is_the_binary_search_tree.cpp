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


// Modified Inorder Traversal for checking for the binary tree
bool is_BST_checking(node *root) // for checking whether the given tree is the BST Tree or not.
{
    static node *prev = NULL; // the static is used for retaining the value of the previous element.
    if (root != NULL)
    {
        // if (!is_BST_checking(root->left)) // function is called for the left side of the tree.
        // {
        //     return false;
        // }
        is_BST_checking(root->left);
        if (prev != NULL && root->data <= prev->data)
        {
            return false;
        }
        prev = root;
        is_BST_checking(root->right);
    }
    else
    {
        return true;
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
    inOrderTraversal(head); // checking whether the given tree is the binary search tree or not.
    bool result = is_BST_checking(head);
    if (result)
    {
        cout << "The given Tree is the Binary Search Tree";
    }
    else
    {
        cout << "The Given Tree is not the binary Search Tree";
    }
    return 0;
}