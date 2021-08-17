#include<iostream>
#define N 4
using namespace std;

int ratMazeUtil(int x, int y, int sol[N][N], int x_moves[], int y_moves[], int path[N][N]);

bool isSafe(int x, int y, int sol[N][N],int path[N][N]){
	if(x>=0 && x<N && y>=0 && y<N && (path[x][y]!=0) && (sol[x][y]==0)){
		return true;
	}
	else{
		return false;
	}
}

void printSolution(int sol[N][N]){
	cout<<endl;
	cout<<endl;
	cout<<"Solution Path :"<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
}

int ratMaze(int path[N][N]){
	int x=0,y=0;
	int sol[N][N];
	int x_moves[2] = {1,0};
	int y_moves[2] = {0,1};
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			sol[i][j] = 0;
		}
	}
	
	sol[0][0]=1;
	
	if(ratMazeUtil(x,y,sol,x_moves,y_moves,path)==0){
		cout<<"no solution"<<endl;
		return 0;
	}
	else{
		printSolution(sol);
	}
	
	return 0;
	
}

int ratMazeUtil(int x, int y, int sol[N][N], int x_moves[], int y_moves[], int path[N][N]){
	
	printSolution(sol);
	
	if((x==N-1) && (y==N-1)){
		return 1;
	}
	
	int next_x,next_y;
	for(int i=0;i<2;i++){
		next_x = x + x_moves[i];
	    next_y = y + y_moves[i];
	    if(isSafe(next_x,next_y,sol,path)){
	    	sol[next_x][next_y] = 1;
	    	printSolution(sol);
	    	if(ratMazeUtil(next_x,next_y,sol,x_moves,y_moves,path)==1){
	    		return 1;
			}
			else{
				sol[next_x][next_y] = 0;
			}
		}
	}
	return 0;
	
}

int main(){
	int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 1, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } 
					};
	ratMaze(maze);
}
