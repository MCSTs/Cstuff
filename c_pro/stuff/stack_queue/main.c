#include "queue.h"
#include "stack.h"

#define MAX_L 10

int main(void)
{

#if 0 // queue_ar
    Queue *queP = init_queue(MAX_L);
    char do_que;
    int num;
    while (true)
    {
        printf("enter the operator('e' or 'd'):");
        scanf("%c", &do_que);
        if (do_que == 'q')
            break;
        switch(do_que)
        {
            case 'e': 
                scanf("%d", &num);
                Enqueue(queP, num);
                break;
            case 'd': 
                      Dequeue(queP); 
                      break;
            default : break;
        }

        print_que(queP);
        while (getchar()!='\n');
    }

#endif

#if 1 // queue_li
    Queue_li *queP_li = init_queue_li();
    char do_que;
    int num;
    while (true)
    {
        printf("enter the operator('e' or 'd'):");
        scanf("%c", &do_que);
        if (do_que == 'q')
            break;
        switch(do_que)
        {
            case 'e': 
                scanf("%d", &num);
                Enqueue_li(queP_li, num);
                break;
            case 'd': 
                      Dequeue_li(queP_li); 
                      break;
            default : break;
        }

        print_que_li(queP_li);
        while (getchar()!='\n');
    }

#endif


#if 0 // stack

    HeadNode *headNode = init_stack();
    int val;
    printf("enter a val to push the stack: ");
    while (scanf("%d", &val))
    {
        push(headNode, val);
        printf("enter again: ");
        print_stack(headNode);
        while (getchar()!='\n');
    }

#endif

    return 0;
}
