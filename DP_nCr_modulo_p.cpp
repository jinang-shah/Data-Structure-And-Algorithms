#include<iostream>
using namespace std;

void findNcrModuloP(int n,int r,int p){
	int dp[n+1][r+1];
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=min(i,r);j++){
			if(j==n || j==0){
				dp[i][j] = 1;
			}
			else{
				dp[i][j] = (dp[i-1][j-1]%p + dp[i-1][j]%p)%p;
			}
		}
	}
	
	cout<<dp[n][r];
	
}

int main(){
	int n = 10;
	int r = 2;
	int p = 13;
	findNcrModuloP(n,r,p);
}
