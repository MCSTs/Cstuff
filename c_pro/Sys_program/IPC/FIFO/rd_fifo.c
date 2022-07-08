#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int re = open("myfifo", O_RDONLY);
	if(re == -1)
	{
		perror("open error");
		exit(1);
	}

	int n;
	char buf[1024];
	while(1)
	{
		n = read(re, buf, 1024);
		write(STDOUT_FILENO, buf, n);
		sleep(1);
	}

	close(re);
	return 0;
}
