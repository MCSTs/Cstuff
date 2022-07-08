#ifndef __TOTAL_H__
#define __TOTAL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct node{
	int val;
	struct node *next;
};

struct node *create_LL(int );
struct node *free_LL(struct node *head, struct node *tail);

struct node *flip_LL(struct node *p);
struct node *flip_recurse(struct node *head);

struct node *flip_between_nm(struct node *head, int n, int m);
struct node *flip_perKground(struct node *head, int k);
struct node *flip_perK(struct node *head, int k);

struct node *joint2_Orderd(struct node *p1, struct node *p2);
struct node *joint2_Orderd_recurse(struct node *p1, struct node *p2);
struct node *jointK_Orderd(struct node **lists, int listLen);

struct node *insert_loopNode(struct node *head, int num);
int isloop(struct node *head);
struct node *find_loopNode(struct node *head);

#endif 
