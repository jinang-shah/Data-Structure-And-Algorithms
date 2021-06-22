#include<iostream>
#include<climits> 
using namespace std;

void swap(int *x,int *y);

class MinHeap{
	int capacity;
	int heap_size;
	int *heap;
	
	public:
		
		MinHeap(int cap){
			capacity=cap;
			heap_size=0;
			heap=new int[cap];
		}
		
		int leftChild(int i) {return (2*i)+1;}
		int rightChild(int i) {return (2*i)+2;}
		int parent(int i) {return (i-1)/2;}
		
		void minHeapify(int i);
		void insertKey(int k);
		int extractMin();
};

void MinHeap::insertKey(int val){
	if(heap_size==capacity){
		cout<<"Heap is Full.\n";
		return;
	}
	heap_size++;
	int i=heap_size-1;
	heap[i]=val;
	
	while(i!=0 && heap[i]<heap[parent(i)]){
		swap(&heap[i],&heap[parent(i)]);
		i=parent(i);
	}
}

void MinHeap::minHeapify(int i){
	int left=leftChild(i);
	int right=rightChild(i);
	int smallest=i;
	if(left<heap_size && heap[left]<heap[smallest]){
		smallest=left;
	}
	if(right<heap_size && heap[right]<heap[smallest]){
		smallest=right;
	}
	if(i!=smallest){
		swap(&heap[i],&heap[smallest]);
		minHeapify(smallest);
	}
}

int MinHeap::extractMin(){
	if(heap_size<=0){
		cout<<"Heap is Empty.\n";
		return INT_MAX;
	}
	if(heap_size==1){
		heap_size--;
		return heap[0];
	}
	int root=heap[0];
	heap[0]=heap[heap_size-1];
	heap_size--;
	minHeapify(0);
	return root;
}


void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}


int main(){
	
	
	MinHeap m(10);
	m.insertKey(20);
	m.insertKey(30);
	m.insertKey(50);
	m.insertKey(60);
	cout<<m.extractMin()<<endl;
	cout<<m.extractMin()<<endl;
	cout<<m.extractMin()<<endl;
	cout<<m.extractMin()<<endl;
	cout<<m.extractMin()<<endl;
	return 0;
}
