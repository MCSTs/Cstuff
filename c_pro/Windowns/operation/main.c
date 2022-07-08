#include "total.h"

int main(void)
{

#if 1 //InfixToPostfix
	char p[20];
	scanf("%s", p);
	char *re = InfixToPostfix(p);
	printf("%s", re);

#endif

	return 0;
}
