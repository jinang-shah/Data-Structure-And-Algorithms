#include<iostream>
using namespace std;
int substract(int a,int b);

int main()
{
   //int a[20]={10,50,75,190,140,24,84,120,100,60};
   //int a[20]={10,15,20,6,4,9,14,2,25,17};
   int a[20]={50,82,170,43,140,24,16,190,195,199};
   int b[20]={0,0,0,0,0,0,0,0,0,0};
   int c[20];
   int i,l,column,temp,j=0;
   int nearest=substract(a[0],a[1]);
   c[0]=a[0];
   temp=a[0];
   
	for(i=1;i<10;i++){

		l=1;     
		while(l<10 && b[l]!=0){
			l++;
		}
		     			 
		nearest=substract(a[l],temp);	      
				    
   		for(j=1;j<10;j++){
   	   		if(b[j]!=1 && (substract(a[j],temp)<=nearest) && (substract(a[j],temp)!=0)){     	   	 	   	  		
   	   	      		nearest=substract(a[j],temp); 
   	   	      		column=j;					  	  					
			}
   		}
   		b[column]=1; 
   		c[i]= a[column];
   		temp=c[i];
   		 		 
    }
    
    
    for(i=0;i<10;i++){
    	cout<<c[i]<<endl;
	}
    
}

int substract(int a,int b){
	if(a>b)
	    return(a-b);
	else
	    return(b-a);    
}






