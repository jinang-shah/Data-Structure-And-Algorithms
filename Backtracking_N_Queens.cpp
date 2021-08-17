#include<iostream>
#define N 4
using namespace std;

void printSolution(int sol[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool isSafe(int x, int y, int sol[N][N]){
	if(x>=0 && x<N && y>=0 && y<N && (sol[x][y]==0)){
		
		for(int i=0;i<=x;i++){
			if(sol[i][y]==1){
				return false;
			}
		}
		
		for(int i=0;i<=y;i++){
			if(sol[x][i]==1){
				return false;
			}
		}
		
		int prev_x = x-1;
		int prev_y = y-1;
		
		while((prev_x>=0 && prev_x<N && prev_y>=0 && prev_y<N)){
			if(sol[prev_x][prev_y]==1){
				return false;
			}
			prev_x--;
			prev_y--;
		}
		
		int next_y = y+1;
		int next_x = x-1;
		
		while((next_x>=0 && next_x<N && next_y>=0 && next_y<N)){
			if(sol[next_x][next_y]==1){
				return false;
			}
			next_x--;
			next_y++;
		}
		
		return true;
	}
	
	return false;
}

int NqeensUtil(int x, int num_queens, int sol[N][N]){
	cout<<endl;
	printSolution(sol);
	if(num_queens==4){
		return 1;
	}
	
	int next_x = x;
	int next_y[N] = {0,1,2,3};  
	
	for(int i=0;i<N;i++){
		if(isSafe(next_x,next_y[i],sol)){
			sol[next_x][next_y[i]]=1;
			num_queens = num_queens+1;
			cout<<"Queens Count : "<<num_queens<<endl;
			if(NqeensUtil(next_x+1, num_queens, sol)==1){
				return true;
			}
			else{
				num_queens--;
				cout<<"Queens Count : "<<num_queens<<endl;
				sol[next_x][next_y[i]]=0;
				cout<<endl;
				printSolution(sol);
			}
		}
	}
	
}


int solveNQueens(){
	int sol[N][N];
	
	int x=0;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			sol[i][j] = 0;
		}
	}
	
	if(NqeensUtil(0, 0, sol)==0){
		cout<<"No Solution Possible"<<endl;
		return 0;
	}
	else{
		printSolution(sol);
	}
}


int main(){
	solveNQueens();
	return 0;
}
