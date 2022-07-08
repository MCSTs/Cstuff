#include "total.h"

void joint_commondNode(ListNode *p1, ListNode *p2, int p1_nu, int p2_nu)
{
	int i;
	ListNode *tmp = NULL;

	for (i=1; i<p1_nu; i++) 
		p1 = p1->next;
	for (i=1; i<p2_nu; i++) 
		p2 = p2->next;

	tmp = p1->next;
	p1->next = p2;

	free_LL(tmp, NULL);
}

int has_commondNode(ListNode *p1, ListNode *p2)
{
	if (p1 == NULL || p2 == NULL)
		return 0;

	int len1 = 0;
	int len2 = 0;
	int diff = 0;
	ListNode *head1 = p1;
	ListNode *head2 = p2;

	while (p1 != NULL) {
		p1 = p1->next;
		len1++;
	}
	while (p2 != NULL) {
		p2 = p2->next;
		len2++;
	}
	p1 = head1;
	p2 = head2;

	if (len1 > len2) {
		diff = len1 - len2;
		while (diff--) 
			p1 = p1->next;
	}
	else {
		diff = len2 - len1;
		while (diff--) 
			p2 = p2->next;
	}
	while (p1 != NULL || p2 != NULL) {
		p1 = p1->next;
		p2 = p2->next;
		if (p1 == p2 && p1 != NULL)
			return 1;
	}
	return 0;
}

int has_commondNode_v2(ListNode *p1, ListNode *p2)
{
	if (p1 == NULL || p2 == NULL)
		return 0;

	int flag1 = 0;
	int flag2 = 0;
	ListNode *head1 = p1;
	ListNode *head2 = p2;

	for (;;) 
	{
		p1 = p1->next;
		p2 = p2->next;
		if (p1 == p2 && p1 != NULL)
			return 1;

		if (p1 == NULL && flag1 == 0) {
			p1 = head2;
			flag1 = 1;
		}
		if (p2 == NULL && flag2 == 0) {
			p2 = head1;
			flag2 = 1;
		}
		if ((p1 == NULL && flag1 == 1)|| (p2 == NULL && flag2 == 1))
			return 0;
	}
	return 0;
}


