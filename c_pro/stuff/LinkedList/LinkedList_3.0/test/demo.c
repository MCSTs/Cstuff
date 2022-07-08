#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char buf[40];
	setbuf(stdout, buf);
		
	printf("1 ");
	//fflush(stdout);
	write(STDOUT_FILENO, "a\n", 2);

	printf("2 ");
	write(STDOUT_FILENO, "b\n", 2);
	//fflush(stdout);

	printf("3 ");
	write(STDOUT_FILENO, "c\n", 2);
	//fflush(stdout);
	exit(1);

	return 0;
}
