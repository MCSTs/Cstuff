#include <stdlib.h>
#include "total.h"


int isloop(struct node* head)
{
	if(head==NULL || head->next==NULL)
		return 1;

	struct node* fast = head;
	struct node* slow = head;
	
	while(fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(fast==slow)
			return 1;
	}
	return 0;
}

struct node* loop_node(struct node* head)
{
	if(head==NULL || head->next==NULL)
		return NULL;

	struct node* fast = head;
	struct node* slow = head;
	struct node* point = NULL;
	
	while(fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(fast==slow)
		{
			point = slow;
			break;
		}
	}
	if(point==NULL)
		return NULL;
	else
	{
		fast = head;
		while(fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}
	return NULL;
}


struct node* common_node(struct node* p1, struct node* p2)
{
	if(p1==NULL || p2==NULL)
		return NULL;
	if(p1==p2)
		return p1;

	struct node* head1 = p1;
	struct node* head2 = p2;
	int p1_len = 0, p2_len = 0;
	while(p1)
	{
		p1 = p1->next;
		p1_len++;
	}
	p1 = head1;

	while(p2)
	{
		p2 = p2->next;
		p2_len++;
	}
	p2 = head2;

	if(p1_len == p2_len)
	{
		while(p1)
		{
			if(p1==p2)
				return p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		return NULL;
	}
	else if(p1_len < p2_len)
	{
		int diff_len = p2_len - p1_len;
		for(int i=0; i<diff_len; i++)
			p2 = p2->next;
		while(p1)
		{
			if(p1==p2)
				return p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		return NULL;
	}
	else if(p1_len > p2_len)
	{
		int diff_len = p1_len - p2_len;
		for(int i=0; i<diff_len; i++)
			p1 = p1->next;
		while(p1)
		{
			if(p1==p2)
				return p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		return NULL;
	}
	return NULL;
}


















