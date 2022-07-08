#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define ms1 "I'm no.1\n"
#define ms2 "I'm no.2\n"
#define ms3 "I'm no.3\n"

void sys_error(char *ms)
{
	perror(ms);
	exit(1);
}

int main(int argc, char *argv[])
{
	int i=0;
	int pipefd[2];

	int re = pipe(pipefd);

	pid_t pid;

	char *buf[BUF_SIZE];
	if(re == -1)
		sys_error("pipe error");
	
	for(i=0; i<3; i++)
	{
		pid = fork();
		if(pid == -1)
			sys_error("fork error");
		else if(pid == 0)
			break;
	}

	switch(i)
	{
		case 0:
			{
				close(pipefd[0]);
				write(pipefd[1], ms1, strlen(ms1));
				if(re == -1)
					sys_error("write no.1 child error");
				close(pipefd[1]);
			}break;
		case 1:
			{
				close(pipefd[0]);
				int re = write(pipefd[1], ms2, strlen(ms2));
				if(re == -1)
					sys_error("write no.2 child error");
				close(pipefd[1]);
			}break;
		case 2:
			{
				sleep(1);
				close(pipefd[0]);
				int re = write(pipefd[1], ms3, strlen(ms3));
				if(re == -1)
					sys_error("write no.3 child error");
				close(pipefd[1]);
			}break;
		case 3: // parent process
			{
				wait(NULL);
				wait(NULL);
				wait(NULL);

				close(pipefd[1]);
				int n = read(pipefd[0], buf, BUF_SIZE);
				write(STDOUT_FILENO, buf, n);
				close(pipefd[0]);
			}break;
	}
	return 0;
}
