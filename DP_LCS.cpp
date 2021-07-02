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
	
	cout<<endl<<"LCS Size : "<<dp[m][n]<<endl;
	
	cout<<"\nLongest Common Subsequence : ";
	i = m, j = n;
	while(j!=0 || i!=0){
			if(A[i-1]==B[j-1]){
				cout<<A[i]<<" ";
				i=i-1;
				j=j-1;
			}
			else{
				if(dp[i][j-1]>dp[i-1][j]){
					j = j-1;
				}
				else{
					i = i-1;
				}
			}
	}	
}

int toggle(int a){
	return (a==0) ? 1:0;
}

void lcs_space_optimised(char *A,char *B,int m,int n){
	int dp[2][n+1];
	int cur = 1;
	int prev = 0;
	int i,j;
	    
	for( i=0;i<=m;i++){
		for( j=0;j<=n;j++){
			if(i == 0 || j == 0){
		 		dp[i][j]=0;
			}
			else if(A[i-1]==B[j-1]){
				dp[cur][j] = 1 + dp[prev][j-1];
			}
			else{
				dp[cur][j] = max(dp[prev][j], dp[cur][j-1]);
			}
		}
		
		toggle(cur);
		toggle(prev);
	}
	
	
	cout<<endl<<"LCS Size : "<<dp[cur][n]<<endl;
	
}


int main(){
	char A[] = "AGGTAB";
	char B[] = "GXTXAYB";
	int m = strlen(A);
	int n = strlen(B);
	lcs_space_optimised(A,B,m,n);
}
