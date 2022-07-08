#include "total.h"


Node_t *back_n(Node_t *head, int n)
{
    Node_t *fast = head;
    Node_t *cur = head;

    for (int i=0; i<n; i++) {
        if (fast == NULL)
            return NULL;
        fast = fast->next;
    }

    while (fast != NULL)
    {
        fast = fast->next;
        cur = cur->next;
    }

    return cur;
}


Node_t *delete_back_n(Node_t *head, int n)
{
    Node_t *fast = head;
    Node_t *cur  = head;
    Node_t *src = malloc(sizeof(Node_t));
    src->next = head;
    Node_t *pre = src;
    
    for (int i=0; i<n; i++)
    {
        if (fast == NULL)
            return NULL;
        fast = fast->next;
    }

    while (fast)
    {
        fast = fast->next;
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
    cur->next = NULL;
    head = src->next;
    free(cur);
    free(src);

    return head;
}


Node_t *del_order_otherRep(Node_t *head)
{
    if (!head)
        return NULL;

    Node_t *cur = head;
    while (cur && cur->next)
    {
        if (cur->data == cur->next->data)
            cur->next = cur->next->next;
        else
            cur = cur->next;
    }
    return head;

}


Node_t *del_order_allRep(Node_t *head)
{
    if (head == NULL)
        return NULL;

    Node_t *rsc = malloc(sizeof(Node_t));
    rsc->next = head;
    Node_t *cur = rsc;

    while (cur->next && cur->next->next)
    {
        if (cur->next->data == cur->next->next->data) 
        {
            int tmp = cur->next->data;
        while (cur->next && cur->next->data == tmp)
            cur->next = cur->next->next;
        }
        else
            cur = cur->next;
        
    }
    head = rsc->next;
    free(rsc);
    return head;
}
