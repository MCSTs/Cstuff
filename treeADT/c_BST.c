#include "tree.h"
#include "queue.h"
#include <unistd.h>


static Node *getTreeNode(int val)
{
    Node *node  = malloc(sizeof(Node));
    memset(node, 0, sizeof(Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


Node *insertTreeNode(Node *root, int val)
{
    if (root == NULL) {
        root = getTreeNode(val);
        root->height = 1;
        return root;
    }

    if (val < root->data)
    {
        root->left = insertTreeNode(root->left, val);
        root->height = getNodeHeight(root);
        if (abs(getNodeHeight(root->left)-getNodeHeight(root->right)) > 1) {
            if (val > root->left->data)
                return RLRotate(root);
            else if (val < root->left->data)
                return LLRotate(root);
        }
    }
    else if (val > root->data)
    {
        root->right = insertTreeNode(root->right, val);
        root->height = getNodeHeight(root);
        if (abs(getNodeHeight(root->left)-getNodeHeight(root->right)) > 1) {
            if (val > root->right->data)
                return RRRotate(root);
            else if (val < root->right->data)
                return LRRotate(root);
        }
    }
    return root;
}

Node *insert_Norec(Node *root, int val)
{
    if (root == NULL)
    {
        root = getTreeNode(val);
        return root;
    }

    Node *tmp = root;
    while (true)
    {
        if (val <= tmp->data)
        {
            if (tmp->left == NULL) {
                tmp->left = getTreeNode(val);
                break;
            }
            tmp = tmp->left;
        }
        else
        {
            if (tmp->right == NULL) {
                tmp->right = getTreeNode(val);
                break;
            }
            tmp = tmp->right;
        }
    }
    return root;
}

void free_BST(Node *root)
{
    if (root == NULL)
        return ;

    free_BST(root->left);
    free_BST(root->right);
    free(root);
}
