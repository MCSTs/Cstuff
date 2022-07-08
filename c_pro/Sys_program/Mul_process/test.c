#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <errno.h>

void test()
{
	printf("in function test\n");
	pthread_exit(NULL);
	printf("function test end, and pthread_exit done\n");
}


void *tt(void *arg)
{
	int re = pthread_join(pthread_self(), NULL);
	if (re != 0) {
		fprintf(stdout, "join(tt): %s\n", strerror(re));
	}
	printf("thread start\n");
	//test();
	printf("thread end\n");
	return NULL;
}

int main(void)
{
	int re = 0;
	pthread_t th;

	re = pthread_create(&th, NULL, tt, NULL);
	if (re != 0) {
		fprintf(stdout, "create: %s\n", strerror(re));
		pthread_exit(NULL);
	}
	
	//for (;;);
	re = pthread_join(th, NULL);
	if (re != 0) {
		fprintf(stdout, "join: %s\n", strerror(re));
		pthread_exit(NULL);
	}

	//pthread_exit(NULL);
	return 0;
}
