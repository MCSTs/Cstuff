#include <stdio.h>
#include "total.h"

struct node* sort_rec(struct node* p)
{
	if(p==NULL || p->next==NULL)
		return p;
	struct node* fast = p->next->next;
	struct node* slow = p->next;
	struct node* pre = p;

	while(fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		pre = pre->next;
	}
	pre->next = NULL;

	return merge_rec(sort_rec(p), sort_rec(slow));
}
