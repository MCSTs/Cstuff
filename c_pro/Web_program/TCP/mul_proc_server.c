#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include "pack.h"

#define D_PORT 9000

void recycle_child(int signum)
{
	while(waitpid(0, NULL, WNOHANG) > 0);
	return;
}

int main(int argc, char **argv)
{
	char buf[BUFSIZ];
	int n, ret;
	int sfd, cfd;
	pid_t pid;

	struct sockaddr_in serv_addr, clit_addr;

	bzero(&serv_addr, sizeof(serv_addr));
	bzero(&clit_addr, sizeof(clit_addr));

	socklen_t clit_addr_len = sizeof(clit_addr);

	struct sigaction act;
	act.sa_handler = recycle_child;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	int re = sigaction(SIGCHLD, &act, NULL);
	if(re == -1)
	{
		perror("sigaction error");
		exit(1);
	}

	// initialize server address
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(D_PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	// create socket
	sfd = Socket(AF_INET, SOCK_STREAM, 0);

	// port reuse 
	int opt = 1;
	setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, (void *)&opt, sizeof(opt));

	// bind server address
	Bind(sfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	// listen setting
	Listen(sfd, 128);

	while(1)
	{
		// block for waiting client connection
		cfd = Accept(sfd, (struct sockaddr *)&clit_addr, &clit_addr_len);

		// print connection message
		printf("Connected from ip: %s and port: %d\n",\
				inet_ntop(AF_INET, &clit_addr.sin_addr, buf, sizeof(buf)), \
				ntohs(clit_addr.sin_port));

		pid = fork();
		if(pid == -1) {
			perror("fork error");
			exit(1);
		}
		else if(pid == 0) {
			close(sfd);
			break;
		}
		else if(pid > 0) {
			continue;
		}
	}

	//alarm(10);
	while(1)
	{
		n = read(cfd, buf, sizeof(buf));
		if(n == -1)
			perror("read error");

		for(ret=0; ret<n; ret++)
			buf[ret] = toupper(buf[ret]);

		ret = write(cfd, buf, n);
		if(ret == -1)
			perror("write error");
		sleep(2);
	}
	close(cfd);


	return 0;
}
