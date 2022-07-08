#include "total.h"

#define MAXCLT 1024


void epoll_run(int port)
{
	int efd, sfd;
	int re, ep_re;
	int i;
	char ip[128];
	struct epoll_event ep_src, ep_tar[MAXCLT]; 

	// create epoll tree
	efd = epoll_create(MAXCLT);
	sys_error(efd, "epoll_create error");

	// initialize sfd and mounted sfd node
	sfd = init_listen_fd(port, efd);

	while (1)
	{
		ep_re = epoll_wait(efd, ep_tar, MAXCLT, -1);
		sys_error(ep_re, "epoll_wait error");

		for (i=0; i<ep_re; i++)
		{
			struct epoll_event *pev = &ep_tar[i];

			if (!(pev->events & EPOLLIN))
				continue;

			if (pev->data.fd == sfd) 
				do_accept(sfd, efd);
			else 
				do_read(pev->data.fd, efd);
		}
	}

	return;
}
