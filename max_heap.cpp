#include <iostream>
using namespace std;
class maxheap{
	public:
	int amount;
	int *heap;
	int sizelimit;
	int heapsize;
	maxheap(int sizelimit){
		heap=new int[sizelimit];
		amount=0;
		heapsize=0;
		this->sizelimit=sizelimit;
	}
	void insert(int value){
		if(heapsize==sizelimit){
			return;
		}
		else{
			heap[heapsize]=value;
			amount+=value;
			heapify(heapsize);
			heapsize++;
		}
	}
	void heapify(int index){
		if(index>0){
			if(heap[index]>heap[(index-1)/2]){
				int temp;
				temp=heap[index];
				heap[index]=heap[(index-1)/2];
				heap[(index-1)/2]=temp;
				heapify((index-1)/2);
			}
		}
	}
	void pop(){
		if(heapsize>0){
			amount-=heap[0];
			heap[0]=heap[heapsize-1];
			heap[heapsize-1]=0;
			heapsize--;
			adjust(0);
		}
		else{
			return;
		}
	}
	void adjust(int root){
		int largest=root;
		int l=2*root+1;
    	int r=2*root+2;
    	if(l<heapsize&&heap[l]>heap[largest])
        	largest=l;
    	if(r<heapsize&&heap[r]>heap[largest])
        	largest=r;
    	if(largest!=root) {
        	int swap;
			swap=heap[largest];
			heap[largest]=heap[root];
			heap[root]=swap;
        	adjust(largest);
    	}
	}
};
int main(){
	int operations;
	while(cin>>operations){
		maxheap kris=maxheap(120005);
		char instruction;
		for(int i=0;i<operations;i++){
			cin>>instruction;
			if(instruction=='a'){
				int input;
				cin>>input;
				kris.insert(input);
			}
			else if(instruction=='p'){
				kris.pop();
			}
			else if(instruction=='r'){
				cout<<kris.amount<<endl;
			}
		}
	}		
}
