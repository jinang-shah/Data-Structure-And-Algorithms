#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int p=0;p<t;p++){
	    int n,m;
	    cin>>n>>m;
	    int a[n+1];
	    
	    for(int s=0;s<=n;s++){
	        a[s]=0;
	    }
	    
	    vector< pair<int,int> > vect;
	    
	    for(int i=0;i<m;i++){
	        int x,y;
	        cin>>x>>y;
	        
	        vect.push_back( make_pair(x,y));
	    }
	    
	    sort(vect.begin(), vect.end());
	    
	    int sum=0;
	    
	    for(int i=m-1;i>=0;i--){
	        
	        int x = vect[i].first;
	        int y = vect[i].second;
	        
	        
	        for(int j=1;j<=n;j++){
	            
	            if((j%y)!=0  &&  a[j]==0){
	                a[j]=x;
	                sum+= a[j];
	            }
	        }
	    }
	    
	    
	    
	    
	    cout<<sum<<endl;
	    
	}
	return 0;
}

