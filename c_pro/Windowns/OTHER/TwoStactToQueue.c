#include <stdio.h>

static int head[100]; 
static int tail[100]; 
static int phead = 0;
static int ptail = 0;

void push(int node)
{
	*(head + phead) = node;
	phead++;
}

int pop()
{
	if(ptail==0)
	{
		while(phead)
		{
			phead--;
			*(tail + ptail) = *(head + phead);
			ptail++;
		}
	}
	ptail--;
	return *(tail + ptail);
}

int main(void)
{
	push(1);
	push(2);
	push(3);
	printf("%d\n", head[0]);
	printf("%d\n", head[1]);
	printf("%d\n", head[2]);
	printf("%d\n", *(head+phead));
	int re1 = pop();
	int re2 = pop();
	int re3 = pop();
	printf("re1: %d\n", re1);
	printf("re2: %d\n", re2);
	printf("re3: %d\n", re3);
	return 0;
}
