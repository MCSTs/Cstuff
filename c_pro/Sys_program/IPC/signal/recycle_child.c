#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void sys_error(char *ms)
{
	perror(ms);
	exit(1);
}

void recycle_child(int signum)
{
	pid_t wpid;
	int wstatus;
	while(1)
	{
		wpid = wait(&wstatus);
		if(wpid == -1)
			break;
		printf("recycle the child process, pid = %d\n", wpid);
		if(WIFEXITED(wstatus))
			printf("the child(%d) exit value is: %d\n", wpid, WEXITSTATUS(wstatus));
	}
	return;
}

int main(void)
{
	pid_t pid;
	int i;
	sigset_t set;

	sigemptyset(&set);
	sigaddset(&set, SIGCHLD);
	int re = sigprocmask(SIG_BLOCK, &set, NULL);	// setting SIGCHLD block in mask
	if(re == -1)
		sys_error("sigprocmask error");

	for(i=0; i<5; i++)
	{
		pid = fork();
		if(pid == -1)
			sys_error("fork error");
		else if(pid == 0)
			break;
	}

	if(i == 5)
	{
		struct sigaction act;
		act.sa_handler = recycle_child;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;

		sigaction(SIGCHLD, &act, NULL);// register recycle function for SIGCHLD
		sigprocmask(SIG_UNBLOCK, &set, NULL); // then unblock

		usleep(1000);
	}
	else
		printf("I'm child process, pid = %d\n", getpid());
	return 0;
}
