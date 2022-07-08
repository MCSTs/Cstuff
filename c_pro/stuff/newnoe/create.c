#include "total.h"

void print_ll(Node_t *head)
{
    if (head == NULL)
        printf("NULL\n");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    putchar('\n');
}

Node_t *create_ll()
{

    int num;
    Node_t *new  = NULL;
    Node_t *head = NULL;
    Node_t *tail = NULL;

    puts("enter the linklist(end of any char):");

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
            tail= new;
        }
    }
    while (getchar()!='\n');

    return head;
}

Node_t *Head_insert()
{

    int num;
    Node_t *head = NULL;
    Node_t *tail = NULL;

    while (scanf("%d", &num)) {
        head = malloc(sizeof(Node_t));
        head->data = num;
        head->next = NULL;
        if (tail == NULL)
            tail = head;
        else
        {
            head->next = tail;
            tail = head;
        }
    }
    return head;

}


void free_ll(Node_t *start, Node_t *end)
{
    Node_t *tmp = start;
    while (start != NULL && start != end) {
        tmp = start->next;
        free(start);
        start = tmp;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



