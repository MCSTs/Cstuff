#include <stdio.h>
#include <stdlib.h>
#include "total.h"

struct node* rev(struct node* p)
{
	if(p==NULL || p->next==NULL)
		return p;
	struct node* pre = NULL;
	while(p)
	{
		struct node* tmp = p->next;
		p->next = pre;
		pre = p;
		p = tmp;
	}
	return pre;
}

struct node* addInList(struct node* head1, struct node* head2) 
{
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;

	head1 = rev(head1);
	head2 = rev(head2);

	struct node* new = (struct node*)malloc(sizeof(struct node));
	struct node* pnew = new;
	struct node* pre = NULL;

	int carry = 0;
	while(head1!=NULL && head2!=NULL)
	{
		int mid = head1->value + head2->value + carry;
		if(mid >= 10)
		{
			new->value = mid - 10;
			carry = 1;
		}
		else
		{
			new->value = mid;
			carry = 0;
		}
		if(pre==NULL)
			pre = new;
		else
		{
			pre->next = new;
			pre = new;
		}
		new = (struct node*)malloc(sizeof(struct node));
		head1 = head1->next;
		head2 = head2->next;
	}
	pre->next = head1==NULL? head2 : head1;
	struct node* pp = pre;
	pre = pre->next;

	if( carry==1 )
	{
		while(pre)
		{
			int re = pre->value + 1;
			if(re >= 10)
				pre->value = 0;
			else
			{
				pre->value = re;
				pnew = rev(pnew);
				return pnew;
			}
			pre = pre->next;
		}
		if(pre)
		{
			pre->next = new;
			new->value = 1;
			new->next = NULL;
		}
		else
		{
			pp->next = new;
			new->value = 1;
			new->next = NULL;
		}
	}
	pnew = rev(pnew);
	return pnew;
}
