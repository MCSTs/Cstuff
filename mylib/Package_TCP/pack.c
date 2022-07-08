#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <errno.h>

static void sys_error(char *ms)
{
	perror(ms);
	exit(1);
}	

int Socket(int domain, int type, int protocol)
{
	int re = socket(domain, type, protocol);
	if(re == -1)
		sys_error("socket error");

	return re;
}


int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
	int re = bind(sockfd, addr, addrlen);
	if(re == -1)
		sys_error("bind error");

	return re;
}


int Listen(int sockfd, int backlog)
{
	int re = listen(sockfd, backlog);
	if(re == -1)
		sys_error("listen error");

	return re;
	
}


int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
	int re;

	while((re=accept(sockfd, addr, addrlen)) < 0)
	{
		
		if(errno == ECONNABORTED || errno == EINTR)
			continue;
		else
		{
			perror("accept error");
			exit(1);
		}
	}

	return re;
}
