#include "total.h"

ListNode *coundDown_K(ListNode *head, int k)
{
	if (head == NULL)
		return head;

	ListNode *fast = head;
	ListNode *slow = head;
	int i;
	for (i=0; i<k; i++) {
		fast = fast->next;
		if (fast == NULL)
			break;
	}
	if (i != (k-1) && fast == NULL)
		return NULL;
	else if (i == (k-1) && fast == NULL) 
		return head;

	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}

ListNode *delete_CoundDownK(ListNode *head, int k)
{
	if (head == NULL) {
		return NULL;
	}

	ListNode *fast = head;
	ListNode *slow = head;
	ListNode *pre = NULL;

	int i;
	for (i=0; i<k; i++) {
		fast = fast->next;
		if (fast == NULL)
			break;
	}
	if (i != (k-1) && fast == NULL) {
		return head;
	}
	else if (i == (k-1) && fast == NULL) {
		ListNode *newhead = head->next; 
		head->next = NULL;
		free(head);
		return newhead; 
	}
		

	while (fast != NULL) {
		fast = fast->next;
		pre = slow;
		slow = slow->next;
	}
	pre->next = slow->next;
	slow->next = NULL;
	free(slow);
	return head;
}


