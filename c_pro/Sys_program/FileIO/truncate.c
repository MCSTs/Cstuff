

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	char *f1 = "./tx1.txt";
	int fd = open(f1, O_RDWR);	
	lseek(fd, 0, SEEK_END);
	int ret = truncate(f1, 1024);
	printf("ret = %d\n", ret);
	return 0;
}
