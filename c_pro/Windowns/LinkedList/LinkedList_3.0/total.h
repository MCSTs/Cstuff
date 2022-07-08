#ifndef __TOTAL_H__
#define __TOTAL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct node{
	int val;
	struct node *next;
}ListNode;


void print_LL(ListNode *head, const char *ms);
ListNode *create_LL(void);
ListNode *free_LL(ListNode *start, ListNode *end);


ListNode *flip_Whole(ListNode *head);
ListNode *flip_recurse(ListNode *head);
ListNode *flip_between_nm(ListNode *head, int n, int m);
ListNode *flip_perNgrop(ListNode *head, int n);
ListNode *flip_perNgrop_recurse(ListNode *head, int n);

ListNode *fineLoopnode(ListNode *head);
ListNode *insert_loopNode(ListNode *head, int num);
int isloop(ListNode *head);

ListNode *joint_LinkedList(ListNode *p1, ListNode *p2);
ListNode *joint_LinkedList_recurse(ListNode *p1, ListNode *p2);

ListNode *mergeKLists(ListNode **lists, int listslen);
ListNode *mergeKLists_LR(ListNode **lists, int left, int right);

ListNode *delete_CoundDownK(ListNode *head, int k);
ListNode *coundDown_K(ListNode *head, int k);

void joint_commondNode(ListNode *p1, ListNode *p2, int p1_nu, int p2_nu);
int has_commondNode(ListNode *p1, ListNode *p2);
int has_commondNode_v2(ListNode *p1, ListNode *p2);

#endif 
