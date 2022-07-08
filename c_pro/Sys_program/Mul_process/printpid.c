#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	printf("begin..\n");
	pid_t parent = getpid();
	printf("parent PID: %d\n", parent);


	pid_t child = fork();

	if(child == -1)
	{
		perror("fork error");
		exit(1);
	}
	else if(child > 0)
	{
		printf("my PID is: %d\n", parent);
	}
	else if(child==0)
	{
		printf("my PID is: %d\n", getpid());
	}
	printf("The end\n");
	return 0;
}
