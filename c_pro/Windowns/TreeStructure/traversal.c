#include "total.h"

/***********************************************************/
// Depth-first
// Preorder
void preorder(struct node* root)
{
	if(!root)
		return;

	printf("%d ", root->val);
	preorder(root->left);
	preorder(root->right);
	return;
}

void postorder(struct node* root)
{
	if(!root)
		return;

	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->val);
}

void inorder(struct node* root)
{
	if(!root)
		return;

	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}
/***********************************************************/



//Breath-first 

/***********************************************************/
// Queue

// breadth-first traversal



/***********************************************************/
