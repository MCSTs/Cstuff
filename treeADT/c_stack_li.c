#include "stack.h"
#include "tree.h"


HeadNode *init_stack()
{
    HeadNode *headNode = malloc(sizeof(HeadNode));
    headNode->stacklen = 0;
    headNode->top = NULL;
    return headNode;
}

void push(HeadNode *headNode, Node *p)
{
    
    Node *new = malloc(sizeof(Node));
    *new = *p; 

    new->next = headNode->top;
    headNode->top = new;
    headNode->stacklen++;
}


void poll(HeadNode *headNode)
{
    if (headNode->top == NULL)
        return ;
    Node *tmp = headNode->top;
    headNode->stacklen--;
    headNode->top = tmp->next;
    free(tmp);
}

bool isempty_stack(HeadNode *headNode)
{
    if (!(headNode->top))
        return true;
    return false;
}


void print_stack(HeadNode *headNode)
{
    if (isempty_stack(headNode))
        puts("the stack is empty");
    printf("The stack have %d element\n", headNode->stacklen);
    Node *p = headNode->top;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}
