#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int re = mkfifo("myfifo", 0644);
	if(re == -1)
	{
		perror("mkfifo error");
		exit(1);
	}

	int fd = open("myfifo", O_WRONLY);
	if(fd == -1)
	{
		perror("open error");
		exit(1);
	}

	char buf[1024];
	int i=0;
	while(1)
	{
		sprintf(buf, "step number %d\n", i++);
		write(fd, buf, strlen(buf));
		sleep(1);
	}

	close(fd);
	return 0;
}
