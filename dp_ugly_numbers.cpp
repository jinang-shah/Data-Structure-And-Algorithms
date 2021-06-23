#include<iostream>
using namespace std;

int maxDivide(int a,int b){
	while(a%b == 0){
		a = a/b;
	}
	return a;
}


int ugly(int n){
	n = maxDivide(n,2);
	n = maxDivide(n,3);
	n = maxDivide(n,5);
	
	return (n==1)? 1:0;
}

int getNthUgly(int n){
	int i=1;
	int count=1;  //counts ugly numbers.
	while(count<n){
		i++;
		if(ugly(i)){
			count++;
		}
	}
	return i;
}

int main(){
	int n=150;
	int ugly = getNthUgly(n);
	cout<<n<<"th Ugly number is : "<<ugly;
}
