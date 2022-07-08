#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void *func(void *arg)
{
	printf("thread, tid=%lu\n", pthread_self());
	return NULL;
}

int main(void)
{
	pthread_t tid;

	int re = pthread_create(&tid, NULL, func, NULL);
	if(re != 0)
	{
		fprintf(stderr, "create thread error: %s\n", strerror(re));
		exit(1);
	}

#if 0
	re = pthread_detach(tid);
	if(re != 0)
	{
		fprintf(stderr, "detach thread error: %s\n", strerror(re));
		exit(1);
	}
#endif

	re = pthread_join(tid, NULL);
	if(re != 0)
	{
		fprintf(stderr, "join thread error: %s\n", strerror(re));
		exit(1);
	}
	else
		printf("join thread succeed\n");
	return 0;
}
