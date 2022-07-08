#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
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
	struct sockaddr_in srv_addr;

	bzero(&srv_addr, sizeof(srv_addr));
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = htons(D_PORT);
	inet_pton(AF_INET, "127.0.0.1", (void *)&srv_addr.sin_addr.s_addr);

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	sys_error(sockfd, "socket error");

	while (1)
	{
		fgets(buf, sizeof(buf), stdin);
		re = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
		sys_error(re, "sendto error");

		re = recvfrom(sockfd, buf, sizeof(buf), 0, NULL, 0);
		sys_error(re, "recvform error");

		write(STDOUT_FILENO, buf, re);
	}

	
	return 0;
}
