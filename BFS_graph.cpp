#include<stdio.h>
#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
	int V;
	list<int> *l;

public:
	
	Graph(int v){
		this->V=v;
		l = new list<int> [V];
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
   
   void BFS(int start){
   	  bool visited[V];
   	  queue<int> que;
   	  
   	  // Mark all the vertices as not visited
   	  for(int i=0;i<V;i++){
   	  	visited[i]=false;
		 }	 
		 
   	  //push first element in queue
   	  que.push(start);
   	  visited[que.front()]=true;
   	  
   	  while(!que.empty()){
   	  	   int node=que.front();
   	  	   que.pop();
   	  	   cout<<node<<"->";
   	  	   for(int i:l[node]){
   	  	   	   if(!visited[i]){
   	  	   	   	   que.push(i);
		   	  	   visited[i]=true;
		   	  	   
				}
	   	  	   	 
			}
	   }
   	  
   	  	
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
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
	return 0;
}
