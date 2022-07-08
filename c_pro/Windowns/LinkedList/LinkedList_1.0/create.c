#include <stdio.h>
#include <stdlib.h>
#include "total.h"

struct node* create()
{
	struct node* pHead = NULL;
	struct node* pNew = NULL;
	struct node* pBefor = NULL;
	int num;
	printf("\nPls input one chainlist(any character to end): \n");
	while(scanf("%d", &num))
	{
		pNew = malloc(sizeof(*pNew));
		pNew->value = num;
		pNew->next = NULL;
		if(pHead==NULL)
		{
			pHead = pNew;
			pBefor = pNew;
		}
		else
		{
			pBefor->next = pNew;
			pBefor = pNew;
		}
	}
	while(getchar()!='\n');
	return pHead;
}

struct node* myprint(struct node* pHead)
{
	struct node* head = pHead;
	printf("The result is: ");
	if(pHead==NULL)
		printf("NULL");
	else
	{
		while(pHead)	
		{
			printf("%d ", pHead->value);
			pHead = pHead->next;
		}
	}
	putchar('\n');
	return head;
}

struct node* gettail(struct node* head)
{
	if(head==NULL)
		return head;
	while(head->next != NULL)
	{
		head = head->next;
	}
	return head;
}

struct node* CreateLoop(struct node* head, int LoopNode)
{
	struct node* fist = head;
	struct node* tail = gettail(head);
	while(head->value != LoopNode)
	{
		head = head->next;
	}
	tail->next = head;
	return fist;
}
