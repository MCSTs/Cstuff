#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

void sys_error(char *ms)
{
	perror(ms);
	exit(1);
}

int main(void)
{
	char *p =(char *)mmap(NULL, 100, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANON, -1, 0);
	if(p == MAP_FAILED)
		sys_error("mmap error");

	pid_t pid = fork();
	if (pid == -1)
		sys_error("fork error");

	else if(pid > 0)
	{
		wait(NULL);
		printf("%s", p);
		munmap(p, 100);
	}
	else if(pid == 0)
	{
		strcpy(p, "hey you\n");
	}

	return 0;
}
