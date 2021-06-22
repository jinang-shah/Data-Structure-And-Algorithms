#include<stdio.h>
#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph{
	int V;
	list<int> *l;

public:
	
	Graph(int v){
		this->V=v;
		l= new list<int> [V];
	}
   
   void addEdge(int a,int b){
   	  l[a].push_back(b);
   	  l[b].push_back(a);
   }
   
   void printGraph(){
   	  for(int i=0;i<V;i++){
   	    cout<<"Vertext : "<<i<<endl<<"head->";
   	    for(int x:l[i]){
   	        cout<<x<<"->";	
		}
		cout<<endl;
		cout<<endl;		
	  }
   } 	
   
   void dfsHelper(int start,bool visited[]){
	  visited[start]=true;
	  
	  	cout<<" -> "<<start;
	  	for(int i:l[start]){
	  		if(!visited[i]){
	  			 dfsHelper(i,visited);
			}
		}
      
   }
   
   void DFS(int start){
   	  bool visited[V];
   	  cout<<endl;
   	  cout<<endl;
	  cout<<"DSA ";
   	  for(int i:visited){
   	  	    i=false;
		 }
		 
	   dfsHelper(start,visited);	 
	
	  
	  }	 
		 
	
};

int main(){
	
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);
	return 0;
}
