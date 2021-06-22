#include<iostream>
#include<stack>
#include<list>
#include<queue>
using namespace std;
int count=0;

struct node{
	int val;
	struct node* lptr;
	struct node* rptr;
	
	node(int v){
		val=v;
		rptr=NULL;
		lptr=NULL;
	}
};


void levelorderTraversal(struct node* root){
   if(root==NULL) return;	
   queue <node*> q;
   q.push(root);
   cout<<endl;
   cout<<"Leve order : ";
   while(!q.empty()){
   	  cout<<q.front()->val<<" ";
   	  if(q.front()->lptr!=NULL) q.push(q.front()->lptr);
   	  if(q.front()->rptr!=NULL) q.push(q.front()->rptr);
   	  q.pop();
   }	
}


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

void inOrder2Traversal(struct node* root){
	stack <node*> s;
	node* temp=root;
	
	while(temp!=NULL || !s.empty()){
		while(temp!=NULL){
			s.push(temp);
			temp=temp->lptr;
		}
		temp = s.top();
		cout<<temp->val<<" ";
		s.pop();
		temp=temp->rptr;
	}
	
	// time complexity : 0(n^2)
}

void countLeafNodes(struct node* root) {
	
   if(root==NULL) return;	
   else{
	   if(root->lptr==NULL && root->rptr==NULL){
	   	  cout<<root->val<<" "; 
	   	  count++;
	   	  return;
	   }
	   countLeafNodes(root->lptr);
	   countLeafNodes(root->rptr);
    }
}

int maximum(int a,int b){
	if(a>b)return a;
	else return b;
}

int heightOfTree(struct node* root){
	int left,right,max;
	if(root==NULL){
		return -1;
	}
	else{
		left=heightOfTree(root->lptr);
		right=heightOfTree(root->rptr);
		return maximum(left,right)+1;
	}
}

/*void leftBoundary(struct node* root){
	if(root==NULL){
		return;
	}
	else{
		cout<<root->val<<" ";
		leftBoundary(root->lptr);
	}
}


*/

void printLeafNodes(struct node* root){
	if(root->lptr==NULL && root->rptr==NULL) {
		cout<<root->val<<" ";
	}
	else if(root->lptr!=NULL) printLeafNodes(root->lptr);
	else if(root->rptr!=NULL) printLeafNodes(root->rptr);
}

void leftBoundary(struct node* root){
	
	stack <struct node*> s;
	if(root==NULL)return;
	
	while(root!=NULL){
		cout<<root->val<<" ";
		s.push(root);
		root=root->lptr;
	}
	
	while(!s.empty()){
		if(s.top()->rptr!=NULL){
			 printLeafNodes(s.top()->rptr);
		}
		s.pop();
	}
	
	
} 

void rightBoundary(struct node* root){
	stack <node*> s;
	if(root==NULL) return;
	while(root!=NULL){
		s.push(root);
		root=root->rptr;
	}
	printLeafNodes(s.top()->lptr);
	while(!s.empty()){
		cout<<s.top()->val<<" ";
		s.pop();
	}
}





int main(){
	struct node* root=new node(1);
	root->lptr=new node(2);
	root->rptr=new node(3);
	root->lptr->lptr=new node(4);
	root->lptr->rptr=new node(5);
	root->rptr->lptr=new node(6);
	root->rptr->lptr->lptr=new node(8);
	root->rptr->rptr=new node(7);
	root->rptr->rptr->lptr=new node(9);
	root->rptr->rptr->lptr->rptr=new node(11);
	cout<<"Pre-Order :";
	preOrderTraversal(root);
	cout<<endl;
	cout<<"In-Order :";
	inOrderTraversal(root);
	cout<<endl;
	cout<<"Post-Order :";
	postOrderTraversal(root);
	cout<<endl;
	cout<<"In-Order(without recurssion) :";
	inOrder2Traversal(root);

    levelorderTraversal(root);
    
    cout<<"\nCount Leaf Nodes : ";
    countLeafNodes(root);
    cout<<"\nTotal Leaf Nodes :"<<count<<endl;
    
    cout<<"Height of Tree : ";
    cout<<heightOfTree(root)<<endl;
    
    cout<<"Left Boundary of Tree : ";
    leftBoundary(root);
    cout<<endl;
    
    cout<<"Right Boundary of Tree : ";
    rightBoundary(root->rptr);
    cout<<endl;
    

	return 0;
}
