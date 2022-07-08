#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

typedef struct que{
    int maxl; 
    int rear;
    int front;
    int curLen;
    int *ar;
}Queue;


typedef struct que_li{
    node_t *front;
    node_t *rear;
    int cur_len;

}Queue_li;


// queue with array
Queue *init_queue(int maxl);
void Dequeue(Queue *queP);
void Enqueue(Queue *queP, int num);

void clear_que(Queue *queP);
void destroy_que(Queue *queP);
void print_que(Queue *queP);


// queue with linkedlist
Queue_li *init_queue_li();
bool isempty_que_li(Queue_li *queP_li);
node_t *Dequeue_li(Queue_li *queP_li);
void Enqueue_li(Queue_li *queP_li, int val);
void print_que_li(Queue_li *queP_li);
