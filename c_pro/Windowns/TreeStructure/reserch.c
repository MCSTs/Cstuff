#include "total.h"

// recursion
int serchBST(struct node* root, int val)
{
	if(root==NULL)
		return 0;
	else if(root->val==val)
		return 1;
	else if(val <= root->val)
		return serchBST(root->left, val);
	else if(val > root->val)
		return serchBST(root->right, val);

}

int serchNode(struct node* root, int val) 
{
	if(root==NULL)
		return 0;
	if(root->val==val)
		return 1;

	while(root)
	{
		if(root->val==val)
			return 1;
		if(val <= root->val)
			root = root->left;
		else
			root = root->right;
	}
	return 0;
}
