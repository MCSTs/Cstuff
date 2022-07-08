#include <stdio.h>

static int step = 0;
void hanio(int n, char A, char B, char C)
{
	if(n==2)
	{
		printf("%c-->%c\n", A, B);
		step++;
		printf("%c-->%c\n", A, C);
		step++;
		printf("%c-->%c\n", B, C);
		step++;
		return;
	}
	hanio(n-1, A, C, B);
	printf("%c-->%c\n", A, C);
	step++;
	hanio(n-1, B, A, C);
	return;
}

int main()
{
	int time;
	char A, B, C;
	while(scanf("%d%c%c%c", &time, &A, &B, &C))
	{
		step = 0;
		hanio(time, A, B, C);
		printf("Sum is: %d\n", step);
		while(getchar()!='\n');
	}
	return 0;
}
