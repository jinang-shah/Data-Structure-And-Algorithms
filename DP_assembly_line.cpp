#include<iostream>
#define STATION 4
#define LINE 2 
using namespace std;

int min(int a, int b){
	return (a>b)? b:a;
}

void assembly(int sc[][STATION],int lcc[][STATION],int e[],int x[]){
	int l1 = 0;   //line 1
	int l2 = 1;   //line 2
	
	int dp[LINE][STATION+1];
	
	int path[LINE][STATION];
	
	dp[l1][0]=dp[l2][0]=0;
	
	dp[l1][1] = sc[l1][0] + e[l1]; 
	dp[l2][1] = sc[l2][0] + e[l2];
	
	for(int i=2;i<=STATION;i++){
		dp[l1][i] = min(dp[l1][i-1] + sc[l1][i-1], dp[l2][i-1] + sc[l1][i-1] + lcc[l2][i-1] ); 
		dp[l2][i] = min(dp[l2][i-1] + sc[l2][i-1], dp[l1][i-1] + sc[l2][i-1] + lcc[l1][i-1] ); 
	}
	
	int final_cost = min(dp[l1][STATION] + x[l1], dp[l2][STATION] + x[l2]);
	
	for(int i=0;i<LINE;i++){
		for(int j=0;j<=STATION;j++){
			cout<<" "<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<final_cost;
}

int main(){
	
	// sc = station cost
	int sc[LINE][STATION] = {{4, 5, 3, 2},           
                            {2, 10, 1, 4}};
    
	// lcc = line change cost                        
    int lcc[LINE][STATION] = {{0, 7, 4, 5},           
                            {0, 9, 2, 8}};  
	
	int e[] = {10, 12};   // entry
	int x[] = {18, 7};	  // exit					                      
	
	assembly(sc,lcc,e,x);
	
}
