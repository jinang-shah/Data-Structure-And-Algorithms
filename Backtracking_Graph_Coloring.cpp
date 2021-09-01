#include<bits/stdc++.h>
#define V 4
using namespace std;

void printSol(int a[]){
	for(int i=0;i<V;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

bool isSafe(int graph[][V], int v,int c,int sol[]){
	for(int i=0;i<V;i++){
		if(graph[v][i]==1 && sol[i]==c){
			return false;
		}
	}
	return true;
}

bool graphColor(int graph[V][V], int v, int m, int sol[V]){
	
	if(v==V){
		printSol(sol);
		return true;
	}
	for(int i=1;i<=m;i++){
		
		if(isSafe(graph, v, i, sol)==true){
			cout<<"safe\n";
			sol[v]=i;
			if(graphColor(graph, v++, m, sol)==true){
				return true;
			}
			sol[v]=0;
		}
	}
	return false;
}

int main(){
	int graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
	int sol[V];

    for(int i=0;i<V;i++){
		sol[i]=0;
	}

	int m = 3;
	graphColor(graph, 0, m, sol);

	return 0;
}