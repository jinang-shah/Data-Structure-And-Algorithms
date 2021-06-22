#include<iostream>
using namespace std;

class car{
	public:
		int weight;
		string color;
		void stop(){
			cout<<"appliing break......";
		}
		void start();
		
};

void car:: start(){
			cout<<"starting engine...."<<endl;
		}

int main(){
	
	car c;
	c.weight=100;
	c.color="red";
	cout<<c.color<<" \n";
	cout<<c.weight<<endl;
	c.start();
	c.stop();
	
	//int n,a[5];
	//for(int i=0;i<5;i++){
	//	cout<<i<<" \n";
	//}
	//cout<<"enter your age : ";
	//cin>>n;
	//cout<<"i'm "<<n<<" years old.\n";
	//cout<<"hello world\n";
	//cout<<"hey there";
	return 0;
}
