#include<iostream>
using namespace std;
#define MAX 100;

int countWays(int amount,int coins[], int noOfCoins){
	int ways[noOfCoins+1][amount+1];
	
	for(int i=0;i<=noOfCoins;i++){
		ways[i][0] = 1;
	}
	
	for(int i=1;i<=amount;i++){
		ways[0][i]=0;
	}
	
	for(int i=1;i<=noOfCoins;i++){
		int coin = coins[i-1];
		for(int j=1;j<=amount;j++){
			if(coin>j){
				ways[i][j] = ways[i-1][j];
			}
			else{
				ways[i][j] = ways[i-1][j] + ways[i][j-coin];
			}
		}
	}
	return ways[noOfCoins][amount];
}

int main(){
	int coins[] = {2,3 , 5, 10};
	int noOfCoins = sizeof(coins)/sizeof(coins[0]);
	int amount = 15;
	int ways = countWays(amount, coins, noOfCoins);
	cout<<"No of Ways = "<<ways;
}
