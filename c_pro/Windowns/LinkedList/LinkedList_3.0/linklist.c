#include "total.h"

void print_LL(ListNode *head, const char *ms)
{
	printf("%s", ms);	
	if (head == NULL)
		printf("NULL");
	while (head != NULL)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	putchar('\n');
	return;
}

ListNode *create_LL(void)
{
	//setbuf(stdin, NULL);
	//setbuf(stdout, NULL);

	ListNode *head = NULL;
	ListNode *tail = NULL;
	ListNode *new = NULL;
	int value = 0;

	printf("enter the linked list: ");
	for (;;)
	{
		if (scanf("%d", &value) == 0)
			break;

		new = (ListNode *)malloc(sizeof(ListNode));
		new->val = value;
		new->next = NULL;

		if (head == NULL) {
			head = new;
			tail = new;
		}
		else {
			tail->next = new;
			tail = new;
		}
	}
	//fflush(stdin);
	//fflush(stdout);
	while (getchar() != '\n');

	return head;
}

ListNode *free_LL(ListNode *start, ListNode *end)
{
	ListNode *tmp = NULL;

	while (start != end && start != NULL)
	{
		tmp = start->next;
		free(start);
		start = tmp;
	}
	if (end != NULL){
		start = start->next;
		free(end);
	}

	return start;
}
