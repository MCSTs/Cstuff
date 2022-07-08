#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	pid_t pid, wpid;
	int i;

	for(i=0; i<3; i++)
	{
		pid = fork();
		if(pid==0)
			break;
		else if(pid == -1)
		{
			perror("fork error");
			exit(1);
		}
	}

	switch(i)
	{
		case 0: // process 1 execute 'ps'
			{
				sleep(1);
				printf("I'm first child proc, pid: %d\n", getpid());
				execlp("ps", "ps", NULL);
				printf("exec error\n");
				exit(1);
			}break;
		case 1: // process 2 execute '1'
			{
				sleep(1);
				printf("I'm second child proc, pid: %d\n", getpid());
				execl("./1", "1",  NULL);
				printf("exec error\n");
				exit(1);
			}break;
		case 2: // process 3 execute '2'
			{
				sleep(1);
				printf("I'm third child proc, pid: %d\n", getpid());
				execl("./2", "2", NULL);
				printf("exec error\n");
				exit(1);
			}break;
		case 3: // parent process
			{
				while((wpid = waitpid(-1, NULL, WNOHANG)) != -1)
				{
					if(wpid > 0)
						printf("I'm parent proc, recycle child process, pid: %d\n", pid);
					else if(wpid == 0)
					{
						sleep(1);
						continue;
					}
					else if(wpid == -1)
					{
						perror("waitpid error");
						exit(1);
					}
				}
			}break;
	}
	return 0;
}
