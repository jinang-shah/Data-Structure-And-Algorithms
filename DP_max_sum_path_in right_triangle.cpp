#include<iostream>
#define N 4
using namespace std;

int max(int a, int b){
	return (a>b)? a:b;
}

void msp(int a[][N]){
	int dp[N][N];
	
	dp[0][0] = a[0][0];
	
	for(int i=1;i<N;i++){
		for(int j=0;j<=i;j++){
			if(i==j){
				dp[i][j] = dp[i-1][j-1] + a[i][j];
			}
			else if(j==0){
				dp[i][j] = dp[i-1][j] + a[i][j];
			}
			else{
				dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
			}
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
	int max=0;
	for(int i=0;i<N;i++){
		if(dp[N-1][i] > max){
			max = dp[N-1][i];
		}
	}
	cout<<max;
	
	
}


int main(){
	int a[N][N] = {{1}, {1,2}, {4,1,2},{2,3,1,1}};
	msp(a);
}

