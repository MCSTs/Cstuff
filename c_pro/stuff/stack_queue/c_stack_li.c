#include "stack.h"


HeadNode *init_stack()
{
    HeadNode *headNode = malloc(sizeof(HeadNode));
    headNode->stacklen = 0;
    headNode->top = NULL;
    return headNode;
}

void push(HeadNode *headNode, int val)
{
    
    node_t *new = malloc(sizeof(node_t));
    new->data = val;
    new->pre = NULL;

    new->next = headNode->top;
    if (headNode->top)
        headNode->top->pre = new;
    headNode->top = new;
    headNode->stacklen++;
}

void push_ch(HeadNode *headNode, char ch)
{
    
    node_t *new = malloc(sizeof(node_t));
    new->ch = ch;
    new->pre = NULL;

    new->next = headNode->top;
    if (headNode->top)
        headNode->top->pre = new;
    headNode->top = new;
    headNode->stacklen++;
}

node_t *poll(HeadNode *headNode)
{
    if (!headNode->top)
        return NULL;

    node_t *tmp = headNode->top;
    headNode->stacklen--;
    headNode->top = tmp->next;
    /*headNode->top->pre = NULL;*/
    return tmp;
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
    node_t *p = headNode->top;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}
