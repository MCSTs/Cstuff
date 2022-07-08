#include "total.h"

int isloop(ListNode *head)
{
	ListNode *slow = head;
	ListNode *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {
			return 1;
		}
	}

	return 0;
}

ListNode *insert_loopNode(ListNode *head, int num)
{
	ListNode *loopNode = NULL;

	for (int i=1; i<num && head != NULL; i++) 
		head = head->next;
	loopNode = head;

	while (head->next != NULL) 
		head = head->next;
	head->next = loopNode;	
	return head;
}

ListNode *fineLoopnode(ListNode *head)
{
	if ( !isloop(head) )
		return NULL;

	ListNode *fast = head;
	ListNode *slow = head;

	for (;;)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			break;
	}

	while (head != slow)
	{
		head = head->next;
		slow = slow->next;
	}
	return head;
}
