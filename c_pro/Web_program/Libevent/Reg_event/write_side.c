#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <event2/event.h>

#define FIFO_NAME "myfifo"

void sys_error(int num, char *ms)
{
	if (num == -1) {
		perror(ms);
		exit(1);
	}
	return;
}

void write_cb(evutil_socket_t fd, short what, void *arg)
{
	char buf[BUFSIZ];

	fgets(buf, sizeof(buf), stdin);

	write(fd, buf, strlen(buf));
	sleep(1);
	return;
}

int main(void)
{
	int re = 0;
	int fd = 0;
	struct event_base *base = NULL;
	struct event *ev = NULL;

	fd = open(FIFO_NAME, O_WRONLY | O_NONBLOCK);
	sys_error(fd, "open error");

	base = event_base_new();

	ev = event_new(base, fd, EV_WRITE | EV_PERSIST, write_cb, NULL);

	re = event_add(ev, NULL);
	sys_error(re, "event_add error");

	re = event_base_dispatch(base);
	sys_error(re, "dispatch error");

	event_base_free(base);

	return 0;
}
