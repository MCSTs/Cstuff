#include "total.h"

void del_connect(int cfd, int efd)
{
	int re;
	re = epoll_ctl(efd, EPOLL_CTL_DEL, cfd, NULL);
	sys_error(re, "epoll_ctl error");

	close(cfd);
	return;
}

int get_line(int cfd, char *buf, int size)
{
	int i = 0;
	char c = '\0';
	int n;
	while ((i < size-1) && (c != '\n')) {
		n = recv(cfd, &c, 1, 0);
		if (n > 0) {
			if (c == '\r') {
				n = recv(cfd, &c, 1, MSG_PEEK);
				if ((n >0) && (c == '\n'))
					recv(cfd, &c, 1, 0);
				else
					c = '\n';
			}
			buf[i] = c;
			i++;
		}
		else
			c = '\n';
	}
	buf[i] = '\n';
	if (n == -1)
		i = n;
	return i;
}


void do_read(int cfd, int efd)
{
	int re;
	int len = 0;
	char line[1024] = {0};
	char method[16], path[256], protocol[16];
	char *filename = NULL;
	char filetype[256] = "Content-Type: ";
	struct stat sa;

	len = get_line(cfd, line, sizeof(line));
	if (len == 0) {
		printf("client disconneted\n");
		del_connect(cfd, efd);
	}
	//fputs(line, stdout);
	else {
		sscanf(line, "%[^ ] %[^ ] %[^ ]", method, path, protocol);
		//sscanf(line, "%s %s %s", method, path, protocol);
	}

	printf("method=%s, path=%s, protocol=%s\n", method, path, protocol);

	filename = path+1;	
	//printf("%s", filename);
	
	memset(&sa, 0, sizeof(sa));
	re = stat(filename, &sa);
	if (re == -1) {
		printf("client request not found\n");
		send_404err(cfd);
		del_connect(cfd, efd);
	}
	else {
	//sleep(5);

	strcat(filetype, f_type(filename));
	send_respond(cfd, 200, "OK", filetype);
	send_content(cfd, filename);
	}

	return;
}
