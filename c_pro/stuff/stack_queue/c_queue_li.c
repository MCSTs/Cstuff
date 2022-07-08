#include "queue.h"
#include "stack.h"


Queue_li *init_queue_li()
{
    Queue_li *queP_li = (Queue_li *)malloc(sizeof(Queue_li));
    queP_li->cur_len = 0;
    queP_li->front = NULL;
    queP_li->rear = NULL;
    return queP_li;
}


bool isempty_que_li(Queue_li *queP_li)
{
    if (!queP_li->front)
        return true;
    return false;
}


node_t *Dequeue_li(Queue_li *queP_li)
{
    if (queP_li->cur_len == 0)
    {
        fprintf(stderr, "The queue is empty\n");
        return NULL;
    }

    node_t *tmp = queP_li->front;
    queP_li->front = queP_li->front->next;
    queP_li->cur_len--;
    return tmp;
}

static node_t *getnode(int val)
{
    node_t *p = malloc(sizeof(node_t));
    p->data = val;
    p->next = NULL;
    p->pre = NULL;
    return p;
}

void Enqueue_li(Queue_li *queP_li, int val)
{
    if (queP_li->front == NULL)
    {
        queP_li->front = getnode(val);
        queP_li->rear = queP_li->front;
    }
    node_t *tmp =  getnode(val);
    queP_li->rear->next = tmp;
    queP_li->rear = tmp;
    queP_li->cur_len++;
}


void print_que_li(Queue_li *queP_li)
{
    if (queP_li->cur_len == 0)
        printf("It's empty\n");

    node_t *p = queP_li->front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}

