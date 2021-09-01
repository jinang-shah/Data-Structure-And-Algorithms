#include<bits/stdc++.h>
using namespace std;

void max_Area(int a[], int n){

    // Time Complexity : 0(N*N)


    int mas = 0;

    for(int i=0;i<n;i++){
        int l,r;
        int cur_h = a[i];
        for(l=i-1;l>=0;l--){
            if(a[l]<cur_h)
                break;
        }
        for(r=i+1;r<n;r++){
            if(a[r]<cur_h)
                break;
        }
        int area = a[i]*((r-l)-1);
        cout<<"l : "<<l<<" , r : "<<r<<" , Area : "<<area<<endl;
        if(area>mas)
            mas = area;
    }
    cout<<mas;
}

int main(){
    int a[] = {1, 5, 3, 5, 6};
    int n = sizeof(a)/sizeof(a[0]);
    max_Area(a, n);

    return 0;
}