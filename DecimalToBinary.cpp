#include <string>
#include <iostream>
using namespace std;

int main() {
	string str = "5";
	int n = stoi(str);
	
	string s = "";
	
	while(n>0){
	    s = to_string((n%2)) + s;
	    n = n/2;
	}
	
	cout<<s;
	return 0;
}
