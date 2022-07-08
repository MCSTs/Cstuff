#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <event2/event.h>

#define FIFO_NAME "myfifo"
#define FIFO_MODE 0644

void sys_error(int num, char *ms)
{
	if (num == -1) {
		perror(ms);
		exit(1);
	}
	return;
}

void read_cb(evutil_socket_t fd, short what, void *arg)
{
	char buf[BUFSIZ];
	int n = read(fd, buf, sizeof(buf));
	write(STDOUT_FILENO, buf, n);
	sleep(1);

	return;
}

int main(void)
{
	int re = 0;
	int fd = 0;
	struct event_base *base = NULL;
	struct event *ev = NULL;

	unlink(FIFO_NAME);
	re = mkfifo(FIFO_NAME, FIFO_MODE);
	sys_error(re, "mkfifo error");

	fd = open(FIFO_NAME, O_RDONLY | O_NONBLOCK);		
	sys_error(fd, "open error");

	// create the event_base
	base = event_base_new();

	// create event
	ev = event_new(base, fd, EV_READ | EV_PERSIST, read_cb, NULL);

	// add the event into base
	re = event_add(ev, NULL);
	sys_error(re, "event_add error");

	// dispatch
	re = event_base_dispatch(base);
	sys_error(re, "dispatch error");

	// destroy the event_base
	event_base_free(base);

	return 0;
}
