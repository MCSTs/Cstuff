#pragma once


typedef struct node{
    int val;
    struct node *next; 
    struct node *pre;
}Node_t;



typedef struct hn{
    Node_t *start;
    Node_t *end;
    Node_t *stack_top;
    Node_t *stack_min;
    int len;
}headN_t;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>


headN_t *create();
headN_t *create_incream();
void print_tt(headN_t *headNode);


void delete_n(headN_t *headNode, int num);
void del_Min(headN_t *headNode);
Node_t *push(headN_t *headNode ,int data);
Node_t *poll(headN_t *headNode);
void del_in_Minstack(headN_t *headNode);


headN_t *create_bothwayList();
void print_back(headN_t *bothhead);
void delN_inBothlist(headN_t *bothhead, int num);

// print
void print_minstack(headN_t *headNode);
