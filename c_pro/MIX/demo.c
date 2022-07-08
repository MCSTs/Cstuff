#include <stdio.h>

void array1(int *, int);
int main(void)
{
	int n;
	scanf("%d", &n);
	int a[n];
	array1(a, n);
	return 0;
}

void array1(int a[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d", &*(a+i));
	}
}
