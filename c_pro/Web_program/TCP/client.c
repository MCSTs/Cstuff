#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define D_PORT 8898 
#define SRC_IP "192.168.59.129"

static void sys_error(int num, char *ms)
{
	if(num == -1)
	{
		perror(ms);
		exit(1);
	}
	return;
}


int main(void)
{
	int cfd, re;
	char buf[BUFSIZ];

	struct sockaddr_in serv_addr;
	socklen_t serv_addr_len = sizeof(serv_addr);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(D_PORT);
	re = inet_pton(AF_INET, SRC_IP, &serv_addr.sin_addr.s_addr);
	sys_error(re, "inet_pton error");
	if(re == 0)
	{
		printf("source ip is invalid\n");
		exit(0);
	}

	cfd = socket(AF_INET, SOCK_STREAM, 0);
	sys_error(cfd, "socket error");

	re = connect(cfd, (struct sockaddr *)&serv_addr, serv_addr_len);
	sys_error(re, "connect error");


	int n;
	char ms[100];
	while(1)
	{
		printf("enter the contex: ");
		scanf("%s", ms);
		ms[strlen(ms)] = '\n';
		//printf("%s", ms);
		//printf("%d\n", ms[strlen(ms)]);

		re = write(cfd, ms, strlen(ms));
		sys_error(re, "write error");

		n = read(cfd, buf, sizeof(buf));
		write(STDOUT_FILENO, buf, n);
		while(getchar()!='\n');
	}

	close(cfd);

	return 0;
}

