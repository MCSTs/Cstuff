#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <mcheck.h>

typedef enum {FALSE, TRUE} Boolean;

int main(void)
{
	printf("%d\n", SOMAXCONN);
	Boolean detect = false;
	printf("%d\n", detect);
	return 0;
}

