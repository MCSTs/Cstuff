#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDWR);
	if(fd == -1)
	{
		perror("open error");
		exit(1);
	}
	char cur[200];
	char *p = cur;
	p = getcwd(cur, 200);
	printf("%s\n", cur);

	struct stat ms;
	stat(argv[1], &ms);
	if( S_ISREG(ms.st_mode))
		printf("It's a regular file\n");

	int len = strlen(p);
	printf("len: %d\n", len); 
	cur[len] = '/';
	cur[len+1] = '\0';

	strcat(p, "demo2");
	printf("newlen: %ld\n", strlen(p));
	printf("new: %s\n", p);

	stat(p, &ms);
	if( S_ISREG(ms.st_mode) )
		printf("It's a regular file\n");
	else if( S_ISDIR(ms.st_mode))
		printf("It's a directory file\n");
	else if( S_ISFIFO(ms.st_mode))
		printf("It's a pipe file\n");

	lseek(fd, 3, SEEK_END);
	int re = write(fd, "Q", 2);
	if(re==-1)
	{
		perror("write error");
		exit(1);
	}

	close(fd);

	return 0;
}

