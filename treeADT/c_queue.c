#include "queue.h"


queHead_t *initQueue()
{
    queHead_t *qHead = malloc(sizeof(queHead_t));
    qHead->front = qHead->rear = NULL;
    qHead->queLen = 0;
    return qHead;
}


bool isemptyQue(queHead_t *qHead)
{
    if (qHead->queLen == 0)
        return true;
    return false;
}


void Enqueue(queHead_t *qHead, Node *p)
{
    Node *new = malloc(sizeof(Node));
    *new = *p;
    
    if (qHead->queLen == 0) {
        qHead->front = qHead->rear = new;
    }
    else
    {
        qHead->rear->next = new;
        qHead->rear = new;
    }
    qHead->queLen++;
}


void Dequeue(queHead_t *qHead)
{
    if (isemptyQue(qHead))
        return ;
    Node *tmp = qHead->front;
    qHead->front = qHead->front->next;
    qHead->queLen--;
    free(tmp);
    return ;
}


void print_que(queHead_t *qHead)
{
    if (qHead->queLen== 0)
        printf("It's empty\n");

    Node *p = qHead->front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}
