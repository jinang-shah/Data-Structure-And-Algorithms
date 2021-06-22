#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
	int V;
	list<int> *l ;
  public:
  	
	Graph(int v){
  		this->V=v;
  		l=new list<int> [V];
	  }
	  
	void addEdge(int a,int b){
		l[a].push_back(b);
		l[b].push_back(a);
	}  
	  
    void printGraph(){
    	for(int i=0;i<V;i++){
    		cout<<"Vertext :"<<i<<"->";
    		for(int x:l[i]){
    			cout<<"->"<<x;
			}
			cout<<endl;
		}
	}
	
	void BFS(int start,int end){
		queue<int> que;
		bool visited[V];
		int flag=0;
		
		for(int i:visited){
			i=false;
		}
		
		que.push(start);
		visited[start]=true;
		cout<<"BFS:  strat :";
		
		while(!que.empty()){
			int node=que.front();
			que.pop();
			cout<<node<<"->";
			for(int x:l[node]){
				if(!visited[x]){
					if(x==end){
						cout<<" end :"<<x<<endl;
						flag=1;
						break;
					}
				    que.push(x);
				    visited[x]=true;
				}
			}
			if(flag==1){
				break;
			}
		}
		
	}
	 	
};

int main(){
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(2,3);
	g.addEdge(2,3);
	g.addEdge(2,3);
	g.printGraph();
	g.BFS(0,3);
}
