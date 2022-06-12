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

void inOrder_Treaversal(node *root)
{
    if (root != NULL)
    {
        inOrder_Treaversal(root->left);
        cout << root->data << endl;
        inOrder_Treaversal(root->right);
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

node *inorderPredecessor(node *root) // for finding the predecessor of the node that want to be deleted.
{
    root = root->left; // for finding the inorder Predecessor of the given tree.
    while (root->right != NULL) // Font Ligatures 🤩🤩
    {
        root = root->right; // Inorder Predecessor of the node which we want to delete.
    }
    return root;
}
node *deletion_in_the_BST(node *root, int value) // to perform the deletion in the given Binary tree etc.
{

    static node *inPre; // for retaining the value of  the iPre.
    // base conditon no 1
    if (root == NULL)
    {
        return NULL;
    }
    // base condition no 2 for deletion of the root node.
    if (root->left == NULL && root->right == NULL)
    {
        delete root; // deleting the leaf node.
        return NULL;
    }

    // Search for the node to be deleted
    if (value < root->data)
    {
        // do the traversal to the left side of the node.
        root->left = deletion_in_the_BST(root->left, value); // doing the recursion for the given tree.
    }
    else if (value > root->data)
    {
        // do the traversal to the right side of  the root
        root->right = deletion_in_the_BST(root->right, value);
    }

    // Perform the deletion Stragety for deleting the node.
    else
    {
        inPre = inorderPredecessor(root);                          // for finding the inorder Predecessor of the node which we want to delete.
        root->data = inPre->data;                                  // copy the data of the predecessor which is found in the root->data which we want to delete.
        root->left = deletion_in_the_BST(root->left, inPre->data); // The Predecessor is Always found in the left child of the node.
        // If the inorder successor is found then the we have to write the deletion_in_the_BST(root->right, inPre->data).
        // because the inorderSuccessor is found always in the right side of the tree.
    }
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
    cout << "Tree Before Deletion" << endl;
    inOrder_Treaversal(head);
    cout << "Tree After Deletion" << endl;
    deletion_in_the_BST(head, 5);
    cout<<head->data; // inorder Predecessor.
    cout<<endl;
    cout<<endl;
    inOrder_Treaversal(head);

    return 0;
}