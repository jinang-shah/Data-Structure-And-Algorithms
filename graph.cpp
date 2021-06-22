#include<stdio.h>
#include<iostream>
#include<list>
using namespace std;

class Graph{
	int V;
	list<int> *l;

public:
	
	Graph(int v){
		this->V=v;
		l= new list<int> [V];
	}
   
   void addedge(int a,int b){
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
	
};

int main(){
	
	Graph g(4);
	g.addedge(0,1);
    g.addedge(0,2);	
    g.addedge(0,3);
    g.addedge(1,3);
    g.addedge(1,2);
    g.addedge(2,3);
    g.printGraph();
	return 0;
}
