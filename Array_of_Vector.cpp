#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
	vector<int> a[3];
	
	a[0].push_back(1);
	a[0].push_back(2);
	a[0].push_back(3);
	a[0].push_back(4);
	a[0].push_back(5);
	
	a[1].push_back(2);
	a[1].push_back(3);
	a[1].push_back(4);
	a[1].push_back(5);
	a[1].push_back(1);
	
	a[2].push_back(3);
	a[2].push_back(4);
	a[2].push_back(5);
	a[2].push_back(1);
	a[2].push_back(2);
	
	for (int i = 0; i < 3; i++) {
  
        cout << "Elements at index "
             << i << ": ";
  
        for (auto it = a[i].begin();it != a[i].end(); it++) {
  
            cout << *it << ' ';
        }
        cout << endl;
}
	return 0;
}
