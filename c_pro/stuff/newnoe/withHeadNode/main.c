#include "total.h"
#include <mcheck.h>

int main(void)
{

    mtrace();

    headN_t *headNode = create();
    /*headN_t *headNode = create_incream();*/


#if 0 // bothway list
    headN_t *bothhead = create_bothwayList();
    print_tt(bothhead);
    print_back(bothhead);

    printf("enter a node to del: ");
    int val = 0;
    scanf("%d", &val);
    delN_inBothlist(bothhead, val);
    print_tt(bothhead);
#endif 


#if 1 // delete 

    del_in_Minstack(headNode);

    print_minstack(headNode);
    
    /*del_Min(headNode);*/
    /*print_tt(headNode);*/
    /*int n;*/
    /*printf("enter the number to delete: ");*/
    /*while(scanf("%d", &n))*/
    /*{*/
        /*delete_n(headNode, n);*/
        /*printf("Now the linked list is: \n");*/
        /*print_tt(headNode);*/
        /*putchar('\n');*/
        /*if (headNode->start == NULL)*/
            /*break;*/
        /*printf("enter the number to delete: ");*/
    /*}*/



#endif 


    return 0;
}
