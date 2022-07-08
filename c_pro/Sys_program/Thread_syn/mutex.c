#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;

void sys_error(int num, char *ms)
{
	if(num != 0)
	{
		fprintf(stderr, "%s: %s\n", ms, strerror(num));
		pthread_exit(NULL);
	}
}

void *func(void *arg)
{
	int re;
	while(1)
	{
		re = pthread_mutex_lock(&mutex);
		sys_error(re, "mutex_lock error");

		printf("hello ");
		sleep(rand() % 3);
		printf("world\n");

		re = pthread_mutex_unlock(&mutex);
		sys_error(re, "mutex_unlock error");

		sleep(rand() % 3);
	}
}

int main(void)
{
	pthread_t tid;
	int re;

	re = pthread_mutex_init(&mutex, NULL);
	sys_error(re, "mutex_init error");

	re = pthread_create(&tid, NULL, func, NULL);
	sys_error(re, "create error");

	while(1)
	{
		re = pthread_mutex_lock(&mutex);
		sys_error(re, "mutex_lock error");

		printf("HELLO ");
		sleep(rand() % 3);
		printf("WORLD\n");

		re = pthread_mutex_unlock(&mutex);
		sys_error(re, "mutex_unlock error");

		sleep(rand() % 3);
	}
	return 0;
}

