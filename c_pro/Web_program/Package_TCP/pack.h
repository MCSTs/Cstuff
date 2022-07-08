#ifndef __PACK_H__
#define __PACK_H__

int Socket(int domain, int type, int protocol);

int Bind(int sockfd, const struct sockaddr *addr,\
		socklen_t addrlen);

int Listen(int sockfd, int backlog);
 
int Accept(int sockfd, struct sockaddr *addr, \
		socklen_t *addrlen);


#endif
