#include<iostream>
using namespace std;
#define NIL -1
int lookup[100];

int tabulation_dp(int n){
	int f[n+1];
	f[0]=0,f[1]=1;
	
	for(int i=2;i<=n;i++){
		f[i] = f[i-1]+f[i-2];
	}
	
	return f[n];
}

int memoization_dp(int n){
	if(lookup[n]==NIL){
		if(n<=1){
			lookup[n]=n;
		}
		else
		   lookup[n] = memoization_dp(n-1) + memoization_dp(n-2);
	}
	
	return lookup[n];
}

int main(){
	int n = 9;
	for(int i=0;i<100;i++){
	   lookup[i]=NIL;
    }
	int tabu = tabulation_dp(n);
	int memo = memoization_dp(n); 
	
	cout<<"Memoization : "<<memo<<endl;
	cout<<"Tabulation : "<<tabu<<endl;
	
}
