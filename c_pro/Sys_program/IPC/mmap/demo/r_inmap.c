#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

typedef struct stud{
	int id;
	char name[256];
	int age;
} stu;

int main(void)
{
	//int fd = open("/dev/zero", O_RDWR);

	int fd = open("testfile", O_RDONLY);
	ftruncate(fd, 1024);

	if(fd == -1)
	{
		perror("open error");
		exit(1);
	}

	stu *p = (stu *)mmap(NULL, 1024, PROT_READ,MAP_SHARED, fd, 0);
	if(p == MAP_FAILED)
	{
		perror("mmap error");
		exit(1);
	}
	close(fd);

	while(1)
	{
		printf("id=%d name=%s age=%d\n", p->id, p->name, p->age);
		sleep(1);
	}
	return 0;
}
