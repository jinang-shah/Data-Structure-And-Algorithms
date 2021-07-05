#include<iostream>
using namespace std;

void countSubsequences(int a[], int n, int k){
    
    int prod =1;
    int l=0,r=0;
    int res = 0;
    
    for(int l=0;l<n;l++){
    	for(int r=0;r<n;r++){
    		prod *= a[r];
    		if(prod>=k){
    			prod /= a[l];
    			l++;
			}
			res = l-r+1;
		}
	}
	
	cout<<res;
}

int main(){
    int a[] = {4, 8, 7, 2};
    int n = sizeof(a)/sizeof(a[0]);
    int k =50;
    countSubsequences(a, n, k);
}
