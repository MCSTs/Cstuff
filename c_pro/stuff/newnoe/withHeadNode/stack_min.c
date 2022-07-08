#include "total.h"

 
Node_t *push(headN_t *headNode ,int data)
{
    Node_t *new = malloc(sizeof(Node_t));
    new->val = data;

    new->next = headNode->stack_top;
    headNode->stack_top = new;
    return new;
}

Node_t *poll(headN_t *headNode)
{
    Node_t *tmp = headNode->stack_top;
    headNode->stack_top = headNode->stack_top->next;
    return tmp;
}
