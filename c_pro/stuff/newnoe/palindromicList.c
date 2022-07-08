#include "total.h"


bool isPalindromic_list(Node_t *head)
{
    if (head == NULL)
        return false;
    if (head->next == NULL)
        return true;
    
    Node_t *fast = head;
    Node_t *mid = head;
    while (fast && fast->next && fast->next->next)
    {
        fast = fast->next->next;
        mid = mid->next;
    }
    mid->next = flip_whole(mid->next);

    Node_t *p1 = head;
    Node_t *p2 = mid->next;
    while (p2)
    {
        if (p1->data != p2->data)
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}


