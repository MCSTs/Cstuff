 /** @param root TreeNode类 */
 /** @return int整型二维数组*/
 /** @return int* returnSize 返回数组行数*/
 /** @return int** returnColumnSizes 返回数组列数*/
 /**/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define maxlen 10000

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


typedef struct queHead{
    int queLen;
    int front;
    int rear;
    struct TreeNode **ar;
}queHead_t;

queHead_t *initQueue()
{
    queHead_t *qHead = malloc(sizeof(queHead_t));
    qHead->front  = -1;
    qHead->rear   = -1;
    qHead->queLen = 0;
    qHead->ar = malloc(10000 * sizeof(struct TreeNode *));
    return qHead;
}


bool isemptyQue(queHead_t *qHead)
{
    if (qHead->queLen == 0)
        return true;
    return false;
}


void Enqueue(queHead_t *qHead, struct TreeNode *p)
{
    if (qHead->queLen == 0) 
        qHead->front = qHead->rear = 0;
    
    else 
        qHead->rear++;
    (qHead->ar)[qHead->queLen] = p;
    qHead->queLen++;
}


void Dequeue(queHead_t *qHead)
{
    if (isemptyQue(qHead))
        return ;
    qHead->rear--;
    return ;
}



int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes ) {
    if (root == NULL)
        return NULL;
    int **re = malloc(10000 * sizeof(int *));
    int ind = 0;
    queHead_t *qHead = initQueue();
    Enqueue(qHead, root);
    while (!isemptyQue(qHead))
    {
        returnSize = malloc(10000 * sizeof(int));
        int n = qHead->queLen;
        for (int i=0; i<n; i++)
        {
            returnSize[i] = (qHead->ar[i])->val;
            if ((qHead->ar[i])->left)
                Enqueue(qHead, (qHead->ar[i])->left);
            if((qHead->ar[i])->right)
                Enqueue(qHead, (qHead->ar[i])->right);
            Dequeue(qHead);
        }
        re[ind++] = returnSize;
    }
    return re;
}


int** LevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes ) {
    
    *returnSize = 0; 
    if(root == NULL){
        return NULL;
    }
    struct TreeNode* queue[100000];  
    int** res = (int**)malloc(sizeof(int*) * 100000); 
    *returnColumnSizes = (int*)malloc(sizeof(int) * 100000); 
    int head = 0,rear = 0;  
    queue[rear] = root; 
    rear++; 
    while(head != rear){  
        int curRear = rear;  
        int k = 0;  
        res[*returnSize] = (int*)malloc(sizeof(int) * (curRear - head)); 
        while(head < curRear){   
            struct TreeNode* p = queue[head];  
            res[*returnSize][k++] = p->val; 
            if(p->left != NULL){  
                queue[rear++] = p->left;
            }
            if(p->right != NULL){ 
                queue[rear++] = p->right;
            }
            head++;  
        }
        (*returnColumnSizes)[*returnSize] = k;  
        (*returnSize)++; 
    }
    return res;
}
