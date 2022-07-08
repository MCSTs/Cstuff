#include "total.h"

void delete_n(headN_t *headNode, int num)
{
    if (headNode->start == NULL)
        return ;

    Node_t *p = headNode->start;
    Node_t *pre = NULL;
    while (p)
    {
        if (p->val == num)
            break;
        pre = p;
        p = p->next;
    }
    if (p == NULL) {
        puts("Not find the node");
        return;
    }

    if (p->next == NULL)
    {
        if (p == headNode->start)
        {
            free(p);
            headNode->start = NULL;
            headNode->end = NULL;
            headNode->len = 0;
            return;
        }
        free(p);
        pre->next = NULL;
        headNode->end = pre;
        headNode->len--;
    }
    else if(p == headNode->start)
    {
        headNode->start = p->next;
        headNode->len--;
    }
    else
    {
        pre->next = p->next;
        p->next = NULL;
        headNode->len--;
        free(p);
    }
}


void del_Min(headN_t *headNode)
{
    if (headNode->start == NULL)
        return;

    int min = headNode->start->val;
    Node_t *p = headNode->start;
    Node_t *tmp = p;
    Node_t *pre = malloc(sizeof(Node_t));
    Node_t *tmp_pre = malloc(sizeof(Node_t));
    pre->next = p;
    tmp_pre->next = p;

    while (p)
    {
        if (p->val < min)
        {
            min = p->val;
            tmp_pre = pre;
            tmp = p;
        }
        pre = p;
        p = p->next;
    }

    if (tmp == headNode->start)
    {
        headNode->start = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }
    else if(tmp->next == NULL)
    {
        headNode->end = tmp_pre;
        tmp_pre->next = NULL;
    }
    else
    {
        tmp_pre->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }

    headNode->len--;
}



void delN_inBothlist(headN_t *bothhead, int num)
{
    if (bothhead->start == NULL)
        return ;

    Node_t *tmp = NULL;
    Node_t *p = bothhead->start;
    while (p)
    {
        if (p->val == num)
            break;
        p = p->next;
    }
    if (p == NULL)
        return;
    else if(p == bothhead->end)
    {
        tmp = p->pre;
        tmp->next = NULL;
        bothhead->end = tmp;
        free(p);
    }
    else if (p == bothhead->start)
    {
        tmp = p->next;
        tmp->pre = NULL;
        bothhead->start = tmp;
        free(p);
    }
    else
    {
        tmp = p->pre;
        tmp->next = p->next;
        p->next->pre = tmp;
        free(p);
    }
    bothhead->len--;
}




void del_in_Minstack(headN_t *headNode)
{
    if (headNode->start == NULL)
        return;

    int min = headNode->start->val;
    Node_t *p = headNode->start;
    headNode->stack_top = malloc(sizeof(Node_t));
    headNode->stack_top->val = p->val;
    headNode->stack_top->next = NULL;

    while (p)
    {
        if (min > p->val)
        {
            min = p->val;
            push(headNode, p->val);
        }
        else
            push(headNode, headNode->stack_top->val);
        p = p->next;
    }
}


void generate_MinStack(headN_t *bothhead)
{
    if (bothhead->start == NULL)
        return ;

    Node_t *p = bothhead->start;
    int min = bothhead->start->val;
    bothhead->stack_top = malloc(sizeof(Node_t));
    bothhead->stack_top->val = min;
    bothhead->stack_top->next = NULL;
    
    while (p)
    {
        if (p->val < min)
        {
            min = p->val;
            push(bothhead, p->val);
        }
        else
            push(bothhead, bothhead->stack_top->val);
        p = p->next;
    }
}
