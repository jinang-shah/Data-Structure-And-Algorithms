#include<stdio.h>
#include<string>
#include <iostream>
using namespace std;
void check_loop();

int main(){
	
	int test_cases;
	cin>>test_cases;
	check_loop();
	
	/* string str = "MM FF MF M";
	int male=0,female=0;
    for(int i=0;i<str.length();i++){
    	if(str[i]=='M') male++;
    	else if(str[i]=='F') female++;
	}
	cout<<male<<" "<<female;  */
}


void check_loop(){
	for(int i=0;i<1;i++){
		string str;
		std::getline(std::cin, str);
		cout<<"str = "<<str<<endl;
		int male=0,female=0;
	    for(int i=0;i<str.length();i++){
	    	if(str[i]=='M') male++;
	    	else if(str[i]=='F') female++;
		}
		cout<<male<<" "<<female;
	}
}


