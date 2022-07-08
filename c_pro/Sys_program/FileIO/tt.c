#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

int main(void)
{
	printf("%d\n", PIPE_BUF);
	return 0;
}
