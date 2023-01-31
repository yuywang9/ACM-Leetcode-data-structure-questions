#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void generateArray(int* arr,int n,int m,int seed){
 	unsigned x=seed;
 	for(int i=1;i<=n;i++){
 	x^=x<<13;
 	x^=x>>17;
 	x^=x<<5;
 	arr[i]=x%m+1;
 	}
}
int main(){
	int n,m,seed;
	while(cin>>n){
		cin>>m;
		cin>>seed;
		int arr[n+1];
		priority_queue<int,vector<int>,std::greater<int>> pq;
		generateArray(arr,n,m,seed);
		for(int i=1;i<=n;i++){
			pq.push(arr[i]);
		}
    	while(pq.size()!=1){
    		int a=pq.top();
    		pq.pop();
    		pq.pop();
			pq.push(2*a);	
		}
		cout<<pq.top()<<endl;
	}
}