#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
	int arr[] = {-4, 6, 3, 9, 4, 1, 8,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	
	int i=0;
	int j=n-1;
	
	while(i<=j){
	    if(arr[i]<0)
	        i++;
	    if(arr[j]>0)
	        j--;
	    if((arr[i]>0 && arr[j]< 0) && (i<j)){
	        swap(&arr[i],&arr[j]);
	        i++;
	        j--;
	    }     
	}
	
	for(int i=0;i<n;i++){
	    cout<<arr[i]<<" ";
	}
	
	return 0;
}
