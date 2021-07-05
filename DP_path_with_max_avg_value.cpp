#include<iostream>
#define N 3
using namespace std;

int max(int a, int b){
	return (a>b)? a:b;
}

void pwmav(int a[][N]){
	int dp[N][N];
	dp[N-1][N-1]= a[N-1][N-1];
	
	for(int i=N-1;i>=0;i--){
		for(int j=N-1;j>=0;j--){
			if(i==N-1 && j==N-1){
				continue;
			}
			else{
				if(j==N-1){
					dp[i][j] = dp[i+1][j] + a[i][j];
				}
				else if(i==N-1){
					dp[i][j] = dp[i][j+1] + a[i][j];
				}
				else{
					dp[i][j] = max(dp[i][j+1], dp[i+1][j]) + a[i][j];
				}
			}
			
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<(double)dp[0][0]/(2*N-1);
}


int main(){
	int a[N][N] = { {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
	pwmav(a);
}

