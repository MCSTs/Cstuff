#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node_t;


// create
void free_ll(Node_t *start, Node_t *end);
Node_t *create_ll();
Node_t *Head_insert();
void print_ll(Node_t *head);

// flip
Node_t *flip_whole(Node_t *head);
Node_t *flip_n2m(Node_t *head, int n, int m);
Node_t *flip_group_n(Node_t *head, int n);
Node_t *add_TwoList(Node_t *p1, Node_t *p2);



// loop 
bool isloop(Node_t *head, bool do_print);
void linkLoop(Node_t *head, int num);
Node_t *findNode_loop(Node_t *head);


// merge
Node_t *merge_order_R(Node_t *p1, Node_t *p2);
Node_t *merge_order(Node_t *p1, Node_t *p2);
Node_t *mer_k(Node_t **list, int left, int right);

// delete
Node_t *back_n(Node_t *head, int n);
Node_t *delete_back_n(Node_t *head, int n);
Node_t *del_order_otherRep(Node_t *head);
Node_t *del_order_otherRep(Node_t *head);
Node_t *del_order_allRep(Node_t *head);

// comment 
bool comment_node(Node_t *p1, Node_t *p2);
void p2Linktop1node(Node_t *p1, Node_t *p2, int index);
Node_t *comment_node_R(Node_t *p1, Node_t *p2);


// sortList
Node_t *sortList(Node_t *head);

// palindromic
bool isPalindromic_list(Node_t *head);


Node_t *odd_to_even(Node_t *head);
