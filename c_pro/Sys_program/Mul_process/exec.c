#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	printf("begin\n");

	int fid = open("proc_ms.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	dup2(fid, STDOUT_FILENO);

	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fork error");
		exit(1);
	}

	if(pid == 0) 
	{
		execlp("ps", "ps", "-aux", NULL);
		perror("execlp error");
		exit(1);
	}
	else if(pid > 0)
	{
		sleep(1);
		printf("My PID is: %d\n", getpid());
	}

	close(fid);
	return 0;
}
