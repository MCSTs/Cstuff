#include "total.h"

bool isloop(Node_t *head, bool do_print)
{
    Node_t *slow = head;
    Node_t *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow){
            if (do_print)
                puts("It's a loop list");
            return true;
        }
    }

    if (do_print)
        puts("It's not a loop list");
    return false;

}

void linkLoop(Node_t *head, int num)
{

	Node_t *p= NULL;

	for (int i=1; i<num && head != NULL; i++) 
		head = head->next;
	p = head;

	while (head->next != NULL) 
		head = head->next;
	head->next = p;	

}

Node_t *findNode_loop(Node_t *head)
{
    if (!isloop(head, false)) 
        return NULL;

    Node_t *fast = head;
    Node_t *slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            break;
    }
    fast = head;

    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;

}
