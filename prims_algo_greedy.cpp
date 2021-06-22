#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define V 5

void printMST(int parent[],int graph[V][V]);

int minKey(int key[V],bool mstSet[V]){
	int min = INT_MAX,min_index;
	for(int i=0;i<V;i++){
		if(mstSet[i]==false && key[i]<min){
			min = key[i];
			min_index = i;
		}
	}
	return min_index;
}

void primsMST(int graph[V][V]){
	int parent[V];
	int key[V];
	bool mstSet[V];
	
	for(int i=0;i<V;i++){
		key[i]=INT_MAX;
		mstSet[i]=false;
	}
	
	key[0]=0;
	parent[0]=-1;
	
	for(int count=0;count<V-1;count++){
		int u = minKey(key,mstSet);
		mstSet[u]=true;
		
		for(int v=0;v<V;v++){
			if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v]){
				parent[v]=u;
				key[v]=graph[u][v];
			}
		}
		
	}
	
	printMST(parent,graph);
	
}

void printMST(int parent[],int graph[V][V]){
	cout<<"Edge  \t weight\n";
	for(int i=1;i<V;i++){
		cout<<parent[i]<<" - "<<i<<"  \t"<<graph[i][parent[i]]<<"\n";
	}
}


int main(){
	int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
	primsMST(graph);
	
	return 0;
}
