#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        
        int i=0,j=1;
        
        while(j<(intervals.size())){
            while(intervals[i][1]<intervals[j][0]  && (j<intervals.size())   ){
                v.push_back(intervals[i]);
                i++;
                j++;
            }
            
            vector<int> v1;
            v1.push_back(intervals[i][1]);
            
            while(intervals[i][1] >= intervals[j][0] && (j<intervals.size() )){
                i++;
                j++;
            }
            v1.push_back(intervals[i][1]);
            v.push_back(v1);
            
            if(j==(intervals.size()-1)){
                v.push_back(intervals[j]);
            }
            
        }
        
        return v;
    }
    
    
int main(){
	vector<vector<int, int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
	vector<vector<int, int>> v;
	v = merge(intervals);
	
	for(int i=0;i<v.size();i++){
		cout<<
	}
	
}    
    
    
    
    
