#include<iostream>
#include<string>
#include<stack>

using namespace std;
int top=-1;

int precedence(char c){
	if(c =='+' || c=='-')
		return 1;
	
	else if(c=='*' || '/')
		return 2;
		
	else if(c=='^')
	    return 3;	
	 
	else 
	    return -1;    
}

bool isOperator(char c){
	if(c=='-' || c=='+' || c=='*' || c=='/' || c=='^') return true;
	else return false;
}


int main(){
	stack<int> stack;
	string infix= "a+b*c+d";
	string ns;
	for(int i=0;i<infix.length();i++){
		char temp=infix[i];
		
		if((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z'))
           ns+=temp;
		
		else if(isOperator(temp)){
			if(stack.empty()) stack.push(temp);
			else{
				while(precedence(stack.top()) >= precedence(temp) ){
					char c=stack.top();
					ns=ns + c;
				}
				stack.push(temp);
			}
		}
		
		else if(temp=='(') stack.push(temp);
		
		else if(temp){
			while(stack.top() != '('){
				char c = stack.top();
				ns = ns + c;
				stack.pop();
			}
			stack.pop();
		}
		 
		
		
		
	}
	while(!stack.empty()){
		char c = stack.top();
		ns = ns + c; 
		stack.pop();
	}
	cout<<"PostFix : "<<ns;
	return 0;
}
