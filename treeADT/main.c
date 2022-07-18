#include "tree.h"
#include "queue.h"
#include <mcheck.h>


int main(void)
{

    mtrace();
    
    Node *root = NULL;
    int num;
    while (scanf("%d", &num)!=0)
    {
        root = insertTreeNode(root, num);
        /*root = insert_Norec(root, num);*/
    }
    while (getchar()!='\n')
        continue;

    
// 25 17 35 15 20 30 40 14 28 13 q
// 25 17 30 15 27 40 10 26 50 45 q
// 25 17 35 15 20 30 40 27 39 50 70 q
#if 1 // traversal

    queHead_t *qHead = initQueue();

    printf("LevelOrder: ");
    levelOrder(root, qHead);

    printf("PreOrder  : ");
    preOrder(root);
    printf("InOrder   : ");
    InOrder(root);
    printf("PostOrder : ");
    PostOrder(root);

#endif

#if 0 // deleteNode
{
    int val;
    printf("enter a number to delete:");
    while (scanf("%d", &val))
    {
        root = deleteNode(root, val);

        printf("LevelOrder: ");
        levelOrder(root, qHead);
        printf("enter again: ");
    }
}
#endif 


#if 0 // isBST?
{
    if (isBST(root))
        printf("It's a BST\n");
    else
        printf("It's not\n");

    /* break the BST */
    puts("Now find a leaf node and insert a node to it's rightNode.");
    int val, insNode;
    printf("enter a leaf node: ");
    scanf("%d", &val);
    printf("enter a number of node to insert: ");
    scanf("%d", &insNode);

    Node *tmp = searchNode(root, val);
    Node *dirtyNode = malloc(sizeof(Node));
    memset(dirtyNode, 0, sizeof(Node));
    dirtyNode->data = insNode;
    tmp->right = dirtyNode;
    printf("Insert done, Now...\n");

    if (isBST(root))
        printf("It's a BST\n");
    else
        printf("It's not\n");
}
#endif


#if 0 // isBalance 
{
    int re = getNodeHeight(root);
    printf("height: %d\n", re);
    if (isBalenceBT(root))
        printf("It's a balance tree\n");
    else
        printf("It's not\n");

    Node *tmp;
    tmp = findNotBalanceNode(root, &tmp);
    if (tmp)
        printf("Imbalance node: %d\n", tmp->data);

}        
#endif


#if 0 // find and search node
{
    Node *minNode = findMin_BST(root);
    printf("min: %d\n", minNode->data);
    Node *maxNode = findMax_BST(root);
    printf("max: %d\n", maxNode->data);
    // find node
    int val_node;
    printf("enter a number to find into the tree: ");
    while (scanf("%d", &val_node))
    {
        if(searchNode(root, val_node)!=NULL)
            printf("Find it\n");
        else
            printf("Not find it\n");
        printf("enter again('q' to quit): ");
    }
    while (getchar()!='\n');
}
#endif

#if 0 // get successor and pioneer
{
    int val;
    Node *successor = NULL;
    Node *pioneer   = NULL;
    printf("enter a value to find it successor and pioneer: ");
    while(scanf("%d", &val))
    {
        successor = getSuccessor(root, val);
        pioneer   = getPioneer(root, val);
        if (successor == NULL)
            printf("it haven't successor node\n");
        else
            printf("it successor: %d\n", successor->data);

        if (pioneer == NULL)
            printf("it haven't pioneer node\n");
        else
            printf("it pioneer: %d\n", pioneer->data);
        printf("enter again: ");
    }
    while (getchar()!='\n');
}
#endif 



#if 0 // test queue
{
    queHead_t *qHead = initQueue();
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
                Enqueue(qHead, num);
                break;
            case 'd': 
                      Dequeue(qHead); 
                      break;
            default : break;
        }

        printf("len: %d\n", qHead->queLen);
        printf("head: %d\n", qHead->front->data);
        printf("rear: %d\n", qHead->rear->data);
        print_que(qHead);
        while (getchar()!='\n');
    }
}
#endif



#if 0 // otherStuff
{
    int re = countDegreeOfOne(root);
    printf("re: %d\n", re);

    int Maxwidth = countMaxWidth(root);
    printf("Maxwidth: %d\n", Maxwidth);
}
#endif



#if 1 // free_BST
    free_BST(root);
    // destroy Qhead
    free(qHead);
#endif



    return 0;
}
