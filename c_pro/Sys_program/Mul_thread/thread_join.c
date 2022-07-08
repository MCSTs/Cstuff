#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

struct test{
	int val;
	char str[256];
};

void *func(void *arg)
{
	printf("thread, tid=%lu\n", pthread_self());

	struct test *th = (struct test *)arg;
	th->val = 100;
	strcpy(th->str, "hello world----------------------------------------------------------------------------------------------------");
	return (void *)th;
}

int main(void)
{
	pthread_t tid;
	struct test arg;
	struct test *rec;

	printf("arg: %ld\n", sizeof(arg));
	printf("(void *)&arg: %ld\n", sizeof((void *)&arg));

	int re = pthread_create(&tid, NULL, func, (void *)&arg);
	if(re != 0)
		perror("pthread_create erro");

	re = pthread_join(tid, (void *)&rec);
	if(re != 0)
		perror("pthread_join error");

	printf("child thread exit with val=%d, str=%s\n", rec->val, rec->str);
	return 0;
}
