#include<iostream>
#include<stdio.h>
using namespace std;
struct node* insertion(struct node *root,int v);
void preOrderTraversal(struct node *root);
void inOrderTraversal(struct node *root);
void postOrderTraversal(struct node *root);
struct node* deletion(struct node *r,int v);
struct node* minValue(struct node* root);
int height(struct node* root);
void printLeafNodes(struct node* root);

struct node{
    int val;
    struct node *left;
    struct node *right;
};

struct node* minValue(struct node* root){
	while(root->left!=NULL){
		root=root->left;
	}
	return root;
}

struct node* deletion(struct node *r,int v){
	if(r==NULL){
		cout<<"Value not Found\n";
		return r;
	}
	else if(v < r->val){
		r->left = deletion(r->left,v);
	}
	else if(v > r->val){
		r->right = deletion(r->right,v);
	}
	else{
		struct node* temp;
		if(r->left==NULL){
			temp=r->right;
			cout<<"deleted node with value = "<<r->val<<endl;
			free(r);
			return temp;
		}
		else if(r->right==NULL){
			temp=r->left;
			cout<<"deleted node with value = "<<r->val<<endl;
			free(r);
			return temp;
		}
		// node with two children
		struct node* succ = minValue(r->right);
		r->val = succ->val;
		deletion(r->right,succ->val);
	}
	return r;
}

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

void inOrderTraversal(struct node *root){
    if(root!=NULL){
        inOrderTraversal(root->left);
         cout<<root->val<<endl;
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct node *root){
    if(root!=NULL){
        cout<<root->val<<endl;
        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct node *root){
    if(root!=NULL){
        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
        cout<<root->val<<endl;
    }
}

int height(struct node* root){
	if(root==NULL){
		return -1;
	}
	else if(root->left==NULL && root->right==NULL){
		return 0;
	}
	int hl = height(root->left);
	int hr = height(root->right);
	int h = 1 + max(hl,hr);
	return h;
}

void printLeafNodes(struct node* root){
	if(root->left==NULL && root->right==NULL){
		cout<<root->val<<" ";
		return;
	}
	if(root->left!=NULL){
		printLeafNodes(root->left);
	}
	if(root->right!=NULL){
		printLeafNodes(root->right);
	}
}

int findDepth(struct node* root,int v){
	if(root==NULL){
		return -1;
	}
	int dist = -1;
	if(root->val==v)
}



int main(){
    struct node *root=NULL;		
    root = insertion(root,50);
    root = insertion(root,10);
    root = insertion(root,40);
    root = insertion(root,30);
    root = insertion(root,80);
    root = insertion(root,5);
    root = insertion(root,6);
    root = insertion(root,60);
    root = insertion(root,90);
    root = insertion(root,85);
    root = insertion(root,100);
    root = insertion(root,95);
    root = insertion(root,88);
    root = insertion(root,89);
    inOrderTraversal(root);
    //root = deletion(root,80);
    inOrderTraversal(root);
    //int h = height(root);
    //cout<<"Height : "<<h<<endl;
    cout<<"Leaf Nodes : ";
    printLeafNodes(root);
}
