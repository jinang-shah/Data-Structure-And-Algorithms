#include<iostream>
using namespace std;
#define MAX 4

int max_row(int gold[MAX][MAX]){
	int index;
	int max=0;
	for(int i=0;i<MAX;i++){
		if(gold[i][0] > max){
			max = gold[i][0];
			index = i; 
		}
	}
	return index;
}

int maxi(int a,int b){
	return (a>b)? a:b;
}

int min(int a,int b){
	return (a<b)? a:b;
}

int mineGold(int gold[MAX][MAX],int n,int m){
	int prev_index = max_row(gold);
	int count=0;
	count = count + gold[prev_index][0];
	for(int i=1;i<m;i++){
		int max=0;
		int index;
		for(int j=maxi(0,prev_index-1);j<=min(prev_index+1,m);j++){
			if(gold[j][i]>max){
				max = gold[j][i];
				index = j;
			}
		}
		prev_index = index;
		count += max;
	}
	return count;
}

int mineGold_tabu(int gold[MAX][MAX]){
	int m[MAX][MAX];
	 
}



int main(){
	int gold[MAX][MAX] = {{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};
	int m=4,n=4;
	cout<<"Max Gold : "<<mineGold(gold,n,m);
}
