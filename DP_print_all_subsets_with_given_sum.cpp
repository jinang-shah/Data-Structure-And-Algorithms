#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include <sstream>
using namespace std;

void sos(int set[],int n, int sum){      //time complexity : 0(sum*n)
	bool dp[n+1][sum+1];
	
	for(int i=0;i<=n;i++)
	    dp[i][0]=true;
	
	for(int i=1;i<=sum;i++)
	    dp[0][i]=false;
	    
	for(int i=1;i<=n;i++){
		int val = set[i-1];
		for(int j=1;j<=sum;j++){
			if(val>j){
				dp[i][j] = dp[i-1][j];
			}
			if(val<=j){
				dp[i][j] = dp[i-1][j]  || dp[i-1][j-val];
			}
		}
	} 
	
    
    queue<pair<pair<int,int>, string> > q;
    
    if(dp[n][sum]==0){
    	cout<<"no any subset available.";
    	return ;
	}
    
    q.push({{n,sum}," "});
    ostringstream str1;
    
    while(!(q.empty())){
    	pair<pair<int,int>, string> p = q.front();
    	pair<int,int> pf = p.first; 
    	
    	if(pf.first==0 || pf.second==0){
    		cout<<p.second<<endl;
		}
		else{
			
			if(pf.second >= set[pf.first-1] ){
				int inc = dp[pf.first-1][pf.second-set[pf.first-1]];
				if(inc == 1)			    
				    str1 << ((pf.first)-1);
				    string temp = str1.str();
				    q.push({{pf.first-1,pf.second-set[pf.first-1]},p.second + " "+temp});
			} 
			
			int exc = dp[pf.first-1][pf.second];
			if(exc==1){
			    q.push({{pf.first-1,pf.second},p.second}); 	
		    }
		}
		q.pop();	
	}
}

int main(){
	int a[] = {10,20,30,50, 40};
    int sum = 50;
	int n  = sizeof(a)/sizeof(a[0]);
	sos(a,n,sum);
}
