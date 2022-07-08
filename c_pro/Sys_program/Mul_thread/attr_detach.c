#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void sys_error(int num, char *ms)
{
	fprintf(stderr, "%s: %s\n", ms, strerror(num));
	exit(1);
}


void *func(void *arg)
{
	printf("thread, tid=%lu\n", pthread_self());
	return NULL;
}

int main(void)
{
	pthread_t tid;
	int re;

	pthread_attr_t attr;

	// initialize attribute
	re = pthread_attr_init(&attr);
	if(re != 0)
		sys_error(re, "init error");

	// setting detach attribute
	re = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); 
	if(re != 0)
		sys_error(re, "setdetachstate error");

	// use the attribute to creata a thread
	re = pthread_create(&tid, &attr, func, NULL);
	if(re != 0)
		sys_error(re, "create error");

	// destroy the attribute 
	re = pthread_attr_destroy(&attr);
	if(re != 0)
		sys_error(re, "destroy error");
	
	// use join to inspect the attr
	re = pthread_join(tid, NULL);
	if(re != 0)
		sys_error(re, "join error");

	return 0;
}

