#include "total.h"

Node_t *flip_whole(Node_t *head)
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



Node_t *flip_n2m(Node_t *head, int n, int m)
{
    if (head == NULL || n>=m)
        return NULL;

    int i;
    Node_t *cur = head;
    Node_t *src = malloc(sizeof(Node_t));
    src->next = head;
    Node_t *pre = src;
    Node_t *tmp = NULL;

    for (i=1; i<n && cur!=NULL; i++) 
    {
        pre = cur;
        cur = cur->next;
    }

    for (i=n; i<m && cur!=NULL && cur->next!=NULL; i++) 
    {
        tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = pre->next;
        pre->next = tmp;
    }

    head = src->next;
    free(src);

    return head;
}

Node_t *flip_group_n(Node_t *head, int n)
{
    Node_t *tail = head;

    for (int i=0; i<n; i++) {
        if (tail == NULL)
            return head;
        tail = tail->next;
    }

    Node_t *pre = NULL;
    Node_t *cur = head;
    while (cur != tail) {
        Node_t *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }

    head->next =  flip_group_n(tail, n);

    return pre;
}


Node_t *add_TwoList(Node_t *p1, Node_t *p2)
{
    if (p1 == NULL)
        return p2;
    if (p2 == NULL)
        return p1;

    Node_t *src = malloc(sizeof(Node_t));
    Node_t *head = src;
    p1 = flip_whole(p1);
    p2 = flip_whole(p2);

    int carray = 0;
    int tmp = 0;
    int val1 = 0;
    int val2 = 0;
    while (p1 || p2 || carray!=0)
    {
        val1 = p1==NULL ? 0 : p1->data;
        val2 = p2==NULL ? 0 : p2->data;

        tmp    = val1 + val2 + carray;
        carray = tmp / 10;
        tmp %= 10;

        head->next = malloc(sizeof(Node_t));
        head = head->next;
        head->data = tmp;

        if (p1)
            p1 = p1->next;
        if (p2)
            p2 = p2->next;
    }

    head = src->next;
    free(src);
    return flip_whole(head);
}

