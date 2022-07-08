#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define D_PORT 9000

void sys_error(int num, char *ms)
{
	if (num == -1)
	{
		perror(ms);
		exit(1);
	}
	return;
}

int main(void)
{
	int re, n;
	int sockfd;
	char buf[BUFSIZ];
	char ipbuf[100];
	struct sockaddr_in srv_addr, clt_addr;
	socklen_t clt_addr_len = sizeof(clt_addr);

	bzero(&srv_addr, sizeof(srv_addr));
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = htons(D_PORT);
	srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	sys_error(sockfd, "socket error");

	re = bind(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
	sys_error(re, "bind error");

	while(1)
	{
		re = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&clt_addr, &clt_addr_len);
		sys_error(re, "recvfrom error");

		printf("recvfrom client ip: %s, port: %d\n",\
				inet_ntop(AF_INET, &clt_addr.sin_addr, ipbuf, 100),\
				ntohs(clt_addr.sin_port));

		for(n=0; n<re; n++)
			buf[n] = toupper(buf[n]);
		re = sendto(sockfd, buf, re, 0, (struct sockaddr *)&clt_addr, clt_addr_len);
		sys_error(re, "sendto error");
	}


	return 0;
}
