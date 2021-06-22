#include<iostream>
#include<list>
#include <bits/stdc++.h>
using namespace std;


struct Item{
	int val,weight;
};

bool comp(struct Item a,struct Item b){
	double r1 = (double)a.val/a.weight;
	double r2 = (double)b.val/b.weight;
	return r1>r2;
}

double knapsack(struct Item arr[], int size , int cap){
	sort(arr, arr+size, comp);
	double profit=0.0;
	int curWeight=0;
	for(int i=0;i<size;i++){
		if (curWeight + arr[i].weight <= cap) {
            curWeight += arr[i].weight;
            profit += arr[i].val;
        }
		
		else {
            int remain = cap - curWeight;
            profit += arr[i].val
                          * ((double)remain
                             / arr[i].weight);
  
            break;
        }
		
	}
	return profit;
}

int main(){
	Item arr[] = { { 100, 10 },
                   { 280, 40 },
                   { 120, 20 },
                   { 120, 24 } };
	int cap = 60;
	int size = sizeof(arr)/sizeof(arr[0]);
	double profit = knapsack(arr, size , cap);
	cout<<"Profit  : "<<profit;
}
