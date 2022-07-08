#include "total.h"


Node_t *reverse(Node_t *head)
{
    Node_t *cur = NULL;
    Node_t *pre = NULL;

    while (head != NULL)
    {
        cur = head;
        head = head->next;
        cur->next = pre;
        pre = cur;
    }

    return cur;
}
