#include "tree.h"
#include "queue.h"


void levelOrder(Node *root, queHead_t *qHead)
{
    if (root == NULL)
        return;

    Enqueue(qHead, root);

    while (!isemptyQue(qHead))
    {
        Node *tmp = qHead->front;
        printf("%d ", tmp->data);
        if (tmp->left)
            Enqueue(qHead, tmp->left);
        if(tmp->right)
            Enqueue(qHead, tmp->right);
        Dequeue(qHead);
    }
    putchar('\n');
    return;
}


static void preOrder_in(Node *root)
{
    if (root == NULL)
        return ;

    printf("%d ", root->data);
    preOrder_in(root->left);
    preOrder_in(root->right);
}
void preOrder(Node *root)
{
    preOrder_in(root);
    putchar('\n');
}



static void InOrder_in(Node *root)
{
    if (root == NULL)
        return ;

    InOrder_in(root->left);
    printf("%d ", root->data);
    InOrder_in(root->right);
}
void InOrder(Node *root)
{
    InOrder_in(root);
    putchar('\n');
}


static void PostOrder_in(Node *root)
{
    if (root == NULL)
        return ;

    PostOrder_in(root->left);
    /*printf("%d ", root->data);*/
    PostOrder_in(root->right);
    printf("%d ", root->data);
}
void PostOrder(Node *root)
{
    PostOrder_in(root);
    putchar('\n');
}

