#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

typedef struct stud{
	int id;
	char name[256];
	int age;
} stu;

int main(int argc, char **argv)
{
	//int fd = open("/dev/zero", O_RDWR);

	int fd = open("testfile", O_RDWR|O_CREAT|O_TRUNC, 0644);
	ftruncate(fd, 1024);	

	if(fd == -1)
	{
		perror("open error");
		exit(1);
	}

	stu stuu = {1, "ross", 20};
	stu *p = (stu *)mmap(NULL, 1024, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);	
	if(p == MAP_FAILED)
	{
		perror("mmap error");
		exit(1);
	}
	close(fd);

	while(1)
	{
		memcpy(p, &stuu, sizeof(stu));
		sleep(2);
	}
	munmap(p, sizeof(stu));

	return 0;
}
