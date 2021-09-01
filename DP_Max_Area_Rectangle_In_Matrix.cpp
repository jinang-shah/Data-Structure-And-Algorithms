class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        int a[MAX][MAX];
        memset(a, 0, sizeof(a[0][0]*MAX*MAX));
        
        int max_overall=0;
        
        for(int i=0;i<MAX;i+++){
            for(int j=0;j<MAX;j++){
                if(i==0){
                    a[i][j]=M[i][j];
                }
                else{
                    if(M[i][j]==0)
                        a[i][j]=0;
                    else
                        a[i][j] += M[i-1][j];
                }
            }

            int left_small[MAX],right_small[MAX];
            
            stack<int> s;
            right_small[MAX-1]=MAX;
            s.push(MAX[i][MAX-1])
            
            for(int x=MAX-2;x>=0;x--){
                while((!s.empty()) && (s.top() >= a[i][r])  ){
                    s.pop();
                }
                if(s.empty()){
                    right_small[x]=MAX
                }
                else{
                    right_small[x]=s.top()
                }
                s.push(a[i][x]);
            }   
            
            //empty queue
            while(!s.empty()){
                s.pop();
            }
            
            
            left_small[0]=-1;
            s.push(MAX[i][0])
            
            for(int x=1;x<MAX;x++){
                while((!s.empty()) && (s.top() >= a[i][r])  ){
                    s.pop();
                }
                if(s.empty()){
                    left_small[x]=-1
                }
                else{
                    left_small[x]=s.top()
                }
                s.push(a[i][x]);
            } 

            int max_row=0;
            int left,right;
            
            for(int x=0;x<MAX;x++){
                left = left_small[x];
                right = right_small[x];
                
                int height = a[i][x];
                int width = right - left -1;
                
                int area = height*width;
                if(area>max_row)
                    max_row=area;
            }
            if(max_row>max_overall)
                max_overall=max_row;
            }
        }
        return mas;
        
    }
};