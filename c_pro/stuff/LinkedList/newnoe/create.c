#include "total.h"

void print_ll(Node_t *head)
{
    if (head == NULL) {
        puts("NULL");
        return ;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    putchar('\n');
}

void myfree(Node_t *start, Node_t *end)
{
    Node_t *tmp = NULL;
    while (start != NULL && start != end) {
        tmp = start->next;
        free(start);
        start = tmp; 
    }
}

Node_t *create()
{
    
    int num;
    Node_t *new = NULL;
    Node_t *head = NULL;
    Node_t *tail = NULL;

    puts("enter a linklist(end of any char): ");

    while (scanf("%d", &num) != 0) {
        new = (Node_t *)malloc(sizeof(Node_t));
        new->data = num;
        new->next = NULL;

        if (head == NULL) {
            head = new;
            tail = new;
        }
        else {
            tail->next = new;
            tail = new;
        }
    }
    scanf("%*s");

    return head;
}


