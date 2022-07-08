#include "total.h"

void print_tt(headN_t *headNode)
{
    if (headNode->start == NULL)
    {
        printf("LinkList is NULL\n");
        return;
    }

    printf("list message:\n");
    printf("headNode: %d (%p)\n", headNode->start->val, &headNode->start);
    printf("tailNode: %d (%p)\n", headNode->end->val, &headNode->end);
    printf("Nodesum : %d\n", headNode->len);

    printf("source list is:\n");
    Node_t *p = headNode->start;
    while (p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    putchar('\n');
}


void print_back(headN_t *bothhead)
{
    if (bothhead->end==NULL)
        return;
    Node_t *p = bothhead->end;
    while (p)
    {
        printf("%d ", p->val);
        p = p->pre;
    }
    putchar('\n');
}


void print_minstack(headN_t *headNode)
{
    Node_t *p = headNode->stack_top;
    while (p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    putchar('\n');
}
