#include "total.h"

int SymbolMatch(char *str)
{
	char sign;

	while( *str!='\0' )
	{
		sign = *str;
		if(sign=='{' || sign=='[' || sign=='(') {
			pushchar(sign);
		}
		else{
			switch(sign){
				case '}':
					{
						if(popchar()!='{')
							return 0;
					}break;
				case ']':
					{
						if(popchar()!='[')
							return 0;
					}break;
				case ')':
					{
						if(popchar()!='(')
							return 0;
					}break;
			}
		}
		str++;
	}
	return 1;
}
