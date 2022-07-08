#include "total.h"

Node_t *merge_order_R(Node_t *p1, Node_t *p2)
{
    if (p1 == NULL)
        return p2;
    if (p2 == NULL)
        return p1;

    if (p1->data < p2->data) {
        p1->next = merge_order_R(p1->next, p2);
        return p1;
    }
    else {
        p2->next = merge_order_R(p1, p2->next);
        return p2;
    }
}


Node_t *merge_order(Node_t *p1, Node_t *p2)
{
    if (p1 == NULL)
        return p1;
    if (p2 == NULL)
        return p2;
    Node_t *src = malloc(sizeof(Node_t)); 
    src->next = p1->data < p2->data ? p1 : p2;
    Node_t *cur = src;

    while (p1 && p2) {
        if (p1->data < p2->data)
        {
            cur->next = p1;
            p1 = p1->next;
        }
        else
        {
            cur->next = p2;
            p2 = p2->next;
        }
        cur = cur->next;
    }
    cur->next = p1==NULL ? p2 : p1;
    cur = src->next;
    free(src);

    return cur;
}


Node_t *mer_k(Node_t **list, int left, int right)
{
    if (left > right)
        return NULL;
    
    if (left == right)
        return list[left];

    int mid = (left + right) / 2;
    return merge_order(mer_k(list, left, mid), mer_k(list, mid+1, right));

}
