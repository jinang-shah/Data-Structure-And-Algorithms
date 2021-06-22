#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(){
	
	//Max Heap
	priority_queue< int,vector<int> > pq;     //pq=priority_queue
	pq.push(2);
	pq.push(1);
	pq.push(30);
	
	cout<<pq.top()<<endl;
	
	pq.pop();
	cout<<pq.top()<<endl;
	
	//Min Heap
	priority_queue< int, vector<int>, greater<int> > pq_min;
	pq_min.push(50);
	pq_min.push(20);
	pq_min.push(70);
	pq_min.push(30);
	pq_min.push(10);
	
	cout<<pq_min.top()<<endl;
	
	pq_min.pop();
	cout<<pq_min.top()<<endl;
	
	
	
	return 0;
}
