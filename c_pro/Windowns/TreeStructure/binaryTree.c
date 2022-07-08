#include "total.h"

struct node* createNode(int val)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->val = val;
	new->left = new->right = NULL;
	return new;
}

struct node* insertNode(struct node** root, int val)
{
	if(*root==NULL)
	{
		(*root) = createNode(val);
	}
	else if(val <= (*root)->val)
	{
		(*root)->left = insertNode( &((*root)->left), val);
	}
	else if(val > (*root)->val)
	{
		(*root)->right = insertNode( &((*root)->right), val);
	}
	return (*root);
}

struct node* insert(struct node* root, int val)
{
	if(root==NULL)
	{
		root = createNode(val);
		return root;
	}
	struct node* tmp = root;
	struct node* pre = NULL;
	struct node* new = createNode(val);
	int flag = 0;
	while(tmp)
	{
		if(val <= tmp->val)
		{
			pre = tmp;
			tmp = tmp->left;
			flag = 1;
		}
		else
		{
			pre = tmp;
			tmp = tmp->right;
			flag = 2;
		}
	}
	if(flag==1)
		pre->left = new;
	else
		pre->right = new;
	return root; 
}
