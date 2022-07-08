#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int cash = 100;

void play(int bet)
{
	char *p = (char*)malloc(3*sizeof(char));
	p[0] = 'J';
	p[1] = 'Q';
	p[2] = 'K';

	srand(time(NULL));
	int i;
	printf("Shuffling...\n");
	sleep(1);
	for(i=0; i<5; i++)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		int tmp = p[x];
		p[x] = p[y];
		p[y] = tmp;
	}
	
	printf("The shuffle is over\n");
	printf("You need choose the 'Queen' location(1, 2 and 3)\n");
	printf("Confirm your choose: ");
	int guess;
	scanf("%d", &guess);
	if(p[guess]=='Q')
	{
		printf("You win!\n");
		cash += 3*bet;
		printf("Your cash is %d now\n", cash);
	}
	else
	{
		printf("You lose\n");
		cash -= bet;
		printf("Your cash is %d now\n", cash);
	}
	free(p);

	putchar('\n');
}
int main(void)
{
	system("clear");
	printf("Your start with 100$\n");
	printf("In this game you need to select the position of the 'Queen' card\n");
	printf("At each start, the cards are shuffled, and the 'Queen' card may appear in (1, 2 or 3) position\n");
	putchar('\n');
	while(1)
	{
		if(cash <= 0)
		{
			printf("Game over!\n");
			break;
		}
		printf("**************************************************\n");
		int bet;
		printf("Confirm your bet: ");
		scanf("%d", &bet);
		if(bet<=0)
			break;
		play(bet);
		printf("**************************************************\n");
		putchar('\n');
	}

	return 0;
}
