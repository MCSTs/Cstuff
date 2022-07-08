#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	pid_t pid;
	int pipefd[2];
	char *src = "test message\n";
	char *buf[1024];

	int re = pipe(pipefd);
	if(re == -1)
	{
		perror("pipe error");
		exit(1);
	}

	pid = fork();
	if(pid == -1)
	{
		perror("fork error");
		exit(1);
	}
	else if(pid > 0 )
	{
		close(pipefd[0]);
		int re = write(pipefd[1], src, strlen(src));
		if(re == -1)
		{
			perror("write pipefd[1] error");
			exit(1);
		}
		close(pipefd[1]);
	}
	else if(pid == 0)
	{
		close(pipefd[1]);
		int re = read(pipefd[0], buf, 1024);
		if(re == -1)
		{
			perror("read pipefd[0] error");
			exit(1);
		}
		if(write(STDOUT_FILENO, buf, re) == -1)
		{
			perror("write stdout error");
			exit(1);
		}
		close(pipefd[0]);
	}
	return 0;
}
