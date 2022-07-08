#include <stdio.h>
#include <unistd.h>

int main(void)
{
	alarm(1);
	for(int i=0; ; i++)
	{
		printf("%d ", i);
	}
	return 0;
}
