#include "total.h"

struct node *create_LL(int num)
{
	int value = 0;
	struct node *new = NULL;
	struct node *tail = NULL;
	struct node *head = NULL;
	printf("enter th.%d linked list:", num);
	for (;;)
	{
		if (scanf("%d", &value) == 0)
			break;
		new = (struct node *)malloc(sizeof(struct node));
		if (new == NULL) {
			printf("malloc error\n");
			exit(1);
		}

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
	while (getchar() != '\n');
	return head;
}


struct node *free_LL(struct node *head, struct node *tail)
{
	struct node *tmp = NULL;
	while (head != NULL && head != tail)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	if (head != NULL) {
		head = tail->next;
		free(tail);
	}

	return head;
}
