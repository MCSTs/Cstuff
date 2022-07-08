#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int count = 0;
pthread_rwlock_t lock;

void sys_error(int num, char *ms)
{
	if(num != 0)
	{
		fprintf(stderr, "%s: %s\n", ms, strerror(num));
		pthread_exit(NULL);
	}
	return;
}

void *read_thread(void *arg)
{
	int i = (int)arg;

	usleep(1000);
	int re = pthread_rwlock_rdlock(&lock);
	sys_error(re, "rdlock error");

	printf("----------It's reading no.%d, count = %d\n", i+1, count);
	re = pthread_rwlock_unlock(&lock);
	sys_error(re, "unlock error");

	return NULL;
}

void *write_thread(void *arg)
{
	int i = (int )arg;

	usleep(1000);
	int re = pthread_rwlock_wrlock(&lock);
	sys_error(re, "wrlock error");

	count++;
	printf("It's writing no.%d, count = %d\n", i+1, count);
	re = pthread_rwlock_unlock(&lock);
	sys_error(re, "unlock error");

	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t tid[8];
	int i;

	int re = pthread_rwlock_init(&lock, NULL);
	sys_error(re, "rwlock_init error");

	while(1)
	{
		for(i=0; i<5; i++)
		{
			re = pthread_create(&tid[i], NULL, read_thread, (void *)i);
			sys_error(re, "create_r_thread error");
		}
		for(i=5; i<8; i++)
		{
			re = pthread_create(&tid[i], NULL, write_thread, (void *)i);
			sys_error(re, "create_w_thread error");
		}

		// recycle thread
		for(i=0; i<8; i++)
		{
			re = pthread_join(tid[i], NULL);
			sys_error(re, "join error");
		}

		sleep(1);
	}

	// destroy rwlock
	re = pthread_rwlock_destroy(&lock);
	sys_error(re, "destroy_lock error");

	return 0;
}
