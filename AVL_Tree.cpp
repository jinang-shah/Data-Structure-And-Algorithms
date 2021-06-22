#include<iostream>
#include<stdio.h>
using namespace std;
struct node* insert(struct node* root, int v);
int max(int a,int b);
int getBalance(struct node* root);

struct node{
	int val,height;
	struct node *left,*right;
};

int max(int a,int b){
	return (a>b)? a : b;
}

struct node* newnode(int v){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->height=1;
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->val = v;
	return newnode; 
}

int height(struct node* root){
	if(root==NULL){
		return 0;
	}
	return root->height;
}

int getBalance(struct node* root){
	if(root==NULL){
		return 0;
	}
	return height(root->left)-height(root->right);
}

struct node* rotateLeft(struct node* x){
	struct node *y = x->right;
    struct node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
} 

struct node* rotateRight(struct node* y){
	struct node *x = y->left;
    struct node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
} 

struct node* insert(struct node* root, int v){
	if(root==NULL){
		return newnode(v);
	}
	if(v < root->val){
		root->left = insert(root->left,v);
	}
	else{
		root->right = insert(root->right,v);
	}
	
	root->height = 1 + max(height(root->left), height(root->right));
	
	int balance = getBalance(root);
	
	if(balance>1 && v<root->left->val){
		return rotateRight(root);
	}
	if(balance<1 && v>root->right->val){
		return rotateLeft(root);
	}
	if(balance>1 && v>root->left->val){
		root->left = rotateLeft(root->left);
		return rotateRight(root);
	}
	if(balance>1 && v>root->left->val){
		root->left = rotateLeft(root->left);
		return rotateRight(root);
	}
	
	return root;
}

void preOrder(struct node* root){
	if(root!=NULL){
		cout<<root->val<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main(){
	struct node* root = NULL;
	root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    preOrder(root);
    return 0;
}
