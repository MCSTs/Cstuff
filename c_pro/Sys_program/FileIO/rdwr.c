#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	char *fp1 = "./tx1.txt";
	char *fp2 = "./tx3.txt";

	int fd1 = open(fp1, O_RDONLY);
	if(fd1==-1){
		perror("open error");
		exit(1);
	}
	int fd2 = open(fp2, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(fd2==-1){
		perror("open error");
		exit(1);
	}

	char buf[1024];
	int n;
	while((n=read(fd1, buf, 1024)))
	{
		if(n<0)
		{
			perror("read error");
			exit(1);
		}
		write(fd2, buf, n);
	}

	close(fd1);
	close(fd2);

	return 0;
}
