#include<bits/stdc++>
using namespace std;

vector<string> sol;

bool findPermutations(string s, int n, string curString, int curLength){
    
    if(curLength==n){
        sol.push_back(curString);
    }

    findPermutations()


}

int main(){
    string s = "jinang";
    int n = s.length();
    findPermutations(s, n, "", 0);
}