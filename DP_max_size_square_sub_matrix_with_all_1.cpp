#include<iostream>
#define M 6
#define N 5
using namespace std;

int min(int a, int b){
	return (a>b)? b:a;
}

void soswms(int a[][N]){
	int dp[M][N];
	
	
	
	for(int i=0;i<M;i++){
		dp[i][N-1]=a[i][N-1];
	}
	
	for(int i=0;i<N;i++){
		dp[M-1][i]=a[M-1][i];
	}	
	

	
	for(int i=M-2;i>=0;i--){
		for(int j=N-2;j>=0;j--){
			if(a[i][j]==0){
				dp[i][j] = 0;
			}
			else{
				dp[i][j] = min( min(dp[i][j+1],dp[i+1][j]), dp[i+1][j+1] )+ 1;
			}
			
		}
	}
	
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int max=0;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(dp[i][j]>max){
				max = dp[i][j];
			}
		}
	}
	cout<<max;
	
	
	
}

int main(){
	int a[M][N] = {{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};	
	soswms(a);
}
