#include "queue.h"


Queue *init_queue(int maxl)
{
    Queue *queP = (Queue *)malloc(sizeof(Queue));
    queP->curLen = 0;
    queP->front = -1;
    queP->rear = -1;
    queP->maxl = maxl;
    queP->ar = (int *)malloc(maxl * sizeof(int));
    return queP;
}



void Dequeue(Queue *queP)
{
    if (queP->curLen == 0) {
        puts("Queue is empty");
        return;
    }

    queP->front = (queP->front + 1) % queP->maxl;
    queP->curLen--;
}

void Enqueue(Queue *queP, int num)
{
    if (queP->curLen == queP->maxl)
    {
        puts("Queue is flow");
        return;
    }
    
    if (queP->front == -1)
    {
        queP->front = 0;
        queP->rear = 0;
        queP->ar[0] = num;
    }
    else
    {
        queP->rear = (queP->rear + 1) % queP->maxl;
        (queP->ar)[queP->rear] = num;
    }

    (queP->curLen)++;

}


void clear_que(Queue *queP)
{
    queP->front = -1;
    queP->rear = -1;
    queP->maxl = 0;
    queP->curLen = 0;
}

void destroy_que(Queue *queP)
{
    free(queP->ar);
}


void print_que(Queue *queP)
{

    if (queP->curLen == 0)
        return;

    for (int i=queP->front, j=0; j<queP->curLen; j++, i=(i+1)%queP->maxl)
        printf("%d ", queP->ar[i]);
    putchar('\n');
}
