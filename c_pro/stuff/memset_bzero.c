#include <stdio.h>
#include <string.h>
#include <strings.h>

struct tt{
	int a;
	char b[10];
	struct tt *pp;
	int arr[3];
};
int main(void) 
{
	struct tt dd;
	struct tt demo = {100, "hello\n", &dd, {3,3,3}};
	printf("source data is: \n");
	printf("int a=%d\n", demo.a);
	printf("char b[10]=%s", demo.b);
	printf("struct tt *pp=%p\n", demo.pp);
	printf("int arr[3]=%d %d %d\n", demo.arr[0], demo.arr[1], demo.arr[2]);
	putchar('\n');

	//bzero(&demo, sizeof(demo));
	memset(&demo, 0, sizeof(demo));

	printf("setting zero after: \n");
	printf("int a=%d\n", demo.a);
	printf("char b[10]=%s\n", demo.b);
	printf("char b[0](int)=%d\n", demo.b[0]);
	printf("struct tt *pp=%p\n", demo.pp);
	printf("int arr[3]=%d %d %d\n", demo.arr[0], demo.arr[1], demo.arr[2]);
	return 0;
}
