#include "total.h"

bool comment_node(Node_t *p1, Node_t *p2)
{
    if (p1==NULL || p2==NULL)
        return false;

    Node_t *ps1 = p1;
    Node_t *ps2 = p2;
    int len1 = 0, len2 = 0;
    int diff = 0;

    while (p1) {
        p1 = p1->next;
        len1++;
    }
    while (p2) {
        p2 = p2->next;
        len2++;
    }
    p1 = ps1;
    p2 = ps2;

    if (len1 > len2)
    {
        diff = len1-len2;
        while (diff--)
            p1 = p1->next;
    }
    else
    {
        diff = len2-len1;
        while (diff--)
            p2 = p2->next;
    }

    while (p1 && p2)
    {
        p1 = p1->next;
        p2 = p2->next;

        if (p1 == p2 && p1!=NULL)
            return true;
    }

    return false;
}


Node_t *comment_node_R(Node_t *p1, Node_t *p2)
{
    Node_t *tmp1 = p1;
    Node_t *tmp2 = p2;

    while (tmp1 != tmp2) {
        tmp1 = tmp1==NULL ? p2 : tmp1->next;
        tmp2 = tmp2==NULL ? p1 : tmp2->next;
    }

    return tmp1;
  
}



void p2Linktop1node(Node_t *p1, Node_t *p2, int index)
{
    if (p1 == NULL || p2 == NULL)
        return;

    while (--index)
    {
        if (p1 == NULL)
            return;
        p1 = p1->next;
    }

    while (p2->next)
        p2 = p2->next;
    p2->next = p1;
}

