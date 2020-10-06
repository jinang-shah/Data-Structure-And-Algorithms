#include<iostream>
using namespace std;
void display(int arr[],int n);
void bubblesort(int arr[],int n);

int main(){
	int i,n=5,arr[5];	
	for(i=0;i<n;i++)
	   cin>>arr[i];	   
	bubblesort(arr,n);
	display(arr,n);   
}

void display(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	    cout<<arr[i]<<endl;
}

void bubblesort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}





