#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sys_error(char *mes)
{
	perror(mes);
	exit(1);
}

int main(int argc, char **argv)
{
	int pipefd[2];
	int re = pipe(pipefd);
	if(re == -1)
		sys_error("pipe error");

	pid_t pid = fork();

	if(pid == -1)
		sys_error("fork error");
	else if(pid > 0)  // parent process execute "ls" > pipefd[1]
	{
		close(pipefd[0]);
		if(dup2(pipefd[1], STDOUT_FILENO) == -1)
			sys_error("dup2 error");

		execlp("ls", "ls", "/etc", NULL);
		sys_error("execlp error");
	}
	else if(pid == 0) // child process execute "wc -l" < pipefd[0]
	{
		close(pipefd[1]);

		if(dup2(pipefd[0], STDIN_FILENO) == -1)
			sys_error("dup2 error");

		execlp("wc", "wc", "-l", NULL);
		sys_error("execlp error");
	}

	return 0;
}
