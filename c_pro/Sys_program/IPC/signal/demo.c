#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define CHLD_PROC 20

void sys_error(char *ms)
{
	perror(ms);
	exit(1);
}

void recycle_child(int signum)
{
	while(wait(NULL)!=-1);
	return;
}

int main(void)
{
	pid_t pid;
	int i, re;

	sigset_t set;
	re = sigemptyset(&set);
	if(re == -1)
		sys_error("sigemptyset error");
	re = sigaddset(&set, SIGCHLD);
	if(re == -1)
		sys_error("sigaddset error");

	re = sigprocmask(SIG_BLOCK, &set, NULL);
	if(re == -1)
		sys_error("sigprocmask error");

	for(i=0; i<CHLD_PROC; i++)
	{
		pid = fork();
		if(pid == -1)
			sys_error("fork error");
		else if(pid == 0)
			break;
	}
	if(i == CHLD_PROC)
	{
		struct sigaction act;
		bzero(&act, sizeof(act));

		act.sa_handler = recycle_child;
		re = sigemptyset(&act.sa_mask);
		if(re == -1)
			sys_error("sigempty error");	
		act.sa_flags = 0;
		
		re = sigaction(SIGCHLD, &act, NULL);
		if(re == -1)
			sys_error("sigaction error");
		re = sigprocmask(SIG_UNBLOCK, &set, NULL);
		if(re == -1)
			sys_error("sigprocmask error");

		//usleep(1000);
		while(1);
	}
	else
		printf("I'm no.%d child process\n", i+1);

	return 0;
}

