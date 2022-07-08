#ifndef __TOTAL_H__
#define __TOTAL_H__

struct node{
	int value;
	struct node* next;
};

struct node* create();
struct node* myprint(struct node*);
struct node* gettail(struct node* );
struct node* CreateLoop(struct node*, int);


struct node* down(struct node* );
struct node* DownPortion(struct node*, int, int);

struct node* joint_2(struct node*, struct node*);
struct node* joint_new(struct node*, struct node*);
struct node* merge_rec(struct node* , struct node* );
struct node* sort_rec(struct node* );

struct node* rev(struct node* );
struct node* addInList(struct node* , struct node* );

struct node* delete_rep(struct node* );
struct node* delete_rep_all(struct node* );

struct node* merge2(struct node* , struct node* );

int isloop(struct node* );
struct node* loop_node(struct node* );

struct node* reverse_k(struct node* , int );
struct node* delete_down_k(struct node* , int );

struct node* odd_even_reset(struct node* );


#endif
