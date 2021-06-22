#include<iostream>
using namespace std;
bool isPresentInSegment(int n,int k,int x,int window[]);
int getMax(int arr[],int n);
int getMin(int arr[],int n);
void reverseArray(int arr[],int n);
void reverseArray2(int a[],int start,int end,int n);
void printArray(int arr[],int n);
void sortArray(int arr[],int n);
void KthsmallestElement(int arr[],int n,int k);
void KthlargestElement(int arr[],int n,int k);
void swap(int *x,int *y);
void sort012(int arr[],int n);
void rotateArray(int arr[],int n);
void missingNumber(int arr[],int n);
void countPairsWithGivenSum(int arr[],int n,int sum);
void commonElements(int a[],int b[],int c[],int na,int nb,int nc);
void firstRepetor(int arr[],int n);
int binarySearch(int arr[],int start,int end,int x);
int countNumbers(int arr[],int n,int x);

int main(){
	int a[] = { 1, 2, 2, 3, 3, 3, 3};
	int na= sizeof(a)/sizeof(a[0]);
	
	int b[] = { 1,2,1,2,2,0,0,1,0,1};
	int nb= sizeof(b)/sizeof(b[0]);
	
	int c[] = { 3,5,1,2,6,7};
	int nc= sizeof(c)/sizeof(c[0]);
	
	int d[] = {1,5, 7, -1};
	int nd= sizeof(d)/sizeof(d[0]);
	/*
    int x = 8, k = 2;
    int n= sizeof(a)/sizeof(a[0]);
	bool ans=isPresentInSegment(n,k,x,a);
	if(ans) cout<<"yes";
	else cout<<"no";
		
	cout<<"\nmaximum : "<<getMax(a,n)<<endl;
	cout<<"minimum : "<<getMin(a,n);	
	
	reverseArray(a,n);
	reverseArray2(a,0,n-1,n);
	
	KthsmallestElement(a,n,3);
	KthlargestElement(a,n,1);   
	*/
	//sort012(b,n);
	
	//rotateArray(a,n);
	//missingNumber(c,nc);
	//countPairsWithGivenSum(d,nd,6);
	//commonElements(b,c,d,nb,nc,nd);
	
	//firstRepetor(a,na);
	//cout<<binarySearch(b,0,nb-1,2)<<endl;
	cout<<"Counted "<<countNumbers(a,na,3)<<" times."<<endl;
	return 0;
}

int countNumbers(int arr[],int n,int x){
	//sortArray(arr);
	int ind = binarySearch(arr, 0, n - 1, x); 
  
    // If element is not present 
    if (ind == -1) 
        return 0; 
  
    // Count elements on left side. 
    int count = 1; 
    int left = ind - 1; 
    while (left >= 0 && arr[left] == x) 
        count++, left--; 
  
    // Count elements on right side. 
    int right = ind + 1; 
    while (right < n && arr[right] == x) 
        count++, right++; 
  
    return count; 
}

int binarySearch(int arr[],int start,int end,int x){
	if(end>=start){
		int mid=start+ (end-start)/2;
		if(arr[mid]==x){
			return mid;
		}
		else{
			if(x<arr[mid]){
				return binarySearch(arr,start,mid-1,x);
			}
			else{
				return binarySearch(arr,mid+1,end,x);
			}
		}
	}
   return -1;		
}
	


void firstRepetor(int arr[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=1;j<n;j++){
			if(arr[i]==arr[j]){
				break;
			}
		}
		if(arr[j]==arr[i]){
			break;
		}
	}
	if(arr[j]==arr[i]){
			cout<<"first Repeting Element : "<<arr[j]<<endl;
		}
	else cout<<"NO Repeted Elements.\n";	
}

void commonElements(int a[],int b[],int c[],int na,int nb,int nc){
	for(int i=0;i<na;i++){
		//cout<<"\ni : "<<i;
		int j;
		for(j=0;j<nb;j++){
		   //cout<<"\nj : "<<j;
		   if(b[j]==a[i]) break;
	    }
	    if(j==nb) continue;
	    int k;
	    for(k=0;k<nc;k++){
	      // cout<<"\nk : "<<k;
		   if(c[k]==a[i]) break;
	    }
	    if(k!=nc) cout<<a[i]<<" ";
	}
}



void countPairsWithGivenSum(int arr[],int n,int sum){
	int count=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
		  if((arr[j]+arr[i])==sum) count++;
	    }
	}
	cout<<"total pairs : "<<count;
}


void missingNumber(int arr[],int n){
	sortArray(arr,n);
	for(int i=0;i<n;i++){
		if(arr[i]!=i+1){
			cout<<"\nMissing Number : "<<i+1;
			return;
		}
	}
	
}

void rotateArray(int arr[],int n){
	int temp=arr[n-1];
	for(int i=n-1;i>0;i--){
		arr[i]=arr[i-1];
	}
	arr[0]=temp;
	
	cout<<"\nRotate Array : ";
	printArray(arr,n);
}

void sort012(int arr[],int n){
	int a=0,b=0,c=0;
	for(int i=0;i<n;i++){
		if(arr[i]==0) a++;
		else if(arr[i]==1) b++;
		else c++;
	}
	for(int i=0;i<n;i++){
		if(i<a ) arr[i]=0;
		else if(i>a-1 && i<a+b) arr[i]=1;
		else arr[i]=2;
	}
	
	cout<<"\nsort 0,1,2 : ";
	printArray(arr,n);
}

void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

void KthsmallestElement(int arr[],int n,int k){
   sortArray(arr,n);
   cout<<"\nsmallest element : "<<arr[k-1];	
}

void KthlargestElement(int arr[],int n,int k){
   sortArray(arr,n);
   cout<<"\nLargest element : "<<arr[n-k];	
}

void sortArray(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int min=arr[i];
		int col;
		for(int j=i+1;j<n;j++){
			if(arr[j]<min){
				col=j;
				min=arr[j];
			}
		}
		int temp=arr[i];
		arr[i]=min;
		arr[col]=temp;
	}
	
	cout<<"\nsorted Array : ";
	printArray(arr,n);
}



void reverseArray2(int arr[],int start,int end,int n){
	while (start < end)
    {
        int temp = arr[start]; 
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    } 
	cout<<"\nreverse array(method 2) : ";
	printArray(arr,n);
	
}

void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<", ";
	}
}

void reverseArray(int arr[],int n){
	int mid=n/2;
	for(int i=0;i<=mid;i++){
		if(i==mid){
			if(n%2==0){
			  int temp=arr[i];
			  arr[i]=arr[n-i-1];
			  arr[n-i-1]=temp;
		    }
		}
		int temp=arr[i];
		arr[i]=arr[n-i-1];
		arr[n-i-1]=temp;
	}
	cout<<"\nreverse array : ";
	printArray(arr,n);
}


bool isPresentInSegment(int n,int k,int x,int window[]){
	int i;
   for(i=0;i<n;i=i+k){
   	cout<<"i :"<<i<<endl;
   	int j;
   	  for(j=0;j<k;j++){
   	      if(window[i+j]==x) break;
      }
	  if(j==k) return false; 
   }
   cout<<"i ::"<<i<<endl;
   if(i==n) return true;	
   
   int j;
   for(j=i-k;j<n;j++){
   	  cout<<j<<endl;
   	  if(window[j]==x) break;
   }
   if(j==n) return false;
   
   return true;
}


int getMax(int arr[],int n){
  	int max=arr[0];
  	for(int i=1;i<n;i++){
  		if(arr[i]>max) max=arr[i];
	  }
	return max;  
}

int getMin(int arr[],int n){
  	int min=arr[0];
  	for(int i=1;i<n;i++){
  		if(arr[i]<min) min=arr[i];
	  }
	return min;  
}
