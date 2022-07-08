#include "total.h"

struct node* head = NULL;
int main(void)
{
#if 0 // Character matching
	char str[20];
	printf("Enter symbol: ");
	scanf("%s", str);
	int re = SymbolMatch(str);
	if(re)
		printf("matching\n");
	else
		printf("mismatching\n");
#endif

#if 1 // Reverse linked list
	int num;
	printf("Push(End with any character): \n");
	while(scanf("%d", &num)){
		push(num);
	}
	myprint(head);

	struct node* newhead = (struct node*)malloc(sizeof(struct node));
	newhead = NULL;
	struct node* tmp = popnode();
	while(tmp)
	{
		tmp->next = newhead;
		newhead = tmp;
		tmp = popnode();
	}
	myprint(newhead);

#endif

	return 0;
}
