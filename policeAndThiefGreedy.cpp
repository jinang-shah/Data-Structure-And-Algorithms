#include<iostream>
using namespace std;

void caughtThief(char arr[],int k,int n){
	int count=0;
	for(int i=0;i<n;i++){
		if(arr[i]=='P'){
			int temp = max(i-2,0);
			bool flag = true;
			for(int j=temp;j<i;j++){
				if(arr[j]=='T'){
					count++;
					flag = false;
					break;
				}
			}
			
			if(flag){
				int temp = min(i+2,n);
				for(int j=temp;j<i;j++){
					if(arr[j]=='T'){
						count++;
						flag = false;
						break;
					}
			    }
			}
		}
	}
	cout<<"Total thieves caught : "<<count;
}

int main(){
	char arr[] = { 'T', 'T', 'P', 'P', 'T', 'P' };
    int k = 2;
	int n = sizeof(arr)/sizeof(arr[0]);
	caughtThief(arr,k,n);
}
