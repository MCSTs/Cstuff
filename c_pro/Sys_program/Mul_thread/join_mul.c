#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *func(void *arg)
{
	printf("thread tid: %lu\n", pthread_self());
	return NULL;
}

int main(void)
{
	pthread_t tid[5];
	int re, i;

	for(i=0; i<5; i++)
	{
		re = pthread_create(&tid[i], NULL, func, NULL);
		if(re != 0)
			printf("create %d thread error\n", i+1);
	}

	usleep(1000);
	for(i=0; i<5; i++)
	{
		printf("recycle no.%d thread\n", i+1);
		re = pthread_join(tid[i], NULL);
		if(re != 0)
			printf("join %d thread error\n", i+1);
	}
	return 0;
}
