#include "tree.h"


Node *deleteNode(Node *root, int val)
{
    if (root == NULL)
        return root;
    else if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);

    // find node
    else {      
        //case 1--> no childNode
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        //case 2--> no leftChild
        else if (root->left == NULL)
        {
            Node *tmp = root;
            root = root->right;
            free(tmp);
        }
        //case 3--> no rightChild
        else if (root->right == NULL)
        {
            Node *tmp = root;
            root = root->left;
            free(tmp);
        }
        //case 4--> have twoChild
        else
        {
            Node *tmp = findMin_BST(root->right);
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
        }
    }
    return root;
}
