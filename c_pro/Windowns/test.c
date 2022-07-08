#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *p = "123";
	char *p2 = "123";
	int re = atoi(p) + atoi(p2);
	printf("re = %d\n", re);
	return 0;
}
