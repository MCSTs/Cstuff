#include "total.h"

ListNode *joint_LinkedList(ListNode *p1, ListNode *p2)
{
	if (p1 == NULL)
		return p2;
	if (p2 == NULL)
		return p1;
	ListNode *res = (ListNode *)malloc(sizeof(ListNode));
	res->next = NULL;
	ListNode *cur = res;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->val >= p2->val) {
			cur->next = p2;
			p2 = p2->next;
		}
		else {
			cur->next = p1;
			p1 = p1->next;
		}
		cur = cur->next;
	}

	cur->next = p1==NULL ? p2 : p1;

	ListNode *newhead = res->next;
	free(res);
	return newhead;

}

ListNode *joint_LinkedList_recurse(ListNode *p1, ListNode *p2)
{
	if (p1 == NULL)
		return p2;
	if (p2 == NULL)
		return p1;

	if (p1->val <= p2->val) {
		p1->next = joint_LinkedList_recurse(p1->next, p2);
		return p1;
	}
	else {
		p2->next = joint_LinkedList_recurse(p1, p2->next);
		return p2;
	}

}


//struct ListNode* mergeKLists(struct ListNode** lists, int listslen);

static ListNode *mergeKLists_LR(ListNode **lists, int left, int right)
{
	if (left > right) {
		return NULL;
	}
	else if (left == right) {
		return lists[left];
	}

	int mid = (left + right) / 2;
	return joint_LinkedList(mergeKLists_LR(lists, left, mid), mergeKLists_LR(lists, mid+1, right));

}

ListNode *mergeKLists(ListNode **lists, int listslen)
{
	return 	mergeKLists_LR(lists, 0, listslen-1);
}



