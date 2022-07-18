#include "tree.h"


Node *findMin_BST(Node *root)
{
    if (root == NULL)
        return NULL;
    
    while (root->left)
    {
        root = root->left;
    }
    return root;

}

Node *findMax_BST(Node *root)
{
    if (root == NULL)
        return NULL;

    while (root->right)
        root = root->right;
    return root;
}

Node *searchNode(Node *root, int num)
{
    if (root == NULL)
        return NULL;
    else if (root->data == num)
        return root;
    else if (root->data > num)
        return searchNode(root->left, num);
    else
        return searchNode(root->right, num);
}


Node *getSuccessor(Node *root, int val)
{
    Node *cur = searchNode(root, val);
    if (cur == NULL)
        return NULL;
    // case 1--> have right subtree
    if (cur->right != NULL)
        return findMin_BST(cur->right);

    // case 2--> No right subtree
    else
    {
        Node *successor = NULL;
        Node *ancestor  = root;
        while (cur != ancestor)
        {
            if (cur->data < ancestor->data)
            {
                successor = ancestor;
                ancestor  = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}


Node *getPioneer(Node *root, int val)
{
    Node *cur = searchNode(root, val);
    if (cur == NULL)
        return NULL;
    if (cur->left != NULL)
        return findMax_BST(cur->left);

    Node *pioneer  = NULL;
    Node *ancestor = root;
    while (cur != ancestor)
    {
        if (cur->data > ancestor->data)
        {
            pioneer  = ancestor;
            ancestor = ancestor->right;
        }
        else
            ancestor = ancestor->left; 
    }
    return pioneer;
}
