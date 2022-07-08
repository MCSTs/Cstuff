#include "total.h"
#include <mcheck.h>

int main(int argc, char *argv[])
{
	/* check whether memory leaks occur */
	mtrace();


	ListNode *head = create_LL();
	ListNode *head2 = create_LL();
/*
	ListNode *head3 = create_LL();
	ListNode *head4 = create_LL();
	ListNode *list[4] = {head, head2, head3, head4};
	ListNode **lists = list;
*/

	//print_LL(head, "source LL: ");

#if 0 // flip Linked list

	//head = flip_Whole(head);
	//head = flip_recurse(head);
	//head = flip_between_nm(head, 2, 5);
	//head = flip_perNgrop(head, 3);
	head = flip_perNgrop_recurse(head, 3);
	//printf("flip done\n");
	print_LL(head, "flip group of 3: ");

#endif 

#if 0 // loop

	if (isloop(head))
		printf("Is a loopLinkedList\n");
	else 
		printf("Isn't a loopLinkedList\n");

	ListNode *tail = insert_loopNode(head, 3);
	printf("Now tailnode linked to the no.3 node\n");

	if (isloop(head)) {
		printf("Is a loopLinkedList\n");
		ListNode *loopnode = fineLoopnode(head);
		printf("loopnode value is: %d\n", loopnode->val);
	}
	else 
		printf("Isn't a loopLinkedList\n");


	ListNode *p = head;
	alarm(20);
	for (;;) {
		printf("%d ", p->val);
		fflush(stdout);
		p = p->next;
		usleep(500 * 1000);
		//sleep(1);
	}

#endif 

#if 0 // joint 

	//head = joint_LinkedList(head, head2);
	//head = joint_LinkedList_recurse(head, head2);

	head = mergeKLists(lists, 4);
	print_LL(head, "jointed: ");
#endif 

#if 0 // countDown
	ListNode *p = coundDown_K(head, 3);
	print_LL(p, "countDown no.3 is: ");
	head = delete_CoundDownK(head, 3);
	print_LL(head, "delete countDown no.3 is: ");
#endif 

#if 1 // commondNode
	//int re = has_commondNode(head, head2);
	int re = has_commondNode_v2(head, head2);
	if (re)
		printf("have common node\n");
	else
		printf("haven't common node\n");

	printf("joint list1 no.3 to list2 no.3 done\n");
	joint_commondNode(head, head2, 3, 3);
	//re = has_commondNode(head, head2);
	re = has_commondNode_v2(head, head2);

	if (re)
		printf("have common node\n");
	else
		printf("haven't common node\n");
#endif 

	free_LL(head, NULL);

	return (((((((((((0)))))))))));

}
