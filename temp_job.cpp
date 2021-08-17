#include <iostream>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

void job_sequencing(struct job jobs[], int n);

struct job{
  char jobId;
  int dline;
  int profit;
};

bool cmpJob(job j1, job j2){
    return (j1.profit > j2.profit);
}

void jobSequence(job jobs[],int n){
	
    sort(jobs, jobs+n, cmpJob);
    
    bool slot[n];
    int result[n];
    
    for(int i=0;i<n;i++){
        slot[i]=false;
    }
    
    for(int i=0;i<n;i++){
        for(int j=min(n, jobs[i].dline)-1;j>=0;j--){
            if(slot[j]==false){
                slot[j]=true;
                result[j] = i;
                break;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(slot[i]==true){
            cout<<jobs[result[i]].jobId<<" "; 
        }
    }
    
    
    
}

int main() {
    
    job jobs[] = {   {'a', 2, 100}, 
	                    {'b', 1, 19}, 
						{'c', 2, 27},
						{'d', 1, 25}, 
						{'e', 3, 15}
					};
	int n = sizeof(jobs)/sizeof(jobs[0]);				
    jobSequence(jobs, n);					
	return 0;
}

