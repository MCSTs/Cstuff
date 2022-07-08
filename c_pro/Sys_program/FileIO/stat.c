#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	struct stat tt;
	int re = stat(argv[1], &tt);
	if(re == -1) {
		perror("stat error");
		exit(1);
	}
	printf("%s inode: %ld\n", argv[1], tt.st_ino);
	printf("%s size: %ld\n", argv[1], tt.st_size);
		
	return 0;
}
