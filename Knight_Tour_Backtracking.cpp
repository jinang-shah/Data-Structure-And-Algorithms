#include<iostream>
#define N 8
using namespace std;

void printSolution(int sol[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<n;j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool isSafe(int x, int y, int sol[N][N]){
	if(x>=0 && x<N && y>=0 && y<N && sol[x][y]==-1){
		return true;
	}
	else{
		return false;
	} 
}


int solveKt(){
	int x=0,y=0;
	int sol[N][N];
	
	int x_move[N] = {2, 1, -1, -2, -2, -1, 1, 2 };
	int y_move[N] = { 1, 2, 2, 1, -1, -2, -2, -1};
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sol[i][j]=-1;
		}
	}
	
	sol[x][y] = 0;
	
	if(solveKtUtil(x,y,1,sol,x_move,y_move)==0){
		cout<<"No solution found"<<endl;
		return 0;
	}
	else{
		printSolution(sol);
	}
	
	
}

int solveKtUtil(int x,int y,int move,int sol[N][N],int x_move[N],int y_move[N]){
	for(int i=0;i<N;i++){
		next_y = y + y_move[i];
		next_x = x + x_move[i];
		if(isSafe(next_x,next_y,sol)){
			sol[next_x][next_y] = move;
			if(solveKtUtil(next_x,next_y,move+1,sol,x_move,y_move)==1){
				return 1;
			} 
			else{
				sol[next_x][next_y] = -1;
			}
			
		}
	}
	return 0;
}


int mian(){
	solveKt();
	return 0;
}
