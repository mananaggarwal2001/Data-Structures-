#include <bits/stdc++.h>
using namespace std;
// Iteration Searching Algorithm for doing searching in the Tree etc.
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

void search_in_BST_iteratively(node *root, int key)
{
    bool flag = false;
    while (root != NULL)
    {

        if (root == NULL)
        {
            cout << "The given Tree is the Empty Binary Search Tree!!!!!!";
        }
        else
        {
            if (key == root->data)
            {
                cout << "Found:- " << root->data << endl;
                flag = true;
                break;
            }
            else if (key < root->data)
            {
                root = root->left;
            }
            else if (key > root->data)
            {
                root = root->right;
            }
        }
    }

    if (flag)
    {
        return;
    }
    else
    {
        cout<<"Element Not found !!!!!!!!!!!!!"<<endl;
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

    search_in_BST_iteratively(head, 5);

    return 0;
}
