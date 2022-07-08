#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sys_error(char *ms)
{
	perror(ms);
	exit(1);
}

int main(int argc, char **argv)
{
	pid_t pid = fork();
	if (pid == -1)
		sys_error("fork error");
	else if (pid == 0)
	{
		printf("I'm child process, pid = %d\n", getpid());
		pid = setsid();
		if (pid == -1)
			sys_error("setsid error");

		printf("after setsid pid = %d\n", pid);

		int re = chdir("/home/mcst");
		if (re == -1)
			sys_error("chdir error");
		for (;;)
		{
			printf("hello\n");
			sleep(3);
		}
	}
	return 0;
}
