#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include "pack.h"

#define D_PORT 9000
#define F_MAX 5000
#define MAX_ENENT 1024

void sys_error(int num, char *ms)
{
	if (num == -1)
	{
		perror(ms);
		exit(1);
	}
}


int main(int argc, char **argv)
{
	int re, n, ep_re;
	int i, j;
	int sfd, cfd, efd, tmpfd;
	int opt = 1;
	char buf[BUFSIZ];

	struct sockaddr_in serv_addr, clit_addr;
	socklen_t clit_addr_len = sizeof(clit_addr);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(D_PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	struct epoll_event src, tar[F_MAX];

	sfd = Socket(AF_INET, SOCK_STREAM, 0);

	re = setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	sys_error(re, "setsockopt error");

	Bind(sfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	Listen(sfd, 128);

	efd = epoll_create(F_MAX);
	sys_error(efd, "epoll_create error");

	src.events = EPOLLIN;
	src.data.fd = sfd;
	re = epoll_ctl(efd, EPOLL_CTL_ADD, sfd, &src);
	sys_error(re, "epoll_ctl error");

	while (1)
	{
		ep_re = epoll_wait(efd, tar, F_MAX, -1);
		sys_error(ep_re, "epoll_wait error");

		for (i=0; i<ep_re; i++)
		{
			if (tar[i].events != EPOLLIN)
				continue;

			if (tar[i].data.fd == sfd)
			{
				cfd = Accept(sfd, (struct sockaddr *)&clit_addr, &clit_addr_len);
				//printf("Connect from ip: %s, port: %d\n", \
						inet_ntop(AF_INET, &clit_addr, buf, sizeof(buf)), \
						ntohs(clit_addr.sin_port));

				src.events = EPOLLIN;
				src.data.fd = cfd;
				re = epoll_ctl(efd, EPOLL_CTL_ADD, cfd, &src);
				sys_error(re, "epoll_ctl error");
			}
			else
			{
				tmpfd = tar[i].data.fd;
				n = read(tmpfd, buf, sizeof(buf));
				sys_error(n, "read error");
				if(n == 0)
				{
					re = epoll_ctl(efd, EPOLL_CTL_DEL, tmpfd, NULL);
					sys_error(re, "epoll_ctl error");
					close(tmpfd);
					continue;
				}
				for(j=0; j<n; j++)
					buf[j] = toupper(buf[j]);
				re = write(tmpfd, buf, n);
				sys_error(re, "write error");
			}
		}
	}
	close(sfd);

	return 0;
}
