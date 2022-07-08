#ifndef __TOTAL_H__
#define __TOTAL_H__

#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	char sign;
	struct node* next;
};

extern struct node* head;

void push(int );
void pushchar(char );
int pop();
char popchar();
struct node* popnode();
int top();
void myprint(struct node* );

int SymbolMatch(char *);


#endif
