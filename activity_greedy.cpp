#include<iostream>
#include<stdlib.h>
using namespace std;

void activitySelection(int s[], int f[], int n);

void activitySelection(int s[], int f[], int n){
	int i=0;
	cout<<" selected Activites  : ";
	cout<<i<<" ";
	
	for(int j=1;j<n;j++){
		if(s[j]>=f[i]){
			cout<<j<<" ";
			i=j;
		}
	}
}

int main(){
	int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
	int n = sizeof(f)/sizeof(f[0]);
	activitySelection(s, f, n);
	return 0; 
}
