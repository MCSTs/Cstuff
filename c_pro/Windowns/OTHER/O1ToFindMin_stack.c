#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int stack[300];
static int TOP = 0;

void push(int value)
{
	if(TOP==300)
	{
		printf("the stack is full\n");
		return;
	}

	*(stack	+ TOP) = value;
	TOP++;
}

void pop()
{
	if(TOP==0)
	{
		printf("the stack is empty\n");
		return;
	}
	TOP--;
	return;
}

int top()
{
	int tmp = TOP;
	tmp--;
	return *(stack + tmp);
}

int min()
{
	int MIN = INT_MAX;
	int i;
	for(i=0; i<TOP; i++)
	{
		if(stack[i] < MIN)
			MIN = stack[i];
	}
	return MIN;
}

int main(void)
{
	push(9);
	push(1);
	push(6);
	printf("MIN: %d\n", min());
	pop();
	pop();
	printf("%d\n", TOP);
	printf("MIN: %d\n", min());
	return 0;
}
