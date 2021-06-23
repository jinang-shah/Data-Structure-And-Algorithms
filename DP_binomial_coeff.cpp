#include<iostream>
using namespace std;
int min(int a,int b);


int binomialCoeff(int n,int k){
	if(k>n)
	    return 0;
	if(k==n || k==0){
		return 1;
	}
	else{
		return binomialCoeff(n-1,k-1)+binomialCoeff(n-1,k);
	}
}

int dp_tabu_binomialCoeff(int n,int k){
	int C[n+1][k+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=min(i,k);j++){
			if(j==0 || j==i){
				C[i][j]=1;
			}
			else{
				C[i][j] = C[i-1][j] + C[i-1][j-1];
			}
		}
	}
	return C[n][k];
}

int min(int a,int b){
	return (a>b) ? b:a;
}

int dp_memo_binoCoeff_util(int n,int k,int** dp){
	
	if(dp[n][k]==-1){
		if(k==0 || k==n){
			dp[n][k] = 1;
		}
		else{
			dp[n][k] = dp_memo_binoCoeff_util(n-1,k-1,dp) + dp_memo_binoCoeff_util(n-1,k,dp);
		}
		return dp[n][k];
	}
	
}

int dp_memo_binoCoeff(int n,int k){
	int **dp;
	
	dp = new int*[n+1];
	
	for(int i=0;i<n+1;i++){
			dp[i]=new int[k+1];
		}
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<k+1;j++){
			dp[i][j]=-1;
		}
	}
	
	return dp_memo_binoCoeff_util(n,k,dp);
	
}


int main(){
	int n = 4, k = 2;
	
    cout << "Value of C(" << n << ", " << k << ") = "
         << dp_memo_binoCoeff(n, k);
    return 0;
}
