#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *pp(void *arg)
{
	printf("This is a thread\n");
	return NULL;
}

int main(void)
{
	pthread_t tid;
	pthread_create(&tid, NULL, pp, NULL);
	printf("This is the main\n");
	pthread_exit(NULL);
}
