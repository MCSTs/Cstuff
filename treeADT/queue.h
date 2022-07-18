#pragma once

#include "tree.h"



queHead_t *initQueue();
bool isemptyQue(queHead_t *qHead);
void Enqueue(queHead_t *qHead, Node *p);
void Dequeue(queHead_t *qHead);
void print_que(queHead_t *qHead);

