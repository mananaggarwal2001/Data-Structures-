#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *left;
    node *right;
    int data;
};

class tree_class
{
    node *root = NULL;

protected:
    node *createNode(int value);   // To create the new Node for the given binary tree.
    node *inOrderPrev(node *root); // for finding the inorder previous of the node to Perform the deletion in the binary search tree.
public:
    node *Create_the_binary_search_tree();                  // done
    bool Checking_the_given_tree_is_BST_or_Not(node *root); // done
    void post_order_traversal(node *root);                  // done
    void In_order_traversal(node *root);                    // done
    void Pre_Order_traversal(node *root);                   // done
    void Search_operation_in_BST(node *root, int value);    // done
    void insertion_in_the_BST(node *root, int value);
    node *Deletion_in_the_BST(node *root, int value);
};

node *tree_class::inOrderPrev(node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

node *tree_class::Deletion_in_the_BST(node *root, int value)
{
    // by performing the recursion search for finding the value and deleting  the value in the given binary tree.
    // base condition 1
    static node *inprev;
    if (root == NULL)
    {
        cout << "The value is not Found in the Given Binary Tree to delete !!!!!!!!!!!!" << endl;
        return NULL;
    }
    // base condition 2 when the node is the leaf node then to perfrom the deletion of that node.
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        cout << "deletion Performed Successfully!!!!!!!!!" << endl;
        return NULL;
    }
    if (value > root->data)
    {
        root->right = Deletion_in_the_BST(root->right, value);
    }
    else if (value < root->data)
    {
        root->left = Deletion_in_the_BST(root->left, value);
    }
    else
    {
        inprev = inOrderPrev(root); // to find the previous inorder child for the node which we want to delete.
        root->data = inprev->data;
        root->left = Deletion_in_the_BST(root->left, inprev->data);
    }
    return root;
}
void tree_class::insertion_in_the_BST(node *root, int value)
{
    node *prev;
    while (root != NULL)
    {
        prev = root; // for tracking the root node if null then prev node will hang to the last leaf node which is either samlller than the value or bigger than the value.
        if (root->data == value)
        {
            cout << "The Duplicate is found in the given Binary Search Tree!!!" << endl;
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
    node *newNode = createNode(value); // for creating the new node.
    if (value < prev->data)
    {
        prev->left = newNode;
    }
    else if (value > prev->data)
    {
        prev->right = newNode;
    }

    cout << "Insertion of the value " << value << " is Sucessfully done !!!!!!!! " << endl;
}

void tree_class::Search_operation_in_BST(node *root, int value)
{

    if (root == NULL) // base condition no 1 for the termination of the recursion.
    {
        cout << "The Value is not Found in the given binary Search Tree!!!!!!" << endl;
        return;
    }
    if (root->data < value)
    {
        Search_operation_in_BST(root->right, value);
    }
    else if (root->data > value)
    {
        Search_operation_in_BST(root->left, value);
    }
    else if (root->data == value)
    {
        cout << "Found:- " << root->data << endl;
        return;
    }
}

bool tree_class::Checking_the_given_tree_is_BST_or_Not(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        Checking_the_given_tree_is_BST_or_Not(root->left);
        if (prev != NULL && prev->data >= root->data)
        {
            return false;
        }
        prev = root;
        Checking_the_given_tree_is_BST_or_Not(root->right);
    }
    return true;
}

void tree_class::Pre_Order_traversal(node *root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        Pre_Order_traversal(root->left);
        Pre_Order_traversal(root->right);
    }
}
void tree_class::post_order_traversal(node *root)
{
    if (root != NULL)
    {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        cout << root->data << endl;
    }
}

void tree_class::In_order_traversal(node *root)
{
    if (root != NULL)
    {
        In_order_traversal(root->left);
        cout << root->data << endl;
        In_order_traversal(root->right);
    }
}

node *tree_class::Create_the_binary_search_tree()
{
    int p_node, p1_node, p2_node, p3_node, p4_node;
    cout << "Enter the value for the root Node:- ";
    cin >> p_node;
    cout << "Enter the value for the P1 Node:- ";
    cin >> p1_node;
    cout << "Enter the value for the P2 Node:- ";
    cin >> p2_node;
    cout << "Enter the value for the P3 Node:- ";
    cin >> p3_node;
    cout << "Enter the value for the P4 Node:- ";
    cin >> p4_node;

    node *P_node = createNode(p_node);
    node *P1_node = createNode(p1_node); // Function for creating the node.
    node *P2_node = createNode(p2_node);
    node *P3_node = createNode(p3_node);
    node *P4_node = createNode(p4_node);
    // node *head = createnode(5);
    // node *p1 = createnode(3);
    // node *p2 = createnode(6);
    // node *p3 = createnode(1);
    // node *p4 = createnode(4);

    if (root == NULL)
    {
        root = P_node;
    }

    //         root
    //       //    \\
    //       p1     p2       Structure of the binary Search Tree formed etc....
    //     // \\
    //     p3  p4
    root->left = P1_node;
    root->right = P2_node;

    P1_node->left = P3_node;
    P1_node->right = P4_node;

    return root;
}

node *tree_class::createNode(int value)
{
    node *ptr = new node;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->data = value;
    return ptr; // for returning the value to the calling statement.
}

int main()
{
    int choice;
    tree_class obj;
    node *rootNode;
    do
    {
        cout << "1. Create the Binary Search Tree" << endl;
        cout << "2. Check Whether the Tree is the Binary search Tree or not." << endl;
        cout << "3. Perform the Post-Order Traversal of the given Tree" << endl;
        cout << "4. Perform the In-Order Traversal of the given Tree" << endl;
        cout << "5. Perform the Pre-Order Traversal of the given Tree" << endl;
        cout << "6. Perform the Search Operation in the Binary Search Tree." << endl;
        cout << "7. Perform the Insertion in the Binary Search Tree." << endl;
        cout << "8. Perform the Deletion in the Binary Search Tree." << endl;
        cout << "9. Exit." << endl;
        cout << endl;
        cout << endl;
        cout << "Enter your choice:- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            rootNode = obj.Create_the_binary_search_tree();
            break;
        }
        case 2:
        {
            bool result = obj.Checking_the_given_tree_is_BST_or_Not(rootNode);
            if (result)
            {
                cout << "The Given Tree is the Binary Search Tree!!!!!!" << endl;
            }
            else
            {
                cout << "The Given Tree is not the Binary Search Tree!!!!!!" << endl;
            }
            break;
        }
        case 3:
        {
            obj.post_order_traversal(rootNode);
            break;
        }
        case 4:
        {
            obj.In_order_traversal(rootNode);
            break;
        }
        case 5:
        {
            obj.Pre_Order_traversal(rootNode);
            break;
        }
        case 6:
        {
            int value;
            cout << "Enter the value that you want to search in the given Tree:- ";
            cin >> value;
            obj.Search_operation_in_BST(rootNode, value);
            break;
        }
        case 7:
        {
            int value;
            cout << "Enter the value that you want to insert in the given Binary Search Tree:- ";
            cin >> value;
            obj.insertion_in_the_BST(rootNode, value);
            break;
        }
        case 8:
        {
            int value;
            cout << "Enter the value which you want to delete:- ";
            cin >> value;
            obj.Deletion_in_the_BST(rootNode, value);
            break;
        }
        case 9:
        {
            break;
        }

        default:
            cout << "Wrong Choice Pls Try Again !!!!!!!!!!!!!!!!!";
            break;
        }

    } while (choice != 9);

    return 0;
}