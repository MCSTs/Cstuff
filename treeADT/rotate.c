#include "tree.h"

Node *RRRotate(Node *node)
{
    Node * root = node->right;
    node->right = root->left;
    root->left  = node;
    node->height = getNodeHeight(node);
    root->height = getNodeHeight(root);
    return root;
}


Node *LLRotate(Node *node)
{
    Node *root  = node->left;
    node->left  = root->right;
    root->right = node;
    node->height = getNodeHeight(node);
    root->height = getNodeHeight(root);
    return root;
}


Node *LRRotate(Node *node)
{
    node->right = LLRotate(node->right);
    node = RRRotate(node);
    return node;
}


Node *RLRotate(Node *node)
{
    node->left = RRRotate(node->left);
    node = LLRotate(node);
    return node;
}
