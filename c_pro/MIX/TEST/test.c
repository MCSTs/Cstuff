#include <stdio.h>

int main(void)
{
	printf("BUFSIZ: %d\n", BUFSIZ);

#if 0
	int a;
	char c;
	scanf("%d", &a);
	c = getchar();
	printf("no.1 c ascii is: %d", c);
	c = getchar();
	printf("no.2 c ascii is: %d\n", c);
#endif

	printf("NULL: %p\n", NULL);
	printf("EOF: %d\n", EOF);

	return 0;
}
