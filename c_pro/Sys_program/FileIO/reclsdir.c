#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>

int isdir(const char *path)
{
	struct stat ms;
	stat(path, &ms);
	if(S_ISDIR(ms.st_mode))
		return 1;
	else
		return 0;
}

void recOrderdir(char *path)
{
	DIR *pdir;
	pdir = opendir(path);
	struct dirent *pp;
	char newpath[1000];

	while( (pp=readdir(pdir))!=NULL )
	{
		if((pp->d_name)[0]=='.')
			continue;
		printf("%-15s", pp->d_name);
		sprintf(newpath, "%s/%s", path, pp->d_name);

		if(isdir(newpath))
		{
			putchar('\n');
			recOrderdir(newpath);
		}
	}

	closedir(pdir);
	putchar('\n');
}

int main(int argc, char **argv)
{
	if(argc==1)
		argv[1] = ".";
	else if(isdir(argv[1])==0)
	{
		printf("%s\n", argv[1]);
		return 0;
	}

	recOrderdir(argv[1]);

	return 0;
}
