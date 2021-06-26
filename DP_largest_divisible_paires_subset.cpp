#include<iostream>
using namespace std;

int ldps(int a[],int n){
	int dp[n];
	dp[0] = 1;
	for(int i=1;i<n;i++){
		dp[i]=0;
		for(int j=i-1;j>=0;j--){
			if(a[j]%a[i] == 0 || a[i]%a[j] == 0){
				dp[i] = max(dp[i],dp[j]);
			}
		}
		dp[i] = dp[i]+1;
	}
	
	int max=0;
	for(int i=0;i<n;i++){
		if(dp[i]>max){
			max = dp[i];
		}
	}
	return max;
}

int main(){
	int a[] = {10,5,20,3,15};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<"size of largest subset : "<<ldps(a,n);
}
