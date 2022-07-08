#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *func(void *arg)
{
	printf("thread no, pid = %d, tid = %lu\n", getpid(), pthread_self());
	return NULL;
}

int main(void)
{
	pthread_t tid;
	int i, re;
	for(i=0; i<5; i++)
	{
		sleep(i);
		re = pthread_create(&tid, NULL, func, NULL);
		if(re != 0)
			perror("pthread_create error");
	}
	sleep(i);
	printf("main thread, pid = %d, tid = %lu\n", getpid(), pthread_self());
	return 0;
}
