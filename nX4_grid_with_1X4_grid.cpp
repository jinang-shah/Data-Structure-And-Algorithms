#include<iostream>
using namespace std;

void countWays(int n, int m){
	int dp[n+1];
	dp[0]=0;
	for(int i=0;i<=n;i++){
		if(i<4){
			dp[i] = 1;
		}
		else if(i==4){
			dp[i] = 2;
		}
		else{
			dp[i] = dp[i-1] + dp[i-4];
		}
	}
	
	cout<<dp[n];
}

int main(){
	int n = 5;
	int m=4;
	countWays(n,m);
}
