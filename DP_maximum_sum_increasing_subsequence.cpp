#include<iostream>
using namespace std;

void MSIC(int a[], int n){
    int dp[n];
    int omax =0;
   
    for(int i=0;i<n;i++){
        int max = 0;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                if(max==0){
                    max = dp[j];
                }
                else if(dp[j]>max){
                    max = dp[j];
                }
            }
        }
       
        if(max==0){
            dp[i] = a[i];
        }
        else{
            dp[i] = max + a[i];
        }
       
        if(dp[i]>omax){
            omax = dp[i];
        }
       
    }
    cout<<omax;
}

int main(){
    int a[] = {3, 4, 5, 10};
    int n = sizeof(a)/sizeof(a[0]);
    MSIC(a, n);
}
