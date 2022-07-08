#ifndef __TOTAL_H__
#define __TOTAL_H__

struct postfix{
	char sign;
	int val;
	struct postfix* next;
};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *InfixToPostfix(char *);
int compare(char , char );
char pop(struct postfix**);
void push(struct postfix** , char, int);


#endif
