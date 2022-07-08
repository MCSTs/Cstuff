#include"total.h"
#include <mcheck.h>


int main(int argc, char **argv)
{

    mtrace();                   /* heap memery check */

    Node_t *head = create();
    print_ll(head);
    
    head = reverse(head);
    print_ll(head);

    myfree(head, NULL);


    return 0;
}
