#include<iostream>
using namespace std;
int main()
{
	int i,n,k,total=0;
	int arr[10];
	cin>>n;
	cin>>k;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		arr[i]=arr[i]+k;
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]%7==0)
		    total++;
	}
	cout<<"total="<<total;

	
}
