#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > v;

void findSubset(vector<int> &numSet, int i, int curTotal, int remTotal, int finalSum,vector<int> &subset){
	
	if(curTotal>finalSum || i>numSet.size () || (finalSum-curTotal)>remTotal){
		return;
	}
	if(curTotal==finalSum){
		v.push_back(subset);
		return;
	}

	findSubset(numSet, i+1, curTotal, remTotal-numSet[i], finalSum,subset);

    subset.push_back(numSet[i]);
	findSubset(numSet, i+1, curTotal+ numSet[i], remTotal-numSet[i], finalSum,subset);
    subset.pop_back();
}


int main(){
	vector<int> numSet = {10,20,30,40,50,60,70,80,90,100};
    int totalSum = 0;
	for(int i = 0; i < numSet.size();i++){
		totalSum += numSet[i];
	}
    int finalSum = 100;
	vector<int> subset;
	findSubset(numSet, 0, 0,totalSum, finalSum, subset);

	for(auto sub: v){
		for(auto ele:sub){
			cout<<ele<<" ";
		}
		cout<<endl;
	}

}