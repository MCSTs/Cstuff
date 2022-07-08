#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	pid_t pid;
	pid_t wpid;
	pid = fork();

	int status;
	if(pid == -1)
	{
		perror("fork error");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("child process, pid: %d\n", getpid());
		sleep(10);
		printf("------child process die--------\n");
		return 77;
	}
	else if(pid > 0)
	{
		printf("parent process, pid: %d\n", getpid());
		printf("now begin wait to child process...\n");
		wpid = wait(&status);	//如果子进程未终止，父进程阻塞在该处
		if(wpid == -1)
		{
			perror("wait error");
			exit(1);
		}
		if(WIFEXITED(status)) //--> 若为真，说明子进程正常终止
		{
			printf("child exit with %d\n", WEXITSTATUS(status));
		}
		if(WIFSIGNALED(status)) //--> 若为真，说明子进程被某信号终止
		{
			printf("child kill with signal %d\n", WTERMSIG(status));
			// --> 获取终止子进程的信号号
		}
		printf("parent wait finish\n");
	}
	return 0;
}
