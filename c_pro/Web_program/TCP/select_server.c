#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "pack.h"

#define D_PORT 9999

void sys_error(int num, char *ms)
{
	if (num == -1)
	{
		perror(ms);
		exit(1);
	}
}

int main(void)
{
	int re, n;	
	int	i, j;		 // circulating factors
	int sfd, cfd;	 // socket descriptor
	int opt = 1;	 // for function setsockopt
	int maxfd = 0;
	char buf[BUFSIZ];// read and write buffers
	fd_set set, mset; 

	struct sockaddr_in serv_addr, clit_addr;
	socklen_t clit_addr_len = sizeof(clit_addr);

	bzero(&serv_addr, sizeof(serv_addr));
	bzero(&clit_addr, sizeof(clit_addr));

	// initialize server address
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(D_PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	// create socket
	sfd = Socket(AF_INET, SOCK_STREAM, 0);

	// port reuse
	setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	
	// bind server address
	Bind(sfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));	

	// listen
	Listen(sfd, 128);


	maxfd = sfd;
	FD_ZERO(&mset);
	FD_SET(sfd, &mset);

	while (1)
	{
		set = mset;
		
		re = select(maxfd+1, &set, NULL, NULL, NULL);
		sys_error(re, "select error");

		if (FD_ISSET(sfd, &set))
		{
			cfd = Accept(sfd, (struct sockaddr *)&clit_addr, &clit_addr_len);

			// print connection message
			printf("Connect the client ip: %s, and port: %d\n", \
				  inet_ntop(AF_INET, &clit_addr.sin_addr, buf, sizeof(buf)), \
				  ntohs(clit_addr.sin_port));

			FD_SET(cfd, &mset);

			maxfd = maxfd > cfd ? maxfd : cfd;

			if (re == 1)
				continue;
		}

		for (i=sfd+1; i<=maxfd; i++)
		{
			if (FD_ISSET(i, &set))
			{
				n = read(i, buf, BUFSIZ);
				sys_error(n, "read error");
				if (n == 0)
				{
					close(i);
					FD_CLR(i, &mset);
					continue;
				}

				for(j=0; j<n; j++)
					buf[j] = toupper(buf[j]);
				re = write(i, buf, n);
				sys_error(re, "write error");
				sleep(2);
				//re = write(STDOUT_FILENO, buf, n);
				//sys_error(re, "write error");
			}
		}
	}

	close(sfd);
	return 0;
}

