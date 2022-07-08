#include "total.h"


void push(struct postfix** heap, char p, int val)
{
	struct postfix* new = (struct postfix*)\
						  malloc(sizeof(struct postfix));
	new->sign = p;
	new->val = val;
	new->next = NULL;
	if(*heap==NULL)
		(*heap) = new;
	else
	{
		new->next = (*heap);
		(*heap) = new;
	}
}

char pop(struct postfix** heap)
{
	if(*heap==NULL)	
		return '\0';
	struct postfix* tmp = (*heap);
	(*heap) = (*heap)->next;
	return tmp->sign;
}

int compare(char left, char right)
{
	if(left=='-' || left=='+')
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
	char *re = (char*)malloc(length+1);
	char *first = re;

	struct postfix* heap = NULL;
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
				push(&heap, mid, 0);
			}
			else if(mid==')')
			{
				char tmp;
				while( (tmp=pop(&heap))!='(' )
				{
					*re = tmp;
					re++;
				}
			}
			else
			{
					while(heap && compare(heap->sign, mid)==1)
					{
						*re = pop(&heap);
						re++;
					}
					push(&heap, mid, 0);
			}
		}
		sour++;
	}
	while(heap!=NULL)
	{
		*re = pop(&heap);
		re++;
	}
	*re = '\0';
	return first;
}

int calculate(char *exp)
{
	while( *exp != '\0')
	{
		if(*exp>=48 && *exp<=57)
		{
			char tmp[10]; 
			int count = 0;
			char *p = exp;
			while(*p>=48 && *p<=57)
			{
				tmp[count] = *p;
				p++;
				count++;
			}
			p++;
			exp = p;
			tmp[count] = '\0';
			continue;
		}
		else
		{

		}
	}
}









