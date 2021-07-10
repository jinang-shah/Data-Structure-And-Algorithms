#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int min(int a, int b){
	return (a>b)? b:a;
}

int find_minimum_cost(int a[], int n, int w){
	int dp[n][w+1];
	
	for(int i=0;i<n;i++){
		dp[i][0] = INT_MAX;
	}
	
	for(int i=0;i<=w;i++){
		dp[0][i] = INT_MAX;
	}
	
	for(int i=1;i<n;i++){
		for(int j=1;j<=w;j++){
			if(j<i){
				dp[i][j] = dp[i-1][j];
			}
			else if((j%i)==0){
				dp[i][j] = min(dp[i-1][j], (j/i)*a[i]);
			}
			else{
				dp[i][j] = min(dp[i-1][j], dp[i][j%i] + dp[i][j-1]);
			}
		}
	}
	
	for(int i=1;i<n;i++){
		for(int j=1;j<=w;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<dp[n-1][w];
	 
}

int main(){
	int b[] = {20, 10, 4, 50, 100};
	int w = 5;
	int n = sizeof(b)/sizeof(b[0]);
	int a[n+1];
	
	a[0] = 0;
	for(int i=0;i<n;i++){
		a[i+1] = b[i];
	}
	
	n = sizeof(a)/sizeof(a[0]);
	find_minimum_cost(a, n, w);
}
