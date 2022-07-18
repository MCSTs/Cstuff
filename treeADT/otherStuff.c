#include "tree.h"
#include "stack.h"

int countDegreeOfOne(Node *root)
{
    static int sum = 0;
    if (root == NULL)
        return sum;
    if ((root->right || root->left) && (root->left == NULL || root->right == NULL))
        sum++;
    countDegreeOfOne(root->left);
    countDegreeOfOne(root->right);
    return sum;
}



int countMaxWidth(Node *root)
{
    if (root == NULL)
        return 0;
    if (!root->left && !root->right)
        return 1;
    HeadNode *levelStack = init_stack();
    HeadNode *nodeStack  = init_stack();
    push(levelStack, root);
    /*push(nodeStack, root);*/
    int Maxwidth = 0;
    while (levelStack->top || nodeStack->top)
    {
        if (Maxwidth < levelStack->stacklen)
            Maxwidth = levelStack->stacklen;
        while (levelStack->top)
        {
            push(nodeStack, levelStack->top);
            poll(levelStack);
        }
        while (nodeStack->top)
        {
            if (nodeStack->top->left)
                push(levelStack, nodeStack->top->left);
            if (nodeStack->top->right)
                push(levelStack, nodeStack->top->right);
            poll(nodeStack);
        }
    }
    free(levelStack);
    free(nodeStack);
    return Maxwidth;

}
