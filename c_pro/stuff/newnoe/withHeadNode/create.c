#include "total.h"

headN_t *create()
{
    printf("enter a list: ");
    headN_t *headNode = malloc(sizeof(headN_t));
    
    memset(headNode, 0, sizeof(headN_t));
   
    Node_t *head = NULL;
    Node_t *tail = NULL;
    Node_t *new = NULL;

    int num;
    while (scanf("%d", &num) != 0)
    {
        new = malloc(sizeof(Node_t));
        new->val = num;
        new->next = NULL;

        if (headNode->start == NULL) {
            headNode->start = new; 
        }
        if (head == NULL)
        {
            head = new;
            tail = new;
        }
        else
        {
            tail->next = new;
            tail = new;
        }
        headNode->end = new;
        (headNode->len)++;
    }

    while (getchar() != '\n');
    return headNode;

}



static headN_t 
*insertNode(headN_t *headNode, Node_t *node)
{
    if (headNode->start == NULL) {
        headNode->start = node;
        headNode->end = node;
        headNode->len++;
    }

    else {
        Node_t *p = headNode->start;
        Node_t *pre = NULL;
        while (p) {
            if (p->val > node->val)
                break;
            pre = p;
            p = p->next;
        }

        if (p == NULL)
        {
            pre->next = node;
            headNode->end = node;
            node->next = NULL;
        }
        else if (p == headNode->start)
        {
            node->next = p;
            headNode->start = node;
        }
        else
        {
            pre->next = node;
            node->next = p;
        }
        headNode->len++;
    }

    return headNode;
}


headN_t *create_incream()
{
    printf("enter a list: ");
    headN_t *headNode = malloc(sizeof(headN_t));
    memset(headNode, 0, sizeof(headN_t));
     
    Node_t *new = NULL;

    int num;
    while (scanf("%d", &num) != 0)
    {
        new = malloc(sizeof(Node_t));
        new->val = num;
        new->next = NULL;
        headNode = insertNode(headNode, new);
    }

    while (getchar() != '\n');
    return headNode;
}


static void insert_bothway(headN_t *bothhead, int data)
{
    Node_t *new = malloc(sizeof(Node_t));
    new->val = data;
    new->next = NULL;
    new->pre = NULL;
    if (bothhead->start == NULL)
    {
        bothhead->start = new;
        bothhead->end = new;
    }
    else
    {
        bothhead->end->next = new;
        new->pre = bothhead->end;
        bothhead->end = new;
    }
    bothhead->len++;
}

headN_t *create_bothwayList()
{
    headN_t *bothhead = malloc(sizeof(headN_t));
    memset(bothhead, 0, sizeof(*bothhead));

    puts("enter the bothway list: ");
    int data;
    while (scanf("%d", &data))
        insert_bothway(bothhead, data);
    while (getchar()!='\n');
    return bothhead;
}

