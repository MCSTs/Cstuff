#include "total.h"
#include <mcheck.h>

int main(void)
{

    mtrace();                       /* memery check */

    Node_t *head = create_ll();
    printf("source list: ");
    print_ll(head);

    

#if 0 // flip list

    //head = flip_whole(head);
    //print_ll(head);

    //int n, m;
    //printf("enter n2m: ");
    //scanf("%d%d", &n, &m);
    //head = flip_n2m(head, n, m);

    /*int n;*/
    /*printf("enter group n: ");*/
    /*scanf("%d", &n);*/
    /*head = flip_group_n(head, n);*/

    Node_t *head2 = create_ll();
    Node_t *new = add_TwoList(head, head2);

    print_ll(new);
    free_ll(new, NULL);
    free_ll(head2, NULL);

#endif 


#if 0 // loop list

    isloop(head, true);
    puts("now link a node to generate the loop list");
    printf("enter the index of node: ");

    /*insert loop node*/
    int num;
    scanf("%d", &num);
    linkLoop(head, num);
    isloop(head, true);

    /* find  loop node */
    Node_t *loop_node = findNode_loop(head);
    printf("loop node: %d\n", loop_node->data);

#endif


#if 0 // merge

    Node_t *head2 = create_ll();
    //head = merge_order_R(head, head2);
    //head = merge_order(head, head2);

    Node_t *head3 = create_ll();
    Node_t *head4 = create_ll();
    Node_t *head5 = create_ll();

    Node_t *list[5] = {head, head2,head3, head4, head5};

    head = mer_k(list, 0, 4);

    print_ll(head);
    
#endif


#if 0 // delete

    //int n;
    //scanf("%d", &n);

    //Node_t *cur = back_n(head, n);
    //print_ll(cur);

    //head = delete_back_n(head, n);
    //head = del_order_otherRep(head);
    head = del_order_allRep(head);
    print_ll(head);

#endif

#if 0 // comment node
    Node_t *head2 = create_ll();
    if(comment_node(head, head2))
        printf("have a comment node\n");
    else
        printf("haven't a comment node\n");

    puts("create comment node after");
    p2Linktop1node(head, head2, 3);
    Node_t *tmp = comment_node_R(head, head2);
    printf("%d\n", tmp->data);
    
    //if(comment_node(head, head2))
        //printf("have a comment node\n");
    //else
        //printf("haven't a comment node\n");

#endif

#if 0 // sortList

    head = sortList(head);
    print_ll(head);

#endif

#if 0 //palindromic
    if (isPalindromic_list(head))
        printf("It's a palindromic list\n");
    else
        printf("It's not\n");
#endif


#if 1 // odd and even

    head = odd_to_even(head);
    print_ll(head);

#endif


    /*free_ll(head, NULL);*/

    return 0;
}

