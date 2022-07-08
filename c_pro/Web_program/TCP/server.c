#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define D_PORT 8898

#ifndef BUFSIZ
#define BUFSIZE 8192
#endif

void sys_error(char *ms)
{
	perror(ms);
	exit(1);
}

int main(int argc, char **argv)
{
	//pid_t pid = fork();
	//if(pid == 0)
	{
//		setsid();

		int re, i;
		int sfd, cfd;

		struct sockaddr_in addr, acp_addr;
		socklen_t acp_addr_len;
		char buf[BUFSIZ];

		// initialiaze the server addr
		addr.sin_family = AF_INET;
		addr.sin_port = htons(D_PORT);
		addr.sin_addr.s_addr = INADDR_ANY;

		sfd = socket(AF_INET, SOCK_STREAM, 0);
		if(sfd == -1)
			sys_error("socket error");

		// port reuse
		int opt = 1;					// permit reuse
		setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, (void *)&opt, sizeof(opt));

		// bind the server address structure
		re = bind(sfd, (struct sockaddr *)&addr, sizeof(addr));
		if(re == -1)
			sys_error("bind error");

		// set the maximum number of conections
		re = listen(sfd, 128);
		if(re == -1)
			sys_error("listen error");

		// block waiting for a client connection
		acp_addr_len = sizeof(acp_addr);
		cfd = accept(sfd, (struct sockaddr *)&acp_addr, &acp_addr_len);
		if(cfd == -1)
			sys_error("accept error");

		// print client address structure
		printf("conneted from client ip: %s, port: %d\n", \
				inet_ntop(AF_INET, &acp_addr.sin_addr, buf, sizeof(buf)),\
				ntohs(acp_addr.sin_port));

		while(1)
		{
			re = read(cfd, buf, BUFSIZ);	
			if(re == -1)
				sys_error("read error");
			//write(STDOUT_FILENO, buf, re);

			for(i=0; i<re; i++)
				buf[i] = toupper(buf[i]);
			write(cfd, buf, re);
		}

		close(sfd);
		close(cfd);
	}
	return 0;
}
