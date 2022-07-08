#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int var = 100;
int main(void)
{
	pid_t pid;
	pid = fork();
	int local = 20;

	if(pid > 0) {
		printf("var: %d\n", var);
		printf("local: %d\n", local);
		printf("parent, my pid: %d  my parent pid: %d\n",\
				getpid(), getppid());
		var += 100;
		printf("new var: %d\n", var);
		local += 20;
		printf("new local: %d\n", local);
	}
	else if(pid == 0) {
		printf("var: %d\n", var);
		printf("local: %d\n", local);
		printf("child, my pid: %d  my parent pid: %d\n",\
				getpid(), getppid());
		var += 100;
		printf("new var: %d\n", var);

		local += 30;
		printf("new local: %d\n", local);
	}

	return 0;
}
