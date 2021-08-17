#include<iostream>
#include<string>
using namespace std;

void findConfig(int cb,int tb,int ssf,int items, string asf){
	if(cb>tb){
		if(ssf == items){
			cout<<asf<<endl;
		}
		return;
	}
    findConfig(cb++, tb, ssf+1, items, asf+"i" );
	findConfig(cb++, tb, ssf, items, asf+"-" );
}
	


int main(){
	int boxes = 4;
    int items = 2;
    findConfig(1, boxes, 0, items,  "");
    return 0;
}
