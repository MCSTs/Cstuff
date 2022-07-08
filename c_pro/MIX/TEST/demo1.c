#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct su
{
	char name[15];
	char gender[10];
	int passwd;
}visitor[3] = {{"ross", "male", 111}, {"rachel", "female", 222}, {"joey", "male", 333}};

int main(void)
{
	FILE *fp = NULL;
	char filename[15];

	printf("filename: ");
	scanf("%s", filename);
	if( (fp=fopen(filename, "r"))==NULL)
	{
		printf("error: '%s' can not open\n", filename);
		exit(0);
	}

#if 0
	for(int i=0; i<3; i++)
	{
		fprintf(fp, "Name:\t%s\n", visitor[i].name);
		fprintf(fp, "Gender:\t%s\n", visitor[i].gender);
		fprintf(fp, "Passwd:\t%d\n\n", visitor[i].passwd);
	}
#endif

	char str[100];
	while((fgets(str, 100, fp))!=NULL)
		printf("%s", str);
	fclose(fp);


	FILE *test = NULL;
	test = fopen("qqq.txt", "r");
	if( (fgets(str, 100, test))==NULL)
		printf("NULL\n");
	fclose(test);
	return 0;
}

