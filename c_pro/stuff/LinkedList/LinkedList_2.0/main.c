#include "total.h"
#include <mcheck.h>

void print_LL(struct node *head, char *ms)
{
	printf("%s", ms);
	if (head == NULL)
		printf("NULL");
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
	return;
}

int main(int argc, char **argv)
{
	/* memory wheather leaks check */
	mtrace();


	struct node *head = create_LL(1);
/*
	struct node *head2 = create_LL(2);
	struct node *head3 = create_LL(3);
	struct node *head4 = create_LL(4);
	struct node *head5 = create_LL(5);
	struct node *lists[] = {head, head2, head3, head4, head5};
*/

#if 0 // flip
	
	//head = flip_LL(head);
	//head = flip_recurse(head);
	//head = flip_between_nm(head, 1, 5);
	//head = flip_perKground(head, 3);
	head = flip_perK(head, 3);
	print_LL(head, "result: ");

#endif 

#if 0 // joint order LL
	//head = joint2_Orderd(head, head2);
	//head = joint2_Orderd_recurse(head, head2);

	head = jointK_Orderd(lists, 5);
	print_LL(head, "result: ");
#endif 

#if 1 // loopNode
	if (argc < 2) {
		printf("%s 'numbers'(position to insert loop node)\n", argv[0]);
		free_LL(head, NULL);
		return 1;
	}
	if (isloop(head))
		printf("It's a loop\n");
	else
		printf("It's not a loop\n");

	printf("Insert a loopNode to number %d positions\n", atoi(argv[1]));
	struct node *tail = insert_loopNode(head, atoi(argv[1]));
	if (isloop(head))
		printf("It's a loop LinkedList\n");
	else
		printf("It's not a loop LL\n");
	struct node *loopNode = find_loopNode(head);
	printf("Find the loop node: %d\n", loopNode->val);
	free_LL(head, tail);

#endif
	//free_LL(head, NULL);

	return 0;
}
