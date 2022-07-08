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
	return;
}

int main(void)
{
	signal(SIGINT, signal_hand);

	while(1);
	return 0;
}
