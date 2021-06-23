#include<iostream>
using namespace std;

int permuCoeff(int n,int k){
	//tabulation method
	int F[n+1];
	F[0]=1;
	for(int i=1;i<=n;i++){
		F[i] = F[i-1]*i;
	}
	return F[n]/F[n-k];
}

int main(){
	int n=10;
	int k=2;
	
	cout<<"P("<<n<<", "<<k<<") = "<<permuCoeff(n,k);
}
