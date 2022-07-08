#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct list{
    int data;
    struct list *next;
}Node_t;


Node_t *create();
void print_ll(Node_t *head);
void myfree(Node_t *, Node_t *);

Node_t *reverse(Node_t *head);
