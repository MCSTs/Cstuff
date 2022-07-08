#ifndef __TOTAL_H__
#define __TOTAL_H__

#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node* left;
	struct node* right;
	struct node* next;
};


// create and insert 
struct node* createNode(int );
struct node* insertNode(struct node** , int );
struct node* insert(struct node*, int );

// Serch
int serchBST(struct node* , int );
int serchNode(struct node* , int );

// Deatch-first
// traversal
void preorder(struct node* );
void inorder(struct node* );
void postorder(struct node* );

// DeleteNode
struct node* findMin(struct node* );
struct node* DeleteNode(struct node* , int);

// get Successor
struct node* findNode(struct node* , int );
int getSuccessor(struct node* , int );

// get Precursor
int getPrecursor(struct node* , int );

#endif
