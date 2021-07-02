#include<iostream>
using namespace std;

void lis(int a[], int n){
	int result[n];
	int last;
	int max=0;
	
	for(int i=0;i<n;i++){
		last = a[i];
		int count = 1;
		for(int j=i+1;j<n;j++){
			if(a[j]>last){
				last = a[j];
				count++;
			}
		}
		
		result[i] = count;
		if(result[i]>max){
			max = result[i];
		}
		
	}
	
	cout<<"Longest Increasing Subsequence size : "<<max;
	return ;
}

void dp_lis(int a[], int n){
	int dp[n];
	int omax = 0;
	
	for(int i=0;i<n;i++){
		int max = 0;
		for(int j=0;j<i;j++){
			if(a[j]<a[i]){
				if(dp[j]>max){
					max = dp[j];
				}
			}	
		}
		dp[i] = max+1;
		if(dp[i] > omax){                 // omax = overall max
			omax = dp[i];
		}
	}
	
	cout<<omax;
	
}

int main(){
	int a[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	int n = sizeof(a)/sizeof(a[0]);
	
	dp_lis(a,n);
	
	return 0;
}
