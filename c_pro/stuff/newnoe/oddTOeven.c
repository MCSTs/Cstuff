#include "total.h"

Node_t *odd_to_even(Node_t *head)
{
    if (head==NULL || head->next==NULL)
        return head;

    Node_t *odd = head;
    Node_t *even = head->next;
    Node_t *headeven = even;

    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = headeven;


    return head;
}

