#include "total.h"

struct node *insert_loopNode(struct node *head, int num)
{
	for (int i=1; i<num && head != NULL; i++) 
		head = head->next;
	if (head == NULL)
		return head;
	struct node *loopNode = head;
	while (head->next != NULL)
		head = head->next;
	head->next = loopNode;
	return head;
}

int isloop(struct node *head)
{
	struct node *fast = head;
	struct node *slow = head;

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return 1;
	}

	return 0;
}

struct node *find_loopNode(struct node *head)
{
	if (!isloop(head))
		return NULL;

	struct node *fast = head;
	struct node *slow = head;

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			break;
	}
	fast = head;
	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}

	return fast;
}
