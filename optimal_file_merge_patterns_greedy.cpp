#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void optimalMerge(int files[],int n){
	priority_queue< int, vector<int> , greater<int> > pq;
	
	for(int i=0;i<n;i++){
		pq.push(files[i]);
	}
	
	int count=0;
	
	while(pq.size()>1){
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		
		int temp = first+second;
		count += temp;
		
		pq.push(temp);
	}
	
	cout<<"result : "<<count;
}

int main(){
	int files[]={2, 3, 4};
	int n =sizeof(files)/sizeof(files[0]);
	optimalMerge(files, n);
	
	return 0;
}
