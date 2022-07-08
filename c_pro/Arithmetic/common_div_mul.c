#include <stdio.h>

int divisor(int sum1, int sum2)
{
	int mid1;
	if(sum1<sum2)
	{
		mid1 = sum1;
		sum1 = sum2;
		sum2 = mid1;
	}
	while(1)
	{
		mid1 = sum1 % sum2;
	
		if(mid1==0)
		{
			return sum2;
		}
		sum1 = sum2;
		sum2 = mid1;
	}
}


int multiple(int sum1, int sum2)
{
	return sum1 * sum2 / divisor(sum1, sum2);		
}

int main(void)
{
	int a,b;
	printf("Please input two number to calculate their common divior and common multiple.\n");
	scanf("%d%d", &a, &b);
	printf("common divisor is: %d\ncommon multiple is: %d\n", divisor(a, b), multiple(a, b));
	return 0;
}
