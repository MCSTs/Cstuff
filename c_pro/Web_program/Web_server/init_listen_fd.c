#include "total.h"

int init_listen_fd(int port, int efd)
{
	int sfd;
	int re;
	int opt = 1;
	struct sockaddr_in srv_addr;
	struct epoll_event ep_src;

	// initialize address structure
	memset(&srv_addr, 0, sizeof(srv_addr));
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = htons(port);
	srv_addr.sin_addr.s_addr = INADDR_ANY;


	sfd = socket(AF_INET, SOCK_STREAM, 0);
	sys_error(sfd, "socket error");

	re = setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	sys_error(re, "setsockopt error");

	re = bind(sfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
	sys_error(re, "bind error");

	re = listen(sfd, 128);
	sys_error(re, "listen error");


	// add into the efd tree
	ep_src.events = EPOLLIN;
	ep_src.data.fd = sfd;
	re = epoll_ctl(efd, EPOLL_CTL_ADD, sfd, &ep_src);
	sys_error(re, "epoll_ctl error");

	return sfd;
}
