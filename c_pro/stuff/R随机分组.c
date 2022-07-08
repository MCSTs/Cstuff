#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	int count;	
	int re[6]={7,7,7,7,7,7};
	char friends[6][10] =  {"Ross", "Rachel", "Chandler", "Monica", "Phoebe", "Joey"};
	char group[6][10];

	srand((unsigned int)time(NULL)*10);

	for(count=0; count<6; count++)
	{
		while(1)
		{
			if(re[0]==7)
			{
				re[0] = rand() % 6;
				printf("%d ", re[0]);
				break;
			}
			int mid = rand() % 6;
			int j;
			for(j=0; j<count; j++)
			{
				if(mid==re[j])
					break;
			}
			if(j==count)
			{
				re[count] = mid;
				printf("%d ", re[count]);
				break;
			}
		}
		strcpy(group[count], friends[re[count]]);
	}

	for(int i=0; i<6; i+=2)
	{
		if(i<2)
			printf("\nGroup1: ");
		else if(i<4)
			printf("Group2: ");
		else
			printf("Group3: ");
		for(count=i; count<i+2; count++)
		{
			printf("%-11s", group[count]);
		}
		putchar('\n');
	}
	return 0;
}
