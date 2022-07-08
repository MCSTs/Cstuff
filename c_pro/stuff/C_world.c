#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	char a[100];
	printf("请输入CTRL + D 进入C世界\n");
	while(scanf("%s", a)!=EOF)
	{
		printf("请输入CTRL + D 进入C世界\n");
	}
	system("cmatrix");
}
