#include<iostream>
using namespace std;

struct node{
	int a,b;
};


void mlcp(node a[], int n){
	int dp[n];
	
	for(int i=0;i<n;i++){
		dp[i]=1;
	}
	
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i].a > a[j].b && dp[i] < dp[j]+1){
				dp[i] = dp[j] + 1;
			}
		}
	}
	
	int max=0;
	for(int i=0;i<n;i++){
		if(dp[i]>max){
			max = dp[i];
		}
	}
	
	cout<<max;
}

int main(){	
	node a[] ={ {5, 24}, {15, 25}, {27, 40}, {50, 60} };      
	int n = sizeof(a)/sizeof(a[0]);
	mlcp(a, n);
}
