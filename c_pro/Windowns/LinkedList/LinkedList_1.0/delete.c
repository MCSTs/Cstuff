#include <stdlib.h>
#include "total.h"

struct node* delete_rep(struct node* head)
{
	if(head==NULL || head->next==NULL) 
		return head;
	struct node* res = (struct node* )malloc(sizeof(struct node)); 
	res = head;
	struct node* cur = res;
	head = head->next;

	while(head)
	{
		if(cur->value == head->value)
		{
			struct node* tmp = head->next;
			head->next = NULL;
			free(head);
			cur->next = tmp; 
			head = tmp;
		}
		else
		{
			cur = head;
			head = head->next;
		}
	}
	return res;
}

struct node* delete_rep_all(struct node* head)
{
	if(head==NULL || head->next==NULL) 
		return head;
	struct node* res = (struct node* )malloc(sizeof(struct node)); 
	res->next = head;
	struct node* pre = res;
	struct node* cur = head; 
	head = head->next;

	while(head)
	{
		if(cur->value == head->value)
		{
			while(head && cur->value==head->value)
			{
				cur = head;
				head = head->next;
			}

			pre->next = head;
			if(head != NULL)
			{
				cur = head;
				head = head->next;
			}
		}
		else
		{
			pre = cur;
			cur = head;
			head = head->next;
		}
	}
	return res->next;
}
