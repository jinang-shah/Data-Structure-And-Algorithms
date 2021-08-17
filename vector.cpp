#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	vector<int> g1;
	g1.push_back(10);
	g1.push_back(20);
	g1.push_back(30);
	g1.push_back(40);
	
	cout<<"Size : "<<g1.size()<<endl;
	cout<<"Capacity : "<<g1.capacity()<<endl;
	cout<<"Max Size : "<<g1.max_size()<<endl;
	
	for(int i=0;i<g1.size();i++){
		cout<<g1[i]<<" ";
	}
	
	cout<<endl;
	
	int *p1 = new int[10];
	for(int i=0;i<10;i++){
		*(p1+i) = i*10;
	}
	
	for(int i=0;i<10;i++){
		cout<<*(p1+i)<<" ";
	}
	
	
	cout<<endl;
	
	
	vector<vector<int> > vec;
	
	for(int i=0;i<3;i++){
		vector<int> v1;
		for(int j=0;j<3;j++){
			v1.push_back(j*(i*10));
		}
		vec.push_back(v1);
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
}
