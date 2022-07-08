#include "total.h" 

void send_respond(int cfd, int st_num, char *st_ms, char *filety)
{
	char msbuf[BUFSIZ] = {0};
	int re;

	sprintf(msbuf, "HTTP/1.1 %d %s\r\n", st_num, st_ms);
	sprintf(msbuf+strlen(msbuf), "%s\r\n", filety);

con:
	re = send(cfd, msbuf, strlen(msbuf), 0);
	if (re == -1) {
		if (errno == ECONNABORTED || errno == EINTR || errno == EBADF || \
				errno == ECONNRESET || errno == EAGAIN)
			goto con;
	}
	sys_error(re, "send error");
	return;
}


void send_404err(int cfd)
{
	int re, n;
	int fd;
	char buf[BUFSIZ];

	send_respond(cfd, 404, "not found", "Content-Type: text/html; charset=utf-8");
	fd = open("404.html", O_RDWR);
	sys_error(fd, "open error");

	while (n=read(fd, buf, sizeof(buf))) {
		if (re == -1) {
			if (errno == ECONNABORTED || errno == EINTR || errno == EBADF || \
					errno == ECONNRESET || errno == EAGAIN)
				continue;
	}
		sys_error(n, "read error");
		re = write(cfd, buf, n);
		sys_error(re, "write error");
	}
	sleep(5);

	//close(fd);
	return;
}

void send_content(int cfd, char *filename)
{
	int re, n;
	int fd;
	char buf[BUFSIZ];

	fd = open(filename, O_RDWR);
	sys_error(fd, "open error");

	while ((n=read(fd, buf, sizeof(buf))))
	{
		if (n == -1)
		{
			if (errno == ECONNABORTED || errno == EINTR || errno == EBADF || \
					errno == ECONNRESET || errno == EAGAIN)
				continue;
		}
		sys_error(n, "read error");
		re = write(cfd, buf, n);
		if (errno == EAGAIN)
			continue;
		sys_error(re, "write error");
	}

	close(fd);
	return;
}
