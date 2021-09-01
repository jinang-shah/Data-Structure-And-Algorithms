#include<bits/stdc++.h>
#define N 9 
using namespace std;

vector<vector<vector<int>>>  allSol;

void printSudoku(int grid[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int grid[N][N], int x, int y, int num){
    for(int i=0;i<N;i++){
        if(grid[i][y]==num || grid[x][i]==num){
            return false;
        }
    }
    /*
    int x_t = (x/3)*2;
    int y_t = (y/3)*2;  
    */
    int x_t = x - x % 3,
        y_t = y - y % 3;

    for(int i=x_t;i<x_t+3;i++){
        for(int j=y_t;j<y_t+3;j++){
            if(grid[i][j]==num){
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int grid[N][N], int x, int y){
    if(x==N-1 && y==N){
        return true;
    }

    if (y == N) {
        x++;
        y = 0;
    }

    if(grid[x][y]>0){
        return solveSudoku(grid, x, y+1);
        
    }

    for(int i=1;i<=N;i++){
        if(isSafe(grid, x, y, i)==true){
            grid[x][y]=i;
            if(solveSudoku(grid, x, y+1)==true){
                return true;
            }
            
        }
        grid[x][y]=0;
    }
    return false;
}



int main(){
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };              

    if(solveSudoku(grid, 0, 0)==false){
        cout<<"NO Solution\n";
    }
    else{
        printSudoku(grid);
    }

    
    return 0;               
}
