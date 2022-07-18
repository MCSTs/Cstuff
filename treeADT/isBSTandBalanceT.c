#include "tree.h"
#include <limits.h>

/*--isBST--*/
static bool
isBST_in(Node *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;
    if (root->data <= maxValue 
        && root->data > minValue
        && isBST_in(root->left, minValue, root->data)
        && isBST_in(root->right, root->data, maxValue))
        return true;
    else
        return false;
}
bool 
isBST(Node *root)
{
    return isBST_in(root, INT_MIN, INT_MAX);
}
/*----*/


/*--findHeight--*/
static int
max(int a, int b)
{
    return a >= b ? a : b;
}
int getNodeHeight(Node *root)
{
    if (root == NULL)
        return 0;
    return max( getNodeHeight(root->left), getNodeHeight(root->right) ) + 1;
}
/*---*/


bool isBalenceBT(Node *root)
{
    if (root == NULL)
        return true;
    int leftLen = getNodeHeight(root->left);
    int rightLen = getNodeHeight(root->right);
    int diffLen = abs(leftLen - rightLen);
    if ((diffLen<= 1) 
            && isBalenceBT(root->left) 
            && isBalenceBT(root->right)) 
        return true;
    return false;
}


Node *findNotBalanceNode(Node *root, Node **re)
{
    if (root == NULL)
        return *re;
    if (abs(getNodeHeight(root->left) - getNodeHeight(root->right)) > 1)
        return *re = root;
    findNotBalanceNode(root->left, re);
    findNotBalanceNode(root->left, re);
    return *re;
}
