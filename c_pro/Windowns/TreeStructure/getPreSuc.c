#include "total.h"

struct node* findNode(struct node* root, int tar)
{
	if(root==NULL)
		return NULL;
	while(root)
	{
		if(tar == root->val)
			return root;
		else if(tar < root->val)
			root = root->left;
		else
			root = root->right;
	}
	return NULL;
}

int getSuccessor(struct node* root, int tar)
{
	struct node* cur = findNode(root, tar);
	struct node* ancestor = root;
	struct node* successor = NULL;

	if(cur==NULL)
	{
		printf("The tree does'n have the node\n");
		return -1;
	}
	if(cur->right!=NULL)
		return cur->right->val;

	while(cur != ancestor)
	{
		if(cur->val <= ancestor->val)
		{
			successor = ancestor;
			ancestor = ancestor->left;
		}
		else
			ancestor = ancestor->right;
	}
	if(successor==NULL)
	{
		printf("The node does'n have successor node\n");
		return -1;
	}
	return successor->val;
}

int getPrecursor(struct node* root, int tar)
{
	struct node* cur = findNode(root, tar);
	if(cur==NULL)
	{
		printf("Does'n find the node\n");
		return -1; 
	}

	if(cur->left)
	{
		struct node* tmp = cur->left;
		while(tmp->right)
			tmp = tmp->right;
		return tmp->val;
	}

	struct node* descendant = root;
	struct node* precursor = NULL;

	while(cur != descendant)
	{
		if(cur->val <= descendant->val)
			descendant = descendant->left;
		else
		{
			precursor = descendant;
			descendant = descendant->right;
		}
	}

	if(precursor==NULL)
	{
		printf("It is no precursor node\n");
		return -1;
	}

	return precursor->val;

}
