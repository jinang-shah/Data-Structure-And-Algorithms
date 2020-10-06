#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int arr[10];
	int i,temp,n=5;
	
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	

	for(i=0;i<n/2;i++){
		temp=arr[n-i-1];
		arr[n-i-1]=arr[i];
		arr[i]=temp;
	}
	
	cout<<"######  Reverse Array  #######\n";
	
	for(i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}
