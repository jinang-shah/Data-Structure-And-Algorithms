#include <bits/stdc++.h>
using namespace std;

int max_med = 0;

vector<int> maxm;

int findMedian(vector<int> v){
    int n = v.size();
    
    sort(v.begin(), v.end());
    
    if(n%2==0){
        return v[(n/2)-1];
    }
    else{
        return v[(n/2)];
    }
    
}



void genSubSequence(int arr[], int k, vector<int> v, int i, int n){
    
    if( (v.size()<k) && i>=n ){
        return;
    }
    
    if(v.size()==k){
        int med = findMedian(v);
        if(med>max_med){
            max_med=med;
            maxm = v;
        }
        return;
    }
    
    
    v.push_back(arr[i]);
    i++;
    genSubSequence(arr, k, v, i, n);
    v.pop_back();
    genSubSequence(arr, k, v, i, n);
    
    return;
}



int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    
	    int arr[n];
	    
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    vector<int> v;
	    
        genSubSequence(arr, k, v, 0, n);
        
        cout<<max_med<<endl;
        
        for(int i=0;i<maxm.size();i++){
            cout<<maxm[i]<<" ";
        }
        cout<<endl;
	    
	}
	return 0;
}

