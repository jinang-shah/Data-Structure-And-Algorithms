#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int max(int a, int b){
	return (a>b)?a:b;
}

void lcs(char *A,char *B,int m,int n){
	int dp[m+1][n+1];
	int i,j;
	    
	for( i=0;i<=m;i++){
		for( j=0;j<=n;j++){
			if(i == 0 || j == 0){
		 		dp[i][j]=0;
			}
			else if(A[i-1]==B[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	} 
	   
	cout<<dp[m][n];
}

int main(){
	char A[] = "AGGTAB";
	char B[] = "GXTXAYB";
	int m = strlen(A);
	int n = strlen(B);
	lcs(A,B,m,n);
}
