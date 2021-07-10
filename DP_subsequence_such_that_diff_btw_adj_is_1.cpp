#include<iostream>
#include<cstdlib>
using namespace std;

void find_size(int a[], int n){
	int dp[n];
	int omax=0;
	dp[0] = 1;
	
	for(int i=1;i<n;i++){
		int max=0;
		for(int j=0;j<i;j++){
			if(abs(a[i]-a[j])==1 && dp[j]+1 > max){
				max = dp[j] + 1;
			}
			else{
				dp[i] = 1;
				if(dp[i] > max){
					max = dp[i] ;
				}
			}
		}
		dp[i] = max;
		if(dp[i]>omax){
			omax = dp[i];
		}
	}
	
	for(int i=0;i<n;i++)
	   cout<<dp[i]<<" ";
	
	cout<<"\n"<<omax;
	
	
	
}

int main(){
	int a[] = {1, 2, 3, 4, 5, 3, 2};
	int n  = sizeof(a)/sizeof(a[0]);
	find_size( a, n);
}
