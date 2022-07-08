#include "total.h"

struct node *joint2_Orderd(struct node *p1, struct node *p2)
{
	if (p1 == NULL)
		return p2;
	if (p2 == NULL)
		return p1;

	struct node *res = (struct node *)malloc(sizeof(struct node));
	struct node *cur = res;

	while (p1 != NULL && p2 != NULL) {
		if (p1->val <= p2->val) {
			cur->next = p1;
			p1 = p1->next;
		}
		else {
			cur->next = p2;
			p2 = p2->next;
		}
		cur = cur->next;
	}
	cur->next = p1==NULL ? p2 : p1;
	p1 = res->next;
	free(res);
	return p1;
}


struct node *joint2_Orderd_recurse(struct node *p1, struct node *p2)
{
	if (p1 == NULL)
		return p2;
	if (p2 == NULL)
		return p1;

	if (p1->val <= p2->val) {
		p1->next = joint2_Orderd_recurse(p1->next, p2);
		return p1;
	}
	else {
		p2->next = joint2_Orderd_recurse(p1, p2->next);
		return p2;
	}

}

static struct node *Kto2(struct node **lists, int left, int right)
{
	if (left >= right)
		return lists[left];

	int mid = (left + right) / 2;
	return joint2_Orderd(Kto2(lists, left, mid), Kto2(lists, mid+1, right));
}

struct node *jointK_Orderd(struct node **lists, int listLen)
{
	 return Kto2(lists, 0, listLen-1);
}
