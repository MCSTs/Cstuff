#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int readLine(int fd, char *buf, int buflen)
{
	if (buflen <=0 || buf == NULL) {
		errno = EINVAL;
		return -1;
	}

	char ch;
	char *p = buf;
	int readnum = 0;
	ssize_t re = 0;

	for (;;) {
		re = read(fd, &ch, 1);
		if (re == -1) {
			if (errno == EINTR)
				continue;
			else 
				return -1;
		} 

		if (re == 0) {
			if (readnum == 0)
				break;
			else 
				return 0;
		}
		else {
			if (readnum < buflen-1) {
				*p++ = ch;
				readnum++;
			}
		}
		if (ch == '\n')
			break;

	}
	*p = '\0';

	return readnum;
}

