#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char buf[20];
	sscanf(argv[1], "%d%2[rw]",&fd, buf);

	printf("%d: %s\n", fd, buf);
	fflush(stdout);
	return 0;
}
