#include<iostream>
using namespace std;
void selectionsort(int arr[],int n);
void display(int arr[],int n);

int main(){
	int i,n,arr[5];
	n=5;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	selectionsort(arr,n);
	display(arr,n);
	return 0;
}

void display(int arr[],int n)
{
	int i;
	cout<<"....sorted array...."<<endl;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}

void selectionsort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[i])
			{
				int temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}


