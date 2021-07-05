#include<iostream>
#define N 3
using namespace std;

int max(int a, int b){
	return (a>b)? a:b;
}

void mpst(int a[N][N]){
	
	for(int i=1;i<N;i++){
		for(int j=0;j<=i;j++){
			if(j==0){
				a[i][j] = a[i-1][j] + a[i][j];
			}
			else if(j==i){
				a[i][j] = a[i-1][j-1] + a[i][j];
			}
			else{
				a[i][j] = max(a[i-1][j], a[i-1][j-1]) + a[i][j];	
			}
			
		}
	}
	
	
	int max=0;
	for(int i=0;i<N;i++){
		if(a[N-1][i]>max){
			max=a[N-1][i];
		}
	}
	
	cout<<max;
	
}

int main(){
	int a[N][N] = {  {1, 0, 0},
                      {10, 8, 0},
                      {1, 5, 6} };
	mpst(a);
}
