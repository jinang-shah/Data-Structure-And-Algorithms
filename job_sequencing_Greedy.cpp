+#include<iostream>
#include<algorithm>
using namespace std;

void job_sequencing(struct job jobs[], int n);

struct job{
	char id;
	int dline;
	int profit;
};

bool cmp(job a, job b)
{
     return (a.profit > b.profit);
}

void job_sequencing(job jobs[], int n){
	sort(jobs, jobs+n, cmp);
	bool slot[n];
	int result[n];
	for(int i=0;i<n;i++){
		slot[i]=false;
	}
	
	for(int i=0;i<n;i++){
		for(int j=min(n, jobs[i].dline)-1;j>=0;j--){
			if(slot[j]==false){
				slot[j]=true;
				result[j]=i;
				break;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		if(slot[i]==true){
			cout<<jobs[result[i]].id<<" ";
		}
	}
	
}

int main(){
	job jobs[] = {   {'a', 2, 100}, 
	                    {'b', 1, 19}, 
						{'c', 2, 27},
						{'d', 1, 25}, 
						{'e', 3, 15}
					};
	int n = sizeof(jobs)/sizeof(jobs[0]);
	job_sequencing(jobs, n);
	
	return 0;
}
