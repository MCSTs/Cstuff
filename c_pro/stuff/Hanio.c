#include <stdio.h>

static long long int step = 0;

void hanio(int n, char A, char B, char C)
{
	if(n==2)
	{
		step++;
		//printf("step%d: %c-->%c\n", step, A, B);
		step++;
		//printf("step%d: %c-->%c\n", step, A, C);
		step++;
		//printf("step%d: %c-->%c\n", step, B, C);
		return;
	}

	hanio(n-1, A, C, B);
	step++;
	//printf("step%d: %c-->%c\n", step, A, C);
	hanio(n-1, B, A, C);
	return;
}

int main()
{
	int n;
	char A, B, C;
	while(1)
	{
		step = 0;
		printf("Enter (nABC): ");
		if(scanf("%d%c%c%c", &n, &A, &B, &C)==EOF)
			break;
		hanio(n ,A, B, C);
		printf("Step of sum is: %lld\n", step);
		while(getchar()!='\n');
	}
	return 0;
}
