#include<iostream>
using namespace std;
void substraction();
//extern int a;
//extern int b;
//extern int c;

int main(){
	typedef int jinang;  //typedef Declarations
	jinang n=5;  
	cout<<n<<endl;
	
	cout<<"hello world!!!!"<<endl;
	cout<<"size of character ="<<sizeof(char)<<endl;
	cout<<"size of integer ="<<sizeof(int)<<endl;
	cout<<"size of long ="<<sizeof(long)<<endl;
	
	enum students {jigo,nem,vedant=5,perk};     //Enumerated Types
	cout<<"....enum...."<<endl;     
	cout<<jigo<<endl;
	cout<<nem<<endl;
	cout<<vedant<<endl;
	cout<<perk<<endl;
	
	float num=50.0000;
	double nu=5.0000;
	cout<<num<<endl;
	cout<<nu<<endl;
	
	int a=1;
	int b=2;
	int c=a+b;
	cout<<"sum="<< c <<endl;
	substraction();
	return 0;
}

void substraction()
{
	int a=2;
	int b=1;
	int c=a-b;
	cout <<"substraction="<< c <<endl;
}









