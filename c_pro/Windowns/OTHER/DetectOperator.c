#include <stdio.h>

static char stack[10000];
static int heap = -1;

void push(char c)
{
	stack[++heap] = c;
}

char top()
{
	if(heap==-1)
		return ' ';
	return stack[heap];	
}

void pop()
{
	if(heap==-1)
		return;
	heap--;
}

int DetectOperator(char *exp)
{
	char tmp;
	while(*exp != '\0')
	{
		tmp = *exp;
		if(tmp=='(' || tmp=='{' || tmp=='[')
			push(tmp);
		else
		{
			switch(tmp)
			{
				case '}':
					{
						char temp = top();
						if(temp == '{')
							pop();
						else
							return 0;
					}
					break;
				case ']':
					{
						char temp = top();
						if(temp == '[')
							pop();
						else
							return 0;
					}
					break;
				case ')':
					{
						char temp = top();
						if(temp == '(')
							pop();
						else
							return 0;
					}
					break;
			}
		}
		exp++;
	}
	if(top()!=' ')
		return 0;
	return 1;
}


int main()
{
	char exp[20];
	scanf("%s", exp);
	int re = DetectOperator(exp);
	if(re)
		printf("true\n");
	else
		printf("false\n");

	return 0;
}
