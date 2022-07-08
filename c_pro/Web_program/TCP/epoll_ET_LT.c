#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
#include <sys/epoll.h>

#define BUF 10

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
	int pfd[2];
	int re;
	int i, n;
	char buf[BUF], ch = 'a';
	pid_t pid;

	re = pipe(pfd); 
	sys_error(re, "pipe error");

	pid = fork();
	sys_error(pid, "fork error");

	// child process write 
	if (pid == 0)
	{
		int count=1;
		close(pfd[0]);
		while(1)
		{
			for (i=0; i<BUF/2; i++)
				buf[i] = ch;
			buf[i-1] = '\n';
			//re = write(pfd[1], buf, BUF/2);
			//sys_error(re, "write error");

			ch++;

			for (; i<BUF; i++)
				buf[i] = ch;
			buf[i-1] = '\n';
			re = write(pfd[1], buf, BUF);
			sys_error(re, "write error");
			ch++;

			printf("write the no.%d: \n", count);
			count++;
			re = write(STDOUT_FILENO, buf, BUF);
			sys_error(re, "write error");
			printf("sleep 5 sec...\n\n");
			sleep(5);

			//lseek(pfd[1], 0, SEEK_SET);
		}
	}
	else
	{
		int count = 1;
		close(pfd[1]);
		struct epoll_event event, ep[1];

		//event.events = EPOLLIN | EPOLLET;	  // ET 
		event.events = EPOLLIN;				  // LT
		event.data.fd = pfd[0];

		int efd = epoll_create(1);
		sys_error(efd, "epoll_create error");

		epoll_ctl(efd, EPOLL_CTL_ADD, pfd[0], &event);
		while(1)
		{
			re = epoll_wait(efd, ep, 1, -1);
			sys_error(re, "epoll_wait error");

			n = read(pfd[0], buf, BUF/2);
			sys_error(n, "read error");

			printf("read the no.%d: \n", count);
			count++;
			re = write(STDOUT_FILENO, buf, n);
			sys_error(re, "write error");

			//lseek(pfd[0], 0, SEEK_SET);
		}
	}

	return 0;
}
