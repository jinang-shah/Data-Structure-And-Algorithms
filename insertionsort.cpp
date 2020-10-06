#include<iostream>
using namespace std;
void display(int arr[],int n);
void insertionsort(int arr[],int n);

int main()
{
	int i,n,arr[5];
	n=5;
	for(i=0;i<n;i++)
		cin>>arr[i];
	insertionsort(arr,n);
	display(arr,n);
}

void display(int arr[],int n)
{
	int i;
	cout<<"....insertion sort...."<<endl;
	for(i=0;i<n;i++)
		cout<<arr[i]<<endl;
}
void insertionsort(int arr[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=i;j>=0;j--)
		{
			if(arr[j]<arr[j-1])
			{
				int temp;
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
		}
	}
	
}
