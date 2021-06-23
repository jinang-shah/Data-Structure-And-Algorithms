#include<iostream>
using namespace std;

int toggle(int x);

bool sos(int set[],int n,int sum){      // sos = sum of subset 
	if (sum == 0)                       // time complexity : exponential (approch : brute force).
        return true;
    if (n == 0)
        return false;
        
    if(set[n-1] > sum){
    	return sos(set, n-1, sum);
	}    
	   
	return sos(set, n-1, sum)  ||  sos(set, n-1, sum-set[n-1]);
}

int dp_sos(int set[],int n, int sum){      //time complexity : 0(sum*n)
	bool dp[n+1][sum+1];
	
	for(int i=0;i<=n;i++)
	    dp[i][0]=true;
	
	for(int i=1;i<=sum;i++)
	    dp[0][i]=false;
	    
	for(int i=1;i<=n;i++){
		int val = set[i-1];
		for(int j=1;j<=sum;j++){
			if(val>j){
				dp[i][j] = dp[i-1][j];
			}
			if(val<=j){
				dp[i][j] = dp[i-1][j]  || dp[i-1][j-val];
			}
		}
	} 
	
	/* print dp[][] table
	for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", dp[i][j]);
       printf("\n");
     }  */
	
	return dp[n][sum];   
	
}

int dp_sos_2(int set[],int n, int sum){            //time complexity : 0(sum*2)
	bool dp[2][sum+1];
	
	dp[0][0]=true;
	dp[1][0]=true;
	
	for(int i=1;i<=sum;i++)
	    dp[0][i]=false;
	
	int prev = 0;
	int cur = 1;
	int count = 1;
	while(count!=n+1){
		for(int i=1;i<=sum;i++){
		    if(set[count]<i){
		    	dp[cur][i] = dp[prev][i];
			}
			else if(dp[prev][i] == true){
				dp[cur][i] = true;
			}
			else{
				dp[cur][i] = dp[prev][i-set[count]];
			}
    	}	
    	cur =  toggle(cur);
		prev =  toggle(prev);
		count++;
		//error
	}
	return dp[n][sum];      
}


int toggle(int x){
	return (x==1)? 0:1;
}


int main(){
	int set[] = { 10,20,30,40 };
    int sum = 100;
	int n = sizeof(set)/sizeof(set[0]); 
	if (dp_sos(set, n, sum) == true)
        printf("TRUE");
    else
        printf("FALSE");
    return 0;
}
