#include "total.h"


void push(int num)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->val = num;
	new->next = head;
	head = new;
}

void pushchar(char sign)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->sign = sign;
	new->next = head;
	head = new;
}

int pop()
{
	if(head==NULL)
		return -1;
	int tmp = head->val;
	struct node* tmp2 = head; 
	head = head->next;
	free(tmp2);
	return tmp;
}

struct node* popnode()
{
	if(head==NULL)
		return NULL;
	struct node* tmp = head;
	head = head->next;
	return tmp;
}

char popchar()
{
	if(head==NULL)
		return '\0';
	char tmp = head->sign;
	struct node* tmp2 = head; 
	head = head->next;
	free(tmp2);
	return tmp;
}

int top()
{
	if(head)
		return 1;
	else
		return 0;
}

void myprint(struct node* head)
{
	struct node* tmp = head;
	printf("Result is: ");
	while(tmp)
	{
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	putchar('\n');
}
