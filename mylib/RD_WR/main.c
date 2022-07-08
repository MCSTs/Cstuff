#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


ssize_t writen(int , const void *, size_t );
ssize_t readn(int , void *, size_t );
int readLine(int fd, char *buf, int buflen);

int main(void)
{
	int fd = open("out", O_RDWR);
	if (fd == -1)
		perror("open");

	size_t num;
	char buf[BUFSIZ];
	int re;
	for (;;) {
		scanf("%ld", &num);
		re = readn(fd, buf, num);
		//re = writen(fd, buf, num);
		if (re)
			write(STDOUT_FILENO, buf, re);
		else {
			printf("EOF\n");
			break;
		}
	}
	return 0;
}
