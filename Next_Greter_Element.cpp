#include<bits/stdc++.h>
using namespace std;


void nextGreater(int a[], int n){
    stack<int> s;
    int sol[n];

    s.push(a[n-1]);
    sol[n-1]=-1;

    for(int i=n-2;i>=0;i--){

        while( (!s.empty()) && (s.top()<=a[i])){
            s.pop();
        }
        if(s.empty()){
            sol[i]=-1;
        }
        else{
            sol[i] = s.top();
        }
        s.push(a[i]);
    }

    for(int i=0;i<n;i++){
        cout<<sol[i]<<" ";
    }

}

int main(){
    int a[] = {1, 5, 3, 5, 6};
    int n = sizeof(a)/sizeof(a[0]);
    nextGreater(a, n);

    return 0;
}