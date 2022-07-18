#ifndef STACK_H__H
#define STACK_H__H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "tree.h"

//typedef struct sst{
    //int data;
    //char ch;
    //struct sst *next;
    //struct sst *pre;
//}node_t;

typedef struct Hnoed{
    int stacklen;
    Node *top;
}HeadNode;


bool isempty_stack(HeadNode *headNode);
void poll(HeadNode *headNode);
void push(HeadNode *headNode, Node *p);
HeadNode *init_stack();
void print_stack(HeadNode *headNode);


#endif

