#include "total.h"

void sys_error(int num, char *ms)
{
	if (num == -1) {
		perror(ms);
		exit(1);
	}
	return;
}

int main(int argc, char **argv)
{
	if (argc < 3) {
		fprintf(stderr, "argument missing:(./Server dir port)\n");
		return 1;
	}
	
	// get the port
	int port = atoi(argv[1]);
	
	// change the directory of working
	int re = chdir(argv[2]);
	sys_error(re, "chdir error");

	// start listening
	printf("starting epoll_run...\n");
	epoll_run(port);
	
	return 0;
}
