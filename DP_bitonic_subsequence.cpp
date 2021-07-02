#include<iostream>
using namespace std;

void bitonic(int a[], int n){
	int dpI[n];
	int dpD[n];
	
	for(int i=0;i<n;i++){
		int max = 0;
		for(int j=0;j<i;j++){
			if(a[j]<a[i]){
				if(dpI[j] > max){
					max  = dpI[j];
				}
			}
		}
		dpI[i] = 1 + max;
	}
	
	for(int i=n-1;i>=0;i--){
		int max = 0;
		for(int j=n-1;j>i;j--){
			if(a[j]<a[i]){
				if(dpD[j] > max){
					max  = dpD[j];
				}
			}
		}
		dpD[i] = 1 + max;
	}
	
	int max = 0;
	
	for(int i=0;i<n;i++){
		if(dpI[i]+dpD[i]>max){
			max = dpI[i]+dpD[i]; 
		}
	}
	
	cout<<max-1;
	
	
}

int main(){
	int a[] ={40 ,80, 60, 30, 100, 20, 101};
	int n= sizeof(a)/sizeof(a[0]);
	
	bitonic(a, n);
}
