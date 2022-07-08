#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

struct ms{
	int val;
	struct ms *next;
};
struct ms *head = NULL;

// static initialize 
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void sys_error(int num, char *ms)
{
	if(num != 0)
	{
		fprintf(stderr, "%s: %s\n", ms, strerror(num));
		pthread_exit(NULL);
	}
}

void *producer(void *arg)
{
	struct ms *new;
	int re;
	for(;;)
	{

		new = (struct ms *)malloc(sizeof(struct ms));
		new->val = rand() % 1000 + 1;
		new->next = NULL;
		printf("----------the producer writ: %d\n", new->val);

		// lock
		re = pthread_mutex_lock(&mutex);
		sys_error(re, "lock error");

		new->next = head;
		head = new;

		// unlock
		re = pthread_mutex_unlock(&mutex);
		sys_error(re, "unlock error");
		
		// inform wait
		re = pthread_cond_signal(&cond);
		sys_error(re, "signal error");


		sleep(rand() % 4);
	}

	return NULL;
}

void *consumer(void *arg)
{
	struct ms *p;
	int re;

	for(;;)
	{
		// lock
		re = pthread_mutex_lock(&mutex);
		sys_error(re, "lock error");

		while(head == NULL)
		{
			// wait and unlock
			re = pthread_cond_wait(&cond, &mutex);
			sys_error(re, "wait error");
		}

		// read the head node, and delete it
		p = head;	
		head = p->next;

		// unlock
		re = pthread_mutex_unlock(&mutex);
		sys_error(re, "unlock error");

		printf("the consumer read the ms: %d\n", p->val);
		free(p);

		sleep(rand() % 4);
	}

	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t pid, cid;
	int re;
	srand(time(NULL));

	re = pthread_create(&pid, NULL, producer, NULL);
	sys_error(re, "create_p error");
	re = pthread_create(&cid, NULL, consumer, NULL);
	sys_error(re, "create_c error");

	// recycle thread
	re = pthread_join(pid, NULL);
	sys_error(re, "join_p error");
	re = pthread_join(cid, NULL);
	sys_error(re, "join_c error");

	// destroy lock
	re = pthread_mutex_destroy(&mutex);
	sys_error(re, "destroy_mutex error");
	re = pthread_cond_destroy(&cond);
	sys_error(re, "destroy_cond error");

	return 0;
}

