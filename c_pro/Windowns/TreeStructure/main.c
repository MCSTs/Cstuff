#include "total.h"

int main(void)
{
	struct node* root = NULL;
	int val;
	printf("enter tree node: ");
	while(scanf("%d", &val))
	{
		//insertNode(&root, val);
		root = insert(root, val);
	}
	while(getchar() != '\n');


#if 0 // Find treeNode
	int number;
	while(scanf("%d", &number))
	{
		if(serchNode(root, number))
			printf("Find it!\n");
		else
			printf("Not find it\n");
	}
#endif



#if 1 // Depth-first traversal
	printf("Preorder traversal is: ");
	preorder(root);
	putchar('\n');

	printf("Inorder traversal is: ");
	inorder(root);
	putchar('\n');

	printf("Postorder traversal is: ");
	postorder(root);
	putchar('\n');
#endif

#if 0 // DeleteNode
	int node;
	while(1)
	{
		printf("enter one node to delete: ");
		if(scanf("%d", &node)==0)
		{
			while(getchar()!='\n');
			break;
		}
		root = DeleteNode(root, node);

		printf("Preorder traversal is: ");
		preorder(root);
		putchar('\n');

		while(getchar()!='\n');
	}
#endif

#if 0 //get Successor or Precursor
	int node;
	printf("Enter the target node to find it Precursor node: ");
	while(1)
	{
		if(scanf("%d", &node)==0)
		{
			while(getchar()!='\n');
			break;
		}
		//int re = getSuccessor(root, node);
		int re = getPrecursor(root, node);
		printf("The result is: %d\n", re);
	}
#endif

#if 0 //  Breath-first traversal
#endif


	return 0;
}
