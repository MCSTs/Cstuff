#include <stdlib.h>
#include "total.h"

struct node* odd_even_reset(struct node* head)
{
	if(head==NULL || head->next==NULL)
		return head;

	struct node* f1 = head;
	struct node* f2 = head->next;
	struct node* f2_head = f2;

	while(f2!=NULL && f2->next!=NULL)
	{
		struct node* tmp = f2->next;
		f2->next = tmp->next;
		f1->next = tmp;
		f1 = tmp;
		f2 = tmp->next;
	}

	f1->next = f2_head;
	return head;
}
