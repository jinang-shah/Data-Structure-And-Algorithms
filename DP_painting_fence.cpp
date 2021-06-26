#include<iostream>
using namespace std;

void findWays(int n, int k){
	int same  = k*1;
	int diff = k*(k-1);
	int total = same + diff;
	
	for(int i=3;i<=n;i++){
		same = diff*1;
		diff = total*(k-1); 
		total = same + diff ;
	}
	
	cout<<total;
	
}

int main(){
	int n = 2;
	int k = 4;
	findWays(n,k);
}
