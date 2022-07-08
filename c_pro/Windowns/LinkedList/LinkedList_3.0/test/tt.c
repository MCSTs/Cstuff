#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

enum {
	red = 5,
	green,
	blue
};

int main(void)
{
	printf("red: %d\n", red);
	int b = green;
	printf("green: %d\n", green);
	printf("blue: %d\n", blue);
	printf("b: %d\n", b);
	printf("sizeof(green): %ld\n", sizeof(green));

	return 0;
}
