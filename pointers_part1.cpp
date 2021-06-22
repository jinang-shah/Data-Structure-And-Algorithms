#include<conio.h>
#include<iostream>
using namespace std;

class Box{
	private:
		int l,b,h;
	public:
	    void setDimension(int x,int y,int z){
	    	l=x;
	    	b=y;
	    	h=z;
		}	
		void showDimension(){
			cout<<"l="<<l<<endl;
			cout<<"b="<<b<<endl;
			cout<<"h="<<h<<endl;
		}
};


int main(){
	Box b;
	Box *p=&b;
	p->setDimension(10,20,30);
	p->showDimension();
	return 0;
}
