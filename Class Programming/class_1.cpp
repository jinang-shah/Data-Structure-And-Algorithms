#include<iostream>
using namespace std;

class BankAccount{
	private:
		int bal;
		
	public:
	    
		BankAccount(int bal){
			this->bal=bal;
		}	
		
		void debitAmount(int amt){
			if(amt<this->bal){
				cout<<endl<<"Amount Debited Successfully"<<endl;
				cout<<"Old Balance  : "<<this->bal<<endl;
				this->bal -= amt;
				cout<<"New Balance  : "<<this->bal<<endl;
			}
			else{
				cout<<endl<<"Sorry !!Debit Amount is Greater than Balance "<<endl;
			}
		}
		
		void creditAmount(int amt){
			cout<<endl<<"Amount Credited Successfully"<<endl;
			cout<<"Old Balance  : "<<this->bal<<endl;
			this->bal += amt;
			cout<<"New Balance  : "<<this->bal<<endl;
		}
		
		void showBalance(){
			cout<<endl<<"Current Balance : "<<this->bal<<endl;
		}
};

int main(){
	BankAccount b1(100);
	b1.showBalance();
	b1.creditAmount(500);
	b1.debitAmount(1000);
	b1.showBalance();
	return 0;
}
