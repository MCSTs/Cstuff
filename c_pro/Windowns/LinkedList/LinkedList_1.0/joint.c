#include "total.h"
#include <stdio.h>
#include <stdlib.h>

struct node* joint_2(struct node* p1, struct node* p2) 
{
	struct node *res = (struct node *)malloc(sizeof(struct node));
	struct node *cur = res;
	while( p1 && p2 )
	{
		if( p1->value < p2->value )
		{
			cur->next = p1;
			cur = cur->next;
			p1 = p1->next;
		}
		else
		{
			cur->next = p2;
			cur = cur->next;
			p2 = p2->next;
		}
	}
	cur->next = p1==NULL?p2:p1;
	return res->next;
}

struct node* joint_new(struct node* p1, struct node* p2)
{
	struct node* res = (struct node*)malloc(sizeof(struct node));
	struct node* cur = res;
	while( p1 && p2 )
	{
		struct node* pnew = (struct node*)malloc(sizeof(struct node));
		if( p2->value < p1->value )
		{
			pnew->value = p2->value;
			p2 = p2->next;
		}
		else
		{
			pnew->value = p1->value;
			p1 = p1->next;
		}
		cur->next = pnew;
		cur = cur->next;
	}
	cur->next = p1 == NULL?p2:p1;
	return res->next;
}

struct node* merge_rec(struct node* p1, struct node* p2)
{
	if(p1==NULL)	
		return p2;
	if(p2==NULL)	
		return p1;

	if(p1->value <= p2->value)
	{
		p1->next = merge_rec(p1->next, p2);
		return p1;
	}
	else
	{
		p2->next = merge_rec(p1, p2->next);
		return p2;
	}
}

struct node* merge2(struct node* p1, struct node* p2)
{
	if(p1==NULL)
		return p2;
	if(p2==NULL)
		return p1;
	struct node* res = (struct node*)malloc(sizeof(struct node));
	res->next = p1->value <= p2->value ? p1: p2;
	struct node* cur = res;
	
	while( p1 && p2 )
	{
		if(p1->value <= p2->value)
		{
			cur->next = p1;
			p1 = p1->next;
		}
		else
		{
			cur->next = p2;
			p2 = p2->next;
		}
		cur = cur->next;
	}

	cur->next = p1==NULL ? p2: p1;

	return res->next;
}


