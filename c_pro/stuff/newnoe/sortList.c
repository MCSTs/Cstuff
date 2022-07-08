#include "total.h"

Node_t *sortList(Node_t *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node_t *left = head;
    Node_t *mid = head->next;
    Node_t *right = head->next->next;

    while (right && right->next)
    {
        left = left->next;
        mid = mid->next;
        right = right->next->next;
    }
    left->next = NULL;

    head = merge_order(sortList(head), sortList(mid));

    return head;

}
