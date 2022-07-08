# pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

typedef struct node{
	int val;
	struct node *next;
}ListNode;

typedef enum{FALSE, TRUE} Boolean;


ListNode *create_LL(void);
ListNode *free_LL(ListNode *start, ListNode *end);
void print_LL(ListNode *head, const char *ms);

/* Flip Linked List */
ListNode *flip_Whole(ListNode *head);
ListNode *flip_recurse(ListNode *head);
ListNode *flip_between_nm(ListNode *head, int n, int m);
ListNode *flip_perNgrop(ListNode *head, int n);
ListNode *flip_perNgrop_recurse(ListNode *head, int n);

/* loop Linked List */
Boolean isloop(ListNode *head);
ListNode *insert_loopNode(ListNode *head, int num);
ListNode *fineLoopnode(ListNode *head);

/* merge Linked List */
ListNode *joint_LinkedList(ListNode *p1, ListNode *p2);
ListNode *joint_LinkedList_recurse(ListNode *p1, ListNode *p2);
ListNode *mergeKLists(ListNode **lists, int listslen);

/* CoundDown node */
ListNode *delete_CoundDownK(ListNode *head, int k);
ListNode *coundDown_K(ListNode *head, int k);

/* Commond Node */
void joint_commondNode(ListNode *p1, ListNode *p2, int p1_nu, int p2_nu);
int has_commondNode(ListNode *p1, ListNode *p2);
int has_commondNode_v2(ListNode *p1, ListNode *p2);


