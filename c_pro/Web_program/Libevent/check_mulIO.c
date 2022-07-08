#include <stdio.h>
#include <event2/event.h>

int main(void)
{
	int i; 
	const char **buf;

	struct event_base *base = event_base_new();
	buf = event_get_supported_methods();
	printf("support IO: ");
	for (i=0; i<3; i++)
	{
		printf("%s ", buf[i]);
	}
	putchar('\n');

	const char *buf2 = event_base_get_method(base);
	printf("current IO: %s\n", buf2);

	return 0;
}

