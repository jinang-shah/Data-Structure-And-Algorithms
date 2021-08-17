#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

vector<vector<int>> v;


void generate(vector<int> numbers, int index, vector<int> subset){
    if(index >= numbers.size()){
        v.push_back(subset);
        return; 
    }
    
    generate(numbers, index+1, subset);

    subset.push_back(numbers[index]); 
    generate(numbers, index+1, subset);
    subset.pop_back();

    
}



int main(){

	vector<int> numbers = {1,2,3,4};
	vector<int> subset;
	generate(numbers, 0, subset);

    for(auto sub : v){
        for(auto el : sub){
            cout<<el<<" ";
        }
        cout<<endl;
    }

}