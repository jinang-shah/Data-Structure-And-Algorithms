// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    
	    int arr[n];
	    priority_queue<int, vector<int>  > pq;
	    
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        pq.push(arr[i]);
	    }
	    
	    /*
	    cout<<"pq"<<endl;
	    for(int i=0;i<n;i++){
	    	cout<<pq.top()<<" ";
	    	pq.pop();
		}
		cout<<endl;
	    */
	    
	    vector<int> v;
	    
	    for(int i=0;i<(n-k);i++){
	        v.push_back(pq.top());
	        pq.pop();
	    }
	    
	    cout<<pq.top()<<endl;
	    v.push_back(pq.top());
	    pq.pop();
	    
	    for(int i=0;i< (n-k);i++){
	        pq.pop();
	    }
	    
	    while(!pq.empty()){
	        v.push_back(pq.top());
	        pq.pop();
	    }
	    
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
	    
	}
	return 0;
}

