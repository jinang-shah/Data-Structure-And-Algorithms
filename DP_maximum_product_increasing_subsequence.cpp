#include<iostream>
using namespace std;

void MPIS(int a[], int n){
    int dp[n];
    int omax =0;
   
    for(int i=0;i<n;i++){
        int max = 1;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                 if(dp[j]>max){
                    max = dp[j];
                }
            }
        }
       
        if(max==1){
            dp[i] = a[i];
        }
        else{
            dp[i]  = max*a[i];
        }
       
        if(dp[i]>omax){
            omax = dp[i];
        }
       
    }
    cout<<omax;
}

int main(){
    int a[] = {10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(a)/sizeof(a[0]);
    MPIS(a, n);
}
