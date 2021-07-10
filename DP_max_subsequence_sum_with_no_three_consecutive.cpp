#include<iostream>
using namespace std;

int max(int a, int b){
	return (a>b)? a:b;
}

void msswntc(int a[], int n){
	int dp[n];
	
	dp[0] = a[0];
	dp[1] = dp[0] + a[1];
	
	for(int i=2;i<n;i++){
		dp[i] = max(max(dp[i-1], dp[i-2]+ a[i]), a[i] + dp[i-3] + a[i-1]);
	}
		
	cout<<dp[n-1];
	
	
}

int main(){
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8	};
	int n = sizeof(a)/sizeof(a[0]); 	
	msswntc(a, n);
}
