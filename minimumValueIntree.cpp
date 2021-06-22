#include<iostream>
#include<stdio.h>
using namespace std;
struct node* insertion(struct node *root,int v);
int minValue(struct node* root);

struct node{
    int val;
    struct node *left;
    struct node *right;
};

struct node* insertion(struct node *root,int v){
    struct node *newnode,*temp;
    newnode= (struct node*)malloc(sizeof(struct node));
    newnode->val=v;
    newnode->left=NULL;
    newnode->right=NULL;
   
    if(root==NULL){
        return newnode;
    }
    temp=root;
    while(1){
        if(v<temp->val){
            if(temp->left==NULL){
                temp->left=newnode;
                break;
            }
            temp=temp->left;
        }
        else{
            if(temp->right==NULL){
                temp->right=newnode;
                break;
            }
            temp=temp->right;
        }
    }
    return root;
}

int minValue(struct node* root){
	while(root->left!=NULL){
		root=root->left;
		temp=root;
	}
	return root->val;
}

int main(){
    struct node *root=NULL;		
    root = insertion(root,50);
    root = insertion(root,10);
    root = insertion(root,80);
    root = insertion(root,5);
    root = insertion(root,60);
    root = insertion(root,90);
    int x = minValue(root);
    cout<<"minimum valued node = "<<x<<endl;
}


