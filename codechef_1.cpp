#include <iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
#include <cctype>
#include <ctype.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    string s;
	    cin>>s;
        int len = s.length();
        char tag[len+1];
        strcpy(tag, s.c_str());
        
        if(len<4){
            cout<<"Error\n";
        	continue;
        }
        
        if(tag[0]!='<' || tag[1]!='/' || tag[len-1]!='>'){
        	cout<<"Error\n";
        	continue;
    	}
    	
    	if(tag[2]==' '){
            cout<<"Error\n";
        	continue;
        }
    	
    	int j;
    	for(j=2;j<len-1;j++){
    		if(!(isdigit(tag[j])) && !(isalpha(tag[j])) ){
    	        cout<<"Error\n";
    	        break;
    	    }
    	    if(isalpha(tag[j])){
    	    	if(isupper(tag[j])){
    	    	    cout<<"Error\n";
    	        	break;
    			}
    		}
    	}
    	if(j==(len-1)){
    		cout<<"Success\n";
    	}
	}
	return 0;
}

/*
if(tag[0]!='<' || tag[1]!='/' || tag[len-1]!='>'){
	        cout<<"Error\n";
	        continue;
	    }
	    else{
	        for(int j=1;j<len-1;j++){
	            if(!(isdigit(tag[j])) && !(isalpha(tag[j])) ){
	                cout<<"Error\n";
	                break;
	            }
	            if(isalpha(tag[j])){
	                if(isupper(tag[j])){
	                    cout<<"Error\n";
	                    break;
	                }
	            }
	            else{
	                cout<<"Success\n";
	            }
	        }
	    }

*/


/*
tic tac toi

#include <iostream>
#include<string>
using namespace std;


bool isWinner(int t[][],char player,int n, int m, int k){
    for(int i=0;i+k<n;i++){
        for(int j=0;j+k<m;j++){
            if(t[i][j] == player && t[])
        }
    }
}

int main() {
	int t;
	for(int x=0;x<t;x++){
	    int m,n,k;
	    string winner;
	    cin>>n>>m>>k;
	    
	    char t[n][m];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            t[n][m]=-1;
	        }
	    }
	    
	    for(int i=0;i<m*n;i++){
	        int x,y;
	        cin>>x>>y;
	        x=x-1;
	        y=y-1;
	        if(i%2==0){
	            t[x][y] = 'a';
	        }
	        else{
	            t[x][y] = 'b';
	        }
	         
	    }
	    
	}
	return 0;
}



*/

