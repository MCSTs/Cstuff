#include <stdio.h>
#include <errno.h>

struct 
{
	char name[30];
	int age;
}guy[3] = {{"Rachel", 1}, {"Ross", 2}, {"Joey", 3}}, *gp;

int main(void)
{
	FILE *f1;
	
	gp = guy;

#if 0
	guy[0].name = "Rachel";
	guy[0].age = 25;
	printf("%s\n", guy[0].name);
	guy[1].name = "Ross";
	guy[1].age = 30;

	guy[2].name = "Joey";
	guy[2].age = 28;
#endif

	f1 = fopen("1.txt", "r+");


	if(f1 == NULL)
	{
		printf("erro: %d\n", errno);
		return 0;
	}
	for(int i=0; i<3; i++)
		fprintf(f1, "No.%d-> name:%s\tage:%d\n",i+1, guy[i].name, guy[i].age);		

	fclose(f1);
	return 0;
}
