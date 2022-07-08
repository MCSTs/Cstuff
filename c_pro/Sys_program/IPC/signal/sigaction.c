#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sys_error(char *ms)
{
	perror(ms);
	exit(1);
}

void signal_hand(int signum)
{
	printf("\nreceipt signal number is: %d\n", signum);
	printf("sleepping 5 sec now...\n");
	sleep(5);
	return;
}

int main(void)
{
	struct sigaction act;
	struct sigaction oldact;

	act.sa_handler = signal_hand;
	sigemptyset(&act.sa_mask);
	//sigaddset(&act.sa_mask, SIGQUIT);
	act.sa_flags = 0;

	sigaction(SIGINT, &act, &oldact);

	for (;;);
	return 0;
}
