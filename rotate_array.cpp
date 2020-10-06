#include<iostream>
using namespace std;
void rotate(int a[],int n,int s);

int main()
{
	int arr[20];
	int i,n=7;
	
	for(i=0;i<n;i++)
	     cin>>arr[i]; 
	
	rotate(arr,n,3);
}

void rotate(int a[],int n,int s)
{
	int i,temp,j=0;
	int b[n];
	
	for(i=0;i<n;i++)
	{
		b[i]=a[i];
	}
	
	for(i=0;i<n-s;i++)
	{
		a[i]=a[i+s];
	}
	
	for(i=n-s;i<n;i++)
	{
		a[i]=b[j];
		j++;
	}
	
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
