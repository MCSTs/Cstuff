#include <stdio.h>
#include <stdlib.h>

int Empty(int f, int r)
{
	if(f==-1 && r==-1)
		return 0;
	else
		return 1;
}

void Enqueue(int *arr, int *f, int *r, int val)
{
	if(*f==-1 && *r==-1)	
	{
		*f = *r = 0;
		arr[*f] = val;
		return;
	}
	if((*r+1)%20==*f)
	{
		printf("The array is full\n");
		return;
	}

	*r = (*r+1) % 20;
	arr[*r] = val;
	if((*r+1)%20==*f)
		printf("The array is full\n");
	return;
}

void Dequeue(int *arr, int *f, int *r)
{
	if(*f==-1 && *r==-1)
	{
		printf("The array is empty\n");
		return;
	}
	if(*f==*r)
	{
		*f = *r = -1;
		return;
	}

	*f = (*f+1) % 20;
}

void print(int* arr, int f, int r)
{
	if(f==-1)
		return;
	for(int i=f; i<=r; i++)
		printf("%d ", arr[i]);
	putchar('\n');
}

int main(void)
{
	int front = -1;
	int rear = -1;

	int arrayQue[20]; 

	int num;
	while(scanf("%d", &num))
	{
		Enqueue(arrayQue, &front, &rear, num);
		print(arrayQue, front, rear);

		int flag=1;
		while(flag)
		{
			printf("Dequeue or not(1 or 0): ");
			scanf("%d", &flag);
			if(flag==1)
			{
				Dequeue(arrayQue, &front, &rear);
				print(arrayQue, front, rear);
			}
		}
	}
	return 0;
}
