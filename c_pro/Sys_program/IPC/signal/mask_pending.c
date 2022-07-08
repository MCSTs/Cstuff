#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sys_err(char *ms)
{
	perror(ms);
	exit(1);
}

void printbit(sigset_t *set)
{
	for(int i=1; i<=32; i++)
	{
		if(sigismember(set, i))
			putchar('1');
		else
			putchar('0');
	}
	putchar('\n');
}

int main(void)
{
	sigset_t set, pset;

	sigemptyset(&set);

	sigaddset(&set, SIGINT);
	//sigaddset(&set, SIGQUIT);
	sigaddset(&set, SIGBUS);
	sigaddset(&set, SIGKILL);

	int re = sigprocmask(SIG_BLOCK, &set, NULL);
	if(re == -1)
		sys_err("sigprocmask error");

	while(1)
	{
		re = sigpending(&pset);
		if(re == -1)
			sys_err("sigpending error");

		printbit(&pset);
		sleep(1);
	}
	return 0;
}
