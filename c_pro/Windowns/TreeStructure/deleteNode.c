#include "total.h"

struct node* findMin(struct node* root)
{
	while(root->left!=NULL)
		root = root->left;
	return root;
}

struct node* DeleteNode(struct node* root, int val)
{
	if( !root )
		return NULL;

	else if(root->val > val)
		root->left = DeleteNode(root->left, val);
	else if(root->val < val)
		root->right = DeleteNode(root->right, val);
	else
	{
		// case 1
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			root = NULL;
		}
		// case 2
		else if(root->left==NULL)
		{
			struct node* tmp = root;
			root = root->right;
			free(tmp);
		}
		else if(root->right==NULL)
		{
			struct node* tmp = root;
			root = root->left;
			free(tmp);
		}
		else
		{
			struct node* tmp = findMin(root->right);
			root->val = tmp->val;
			root->right = DeleteNode(root->right, tmp->val);
		}
	}

	return root;
}
