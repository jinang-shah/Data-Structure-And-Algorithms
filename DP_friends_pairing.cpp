#include<iostream>
using namespace std;

int countWays(int n){
	int F[n+1];
	F[0]=0;
	F[1]=1;
	F[2]=2;
	
	for(int i=3;i<=n;i++){
		F[i] = F[i-1] + (i-1)*F[i-2];
	}
	
	return F[n];
}

int main(){
	int n = 4;
	cout<<"No of Ways = "<<countWays(n);
}
