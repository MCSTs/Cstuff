#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/mman.h>
//#include <sys/stat.h>

#define F_NAME "mymap"
#define F_SIZE 100

void sys_error(char *ms)
{
	perror(ms);
	exit(1);
}

int main(int argc, char **argv)
{
	int fd = open(F_NAME, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(fd == -1)
		sys_error("open error");

	if(ftruncate(fd, F_SIZE) == -1)
		sys_error("ftruncate error");
	int f_size = lseek(fd, 0, SEEK_END); // get file size

	char *pmap = mmap(NULL, f_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0); // creat mmap of file
	if(pmap == MAP_FAILED)
		sys_error("mmap error");
	close(fd); 


	pid_t pid  = fork();
	if(pid == -1)
		sys_error("fork error");
	else if(pid > 0)
	{
		printf("I'm parent process, I'm waitting child process to write\n");
		wait(NULL);
		putchar('\n');
		printf("the mmap context is: %s\n", pmap);
		munmap(pmap, f_size);
	}
	else if(pid == 0)
	{
		printf("I'm child process.");
		printf("I'm writing something to the map zone: ");
		char p[100];
		scanf("%s", p);
		strcpy(pmap, p);
	}

	return 0;
}
