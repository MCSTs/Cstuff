#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct postfix{
	char sign;
	int val;
	struct postfix* next;
};

static struct postfix* heap = NULL;

void push(char p, int val)
{
	struct postfix* new = (struct postfix*)\
						  malloc(sizeof(struct postfix));
	new->sign = p;
	new->val = val;
	new->next = NULL;
	if(heap==NULL)
		(heap) = new;
	else
	{
		new->next = (heap);
		(heap) = new;
	}
}

void pop()
{
	if(heap==NULL)	
		return;
	struct postfix* tmp = heap;
	heap = heap->next;
	free(tmp);
}

int compare(char left, char right)
{

	if(left=='(')
		return 2;
	else if(left=='-' || left=='+')
	{
		if(right=='-' || right=='+')
			return 1;
		else if(right=='*' || right=='/' || right=='%')
			return 2;
	}
	else
	{
		return 1;
	}
}

char *InfixToPostfix(char *sour)
{
	int length = strlen(sour);	
	//printf("len: %d\n", length);
	char *re = (char*)malloc(2*length);
	char *first = re;

	char mid;
	while(1)
	{
		mid = *sour;
		if(mid=='\0')
			break;
		if(mid>=48 && mid<=57)
		{
			char *tmp = sour;
			while(*tmp>=48 && *tmp<=57)
			{
				*re = *tmp;
				re++;
				tmp++;
			}
			*re = ' ';
			re++;
			sour = tmp;
			continue;
		}
		else if(mid=='+'||mid=='-'||mid=='*'||mid=='/'||mid=='%'\
				||mid=='('||mid==')')
		{
			if(heap==NULL || mid=='(' || heap->sign=='('\
					|| compare(heap->sign, mid)==2)
			{
				push(mid, 0);
			}
			else if(mid==')')
			{
				char tmp;
				while( (tmp=heap->sign)!='(' )
				{
					pop();
					*re = tmp;
					re++;
				}
				pop();
			}
			else
			{
					while(heap && compare(heap->sign, mid)==1)
					{
						*re = heap->sign;
						pop();
						re++;
					}
					push(mid, 0);
			}
		}
		sour++;
	}
	while(heap!=NULL)
	{
		*re = heap->sign;
		pop();
		re++;
	}
	*re = '\0';
	return first;
}

int calculate(char *s)
{
	while( *s != '\0')
	{
		if(*s>=48 && *s<=57)
		{
			char tmp[10]; 
			int count = 0;
			char *p = s;
			while(*p>=48 && *p<=57)
			{
				tmp[count] = *p;
				p++;
				count++;
			}
			p++;
			s = p;
			tmp[count] = '\0';
			push('0', atoi(tmp));

			//printf("%d\n", atoi(tmp));
			continue;
		}
		else
		{
			int re1;
			int re2;
			//printf("%c\n", *s);
			switch(*s)
			{
				case '+':
					{
						re2 = heap->val;
						pop();
						re1 = heap->val;
						pop();
						push('0', re1+re2);
					}break;
				case '-':
					{
						re2 = heap->val;
						pop();
						re1 = heap->val;
						pop();
						push('0', re1-re2);
					}break;
				case '*':
					{
						re2 = heap->val;
						pop();
						re1 = heap->val;
						pop();
						push('0', re1*re2);
					}break;
				case '/':
					{
						re2 = heap->val;
						pop();
						re1 = heap->val;
						pop();
						push('0', re1/re2);
					}break;
				case '%':
					{
						re2 = heap->val;
						pop();
						re1 = heap->val;
						pop();
						push('0', re1%re2);
					}break;
			}
			s++;
		}
	}
	int result = heap->val;
	free(heap);
	return result;
}


int main(void)
{

	char p[20];
	scanf("%s", p);
	char *re = InfixToPostfix(p);
	printf("%s", re);
	putchar('\n');
	if(heap==NULL)
		printf("heap==NULL\n");

	int result = calculate(re);
	printf("Result = %d\n", result);
	exit(0);
	return 0;
}
