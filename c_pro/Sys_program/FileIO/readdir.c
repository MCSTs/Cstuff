#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char **argv)
{
	DIR *dirp;
	//printf("%s\n", argv[1]);

	if(argc==1)
	{
		printf("error: missing parameter argv[1]\n");
		exit(1);
	}

	dirp = opendir(argv[1]);
	if(dirp == NULL)
	{
		perror("opendir error");
		exit(1);
	}

	struct dirent *dp; 
	int count=0;
	while( (dp=readdir(dirp)) != NULL)
	{
		if( (dp->d_name)[0] == '.' )
			continue;
		printf("%s\t", dp->d_name);
		count++;
		if(count==4)
		{
			putchar('\n');
			count=0;
		}
	}
	putchar('\n');

	closedir(dirp);
	return 0;
}
