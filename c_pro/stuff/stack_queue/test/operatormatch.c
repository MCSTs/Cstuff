#include "../stack.h"

#define MAXLEN 20

bool match_op(char ch1, char ch2)
{
    switch(ch1)
    {
        case '(': 
            if (ch2 != ')')
                return false;
            break;
        case '{': 
            if (ch2 != '}')
                return false;
            break;
        case '[': 
            if (ch2 != ']')
                return false;
            break;
        default :
            return false;
    }
    return true;
}

bool is_leftOp(char ch)
{
    switch(ch)
    {
        case '(':
        case '{':
        case '[':
            return true;
        default:
            break;
    }
    return false;
}


int main(void)
{
    char ar[MAXLEN];
    printf("enter the operasation: ");
    scanf("%s", ar);
    char *p = ar;
    char ch1, ch2;

    HeadNode *headNode = init_stack();
    node_t *tmp = NULL; 
    while (*p != '\0')
    {
        ch1 = *p;
        if (is_leftOp(ch1))
            push_ch(headNode, ch1);
        else
        {
            if (isempty_stack(headNode))
            {
                printf("empty...");
                printf("It's not leagle\n");
                return 0;
            }
            tmp = poll(headNode);
            ch2 = tmp->ch;
            if(!match_op(ch2, ch1))
            {
                printf("not matching...");
                printf("It's not leagle\n");
                return 0;
            }
        }
        p++;
    }
    if (isempty_stack(headNode))
        printf("It's leagle\n");
    else
        printf("It's not leagle\n");
    return 0;
}
