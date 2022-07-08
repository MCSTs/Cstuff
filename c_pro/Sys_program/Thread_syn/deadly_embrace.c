#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex1;
//pthread_mutex_t mutex2;

void sys_error(int num, char *ms)
{
	if(num != 0)
	{
		fprintf(stderr, "%s: %s\n", ms, strerror(num));
		pthread_exit(NULL);
	}
}

void *func1(void *arg)
{
	int re = pthread_mutex_lock(&mutex1);
	sys_error(re, "lock1 error");

	printf("the lock1 is locked\n");

	re = pthread_mutex_lock(&mutex1);
	sys_error(re, "lock1_1 error");

	printf("thread1, tid=%lu\n", pthread_self());

	re = pthread_mutex_unlock(&mutex1);
	sys_error(re, "unlock1 error");
	//re = pthread_mutex_unlock(&mutex2);
	//sys_error(re, "unlock2 error");
	return NULL;
}

#if 0  // 
void *func2(void *arg)
{
	printf("thread2, tid=%lu\n", pthread_slef());
	return NULL;
}
#endif


int main(void)
{
	int re;
	pthread_t tid, tid2;

	re = pthread_mutex_init(&mutex1, NULL);
	sys_error(re, "init_mutex1 error");

	//re = pthread_mutex_init(&mutex2, NULL);
	//sys_error(re, "init_mutex2 error");
	
	// create thread
	re = pthread_create(&tid, NULL, func1, NULL);
	sys_error(re, "create_thread1 error");

	//re = pthread_create(&tid2, NULL, func1, NULL);
	//sys_error(re, "create_thread2 error");
	
	// recycle thread
	re = pthread_join(tid, NULL);
	sys_error(re, "join error");

	//re = pthread_join(tid2, NULL);
	//sys_error(re, "join2 error");

	printf("main thread, tid=%lu\n", pthread_self());
	return 0;
}
