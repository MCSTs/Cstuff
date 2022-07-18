#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



typedef struct TR_Node{
    int data;
    int height;
    struct TR_Node *next;
    struct TR_Node *left;
    struct TR_Node *right;
}Node;

typedef struct queHead{
    int queLen;
    Node *front;
    Node *rear;
}queHead_t;

typedef struct TR{
    struct TR_Node *root;
    int depth;
    int nodeNum;
}tree_t;


// create
Node *insertTreeNode(Node *root, int val);
Node *insert_Norec(Node *root, int val);
void free_BST(Node *root);

// traversal
void levelOrder(Node *root, queHead_t *qHead);
void preOrder(Node *root);
void InOrder(Node *root);
void PostOrder(Node *root);

// searchInBST
Node *findMin_BST(Node *root);
Node *searchNode(Node *root, int num);
Node *findMax_BST(Node *root);

// isBSTandBalance
bool isBST(Node *root);
int getNodeHeight(Node *root);
bool isBalenceBT(Node *root);
Node *findNotBalanceNode(Node *root, Node **re);


// delete
Node *deleteNode(Node *root, int val);

// get successor and pioneer
Node *getSuccessor(Node *root, int val);
Node *getPioneer(Node *root, int val);


// otherStuff
int countDegreeOfOne(Node *root);
int countMaxWidth(Node *root);


// rotate
Node *RRRotate(Node *node);
Node *LLRotate(Node *node);
Node *RLRotate(Node *node);
Node *LRRotate(Node *node);
