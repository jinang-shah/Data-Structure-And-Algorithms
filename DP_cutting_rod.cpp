#include<iostream>
using namespace std;

void cutRod(int profit[],int n){
	int dp[n];
	dp[0] = 0;
	dp[1] = profit[1];
	
	for(int i=2;i<n;i++){
		for(int )
	}
	
}

int main(){
	int p[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = sizeof(p)/sizeof(p[0]);
	
	int profit[n+1];
	profit[0] = 0;
	for(int i=1;i<=n;i++){
		profit[i] = p[i-1];
	}
	n = sizeof(profit)/sizeof(profit[0]);
	
	cutRod(profit, n);
}
