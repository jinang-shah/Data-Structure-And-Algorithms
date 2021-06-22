#include<stdio.h>
#include<iostream>
using namespace std;

struct node{
	int val;
	struct node *lptr;
	struct node *rptr;
	
	node(int v){
		val=v;
		lptr=NULL;
		rptr=NULL;
	}
};

void preOrderTraversal(struct node* root){
	if (root == NULL) 
        return;
    cout<<root->val<<" ";    
	preOrderTraversal(root->lptr);
	preOrderTraversal(root->rptr);
}

void postOrderTraversal(struct node* root){
	if (root == NULL) 
        return;
	postOrderTraversal(root->lptr);
	postOrderTraversal(root->rptr);
	cout<<root->val<<" ";
}

void inOrderTraversal(struct node* root){
	if (root == NULL) 
        return;
	inOrderTraversal(root->lptr);
	cout<<root->val<<" ";
	inOrderTraversal(root->rptr);
}

int main(){
	struct node* root = new node(1);
	root->lptr = new node(2);
	root->rptr = new node(3);
	root->lptr->lptr=new node(4);
	root->lptr->rptr=new node(5);
	preOrderTraversal(root);
	getchar();
	return 0;
	
}
