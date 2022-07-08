#include <stdio.h>
#include <stdlib.h>
#include "total.h"

struct node* down(struct node* pHead)
{
	struct node* newhead = NULL;
	struct node* befor = NULL;
	while (pHead)
	{
		newhead = pHead;
		pHead = pHead->next;
		if (newhead == NULL)
			newhead->next = NULL;
		else {
			newhead->next = befor;
		}
		befor = newhead;
	}
	return newhead;
}

struct node* DownPortion(struct node* pHead, int n, int m)
{
    struct node* res = (struct node*)malloc(sizeof(struct node));
    res->next = pHead;
    struct node* cur = res;

    for(int i=0; i<n-1; i++)
	{
        cur=cur->next;
    }

    struct node* end = cur->next;
    for(int i=0; i<m-n; i++)
	{
        struct node* tmp = end->next;
        end->next = tmp->next;
        tmp->next = cur->next;
        cur->next = tmp;
    }
    return res->next;
}

struct node* reverse_k(struct node* head, int k)
{
	if(head==NULL || k<=0)
		return NULL;
	struct node* p = head;
	int sum = 0;
	while(p)
	{
		sum++;
		p = p->next;
	}
	if(k>sum)
		return NULL;
	else if(k==sum)
		return head;
	sum = sum-k;
	for(int i=0; i<sum; i++)
	{
		head = head->next;
	}
	return head;
}


struct node* delete_down_k(struct node* head, int k)
{
	if(head==NULL)
		return NULL;
	if(k<=0)
		return head;

	struct node* p = head;
	struct node* pre = NULL;
	int sum = 0;
	while(p)
	{
		sum++;
		p = p->next;
	}
	if(k>sum)
		return head;
	else if(k==sum)
	{
		return head->next;
	}

	sum = sum-k;
	p = head;
	for(int i=0; i<sum; i++)
	{
		pre = head;
		head = head->next;
	}

	pre->next = head->next;
	head->next = NULL;
	free(head);
	return p;
}





