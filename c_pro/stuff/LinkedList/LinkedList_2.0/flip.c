#include "total.h"

struct node *flip_LL(struct node *p)
{
	if (p == NULL || p->next == NULL)
		return p;

	struct node *head = NULL;
	struct node *pre = NULL;

	while (p != NULL)
	{
		head = p;
		p = p->next;
		head->next = pre;
		pre = head;
	}
	return head;
}

struct node *flip_recurse(struct node *head)
{
	if (head == NULL || head->next == NULL) {
		return head;
	}

	struct node *newhead = flip_recurse(head->next);
	head->next->next = head;
	head->next = NULL;
	return newhead;
}


struct node *flip_between_nm(struct node *head, int n, int m)
{
	if (head == NULL || head->next == NULL || n >= m) {
		return head;
	}

	int i;
	struct node *tmp = NULL;
	struct node *res = (struct node *)malloc(sizeof(struct node));
	res->next = head;
	struct node *pre = res;
	struct node *newhead = NULL;

	for (i=1; i<n; i++)
	{
		pre = head;
		head = head->next;
	}
	
	for (i=n; i<m; i++)
	{
		tmp = head->next;
		head->next = tmp->next;
		tmp->next = pre->next;
		pre->next = tmp;
	}
	
	newhead = res->next;
	free(res);
	return newhead;
}


struct node *flip_perKground(struct node *head, int k)
{
	int i;
	struct node *tail = head;
	for (i=0; i<k; i++)
	{
		if (tail == NULL)
			return head;
		tail = tail->next;
	}
	struct node *pre = NULL;
	struct node *tmp = NULL;
	struct node *cur = head;
	for (i=0; i<k; i++) {
		tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	head->next = flip_perKground(tail, k);
	return pre;
}


struct node *flip_perK(struct node *head, int k)
{
	if (head == NULL)
		return head;

	int i;
	struct node *tail = head;
	struct node *cur = head;
	struct node *tmp = head;
	struct node *pre = NULL;
	for (i=0; i<k; i++) {
		if (tail == NULL)
			return head;
		tail = tail->next;
	}

	for (i=0; i<k; i++) {
		tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	head->next = flip_perK(tail, k);
	return pre;
}
