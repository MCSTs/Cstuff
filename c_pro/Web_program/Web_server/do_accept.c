#include "total.h"


int do_accept(int sfd, int efd)
{
	int cfd;
	int re;
	int flag = 0;
	char client_ip[64] = {0};
	struct epoll_event ev;
	struct sockaddr_in clt_addr;
	socklen_t clt_addr_len = sizeof(clt_addr);

	cfd = accept(sfd, (struct sockaddr *)&clt_addr, &clt_addr_len);
	sys_error(cfd, "accept error");

	printf("New client IP: %s, Port: %d, cfd=%d\n", \
			inet_ntop(AF_INET, &clt_addr.sin_addr, client_ip,sizeof(client_ip)),\
			ntohs(clt_addr.sin_port), cfd);

	flag = fcntl(cfd, F_GETFL);
	flag |= O_NONBLOCK;
	fcntl(cfd, F_SETFL, flag);

	// mounted node
	ev.data.fd = cfd;

	// ET NONBLOCK
	ev.events = EPOLLIN | EPOLLET;
	
	re = epoll_ctl(efd, EPOLL_CTL_ADD, cfd, &ev);
	sys_error(re, "epoll_ctl error");
	return cfd;
}
