#include "total.h"

ListNode *flip_Whole(ListNode *head)
{
	ListNode *cur = NULL;
	ListNode *pre = NULL;

	while (head != NULL)
	{
		cur = head;
		head = head->next;
		cur->next = pre;
		pre = cur;
	}
	return cur;
}

ListNode *flip_recurse(ListNode *head)
{
	if (head == NULL || head->next == NULL) {
		return head;
	}

	ListNode *newhead = flip_recurse(head->next);
	head->next->next = head;
	head->next = NULL;
	return newhead;
}

ListNode *flip_between_nm(ListNode *head, int n, int m)
{
	if (head == NULL || head->next == NULL || n >= m) {
		return head;
	}

	int i;
	ListNode *res = (ListNode *)malloc(sizeof(ListNode));
	res->next = head;
	ListNode *pre = res;
	ListNode *tmp = NULL;
	ListNode *newhead = NULL;

	for (i=1; i<n; i++)
	{
		pre = head;
		head = head->next;
	}
	for (i=n; i<m && head!=NULL; i++)
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


ListNode *flip_perNgrop(ListNode *head, int n)
{
	if (head == NULL || head->next == NULL || n<=0)
		return head;

	int i = 1;
	int mid = n-1;
	ListNode *res = (ListNode *)malloc(sizeof(ListNode));
	res->next = head;
	ListNode *pre = res;
	ListNode *tmp = NULL;
	ListNode *newhead = NULL;

	while (head != NULL)
	{
		for ( ; i<n && head != NULL && head->next != NULL; i++)
		{
			tmp = head->next;
			head->next = tmp->next;
			tmp->next = pre->next;
			pre->next = tmp;
		}
		n += mid;
		pre = head;
		if (head == NULL && head->next == NULL)
			break;
		head = head->next;
	}
	//printf("loop done\n");
	newhead = res->next;
	free(res);
	return newhead;
}


ListNode *flip_perNgrop_recurse(ListNode *head, int n)
{
	int i;
	ListNode *tail = head;
	for (i=0; i<n; i++)
	{
		if (tail == NULL)
			return head;
		tail = tail->next;
	}

	ListNode *pre = NULL;
	ListNode *tmp = NULL;
	ListNode *cur = head;
	for (i=0; i<n; i++)
	{
		tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}

	head->next = flip_perNgrop_recurse(tail, n);

	return pre;

}
