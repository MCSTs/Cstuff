#include <stdlib.h>
#include <stdio.h>
#include "total.h"

void release(struct node* pHead, struct node* end)
{
	struct node* mid = NULL;
	while(pHead!=end)
	{
		mid = pHead->next;
		free(pHead);
		pHead = mid;
	}
}

int main(void)
{
	struct node* p = create();

#if 0
	if(isloop(p))
		printf("Have a cycle\n");
	else
		printf("NO cycle\n");

	int NODE;
	printf("enter a loop node: ");
	scanf("%d", &NODE);
	p = CreateLoop(p, NODE);
	if(isloop(p))
	{
		printf("Have a cycle\n");
		p = find_loopnode(p);
		printf("The loop node is: %d\n", p->value);
	}
	else
	{
		printf("NO cycle\n");
	}

#endif 


#if 1
	p = down(p);
#endif

#if 0 
	printf("(n, m): ");
	int n, m;
	scanf("%d%d", &n, &m);
	p = DownPortion(p, n, m);
#endif

#if 0 // joint 2 list
	struct node* p2 = create();
	//p = joint_2(p, p2);
	p = merge2(p, p2);
#endif

#if 0 // addINlist
	struct node* p2 = create();
	p = addInList(p, p2);
#endif

#if 0
	p = sort_rec(p);
#endif

#if 0  //delete
	//p = delete_rep(p);
	p = delete_rep_all(p);
#endif

#if 0 // loop 
	//int re = isloop(p);
	//if(re)
	//	printf("is loop\n");
	//else
	//	printf("is not loop\n");
	p = loop_node(p);
	printf("Loop node: %d\n", p->value);
#endif 

#if 0
	int k;
	printf("enter (k): ");
	scanf("%d", &k);
	//p = reverse_k(p, k);
	p = delete_down_k(p, k);
#endif 

#if 0
	p = odd_even_reset(p);
#endif

	p = myprint(p);
	release(p, NULL);

	return 0;
}
