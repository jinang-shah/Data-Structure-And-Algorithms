#include<iostream>
using namespace std;
int maxsum(int a[],int n);

int main()
{
	int i,n=5,arr[10];
	
	for(i=0;i<n;i++)
	   cin>>arr[i];
	   
	int sum=maxsum(arr,n);
	cout<<sum<<endl;   
}

int maxsum(int a[],int n)
{
	int i,temp1=0,temp2=0;
	
	for(i=0;i<n;i++){
		if((i%2)==0)
		    temp1=temp1+a[i];
		    
		else
		    temp2=temp2+a[i];     		    
	}   
	
	if(temp1>temp2)
	    return temp1;
	else
	   return temp2;    
}
