#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    int size;
    while(cin>>size){
    	priority_queue<int ,vector<int>, greater<int> > node; 
    	for(int i=0;i<size;i++){
    		int val;
    		cin>>val;
    		node.push(val);
		} //ascendent
     	int sum=0;
     	while(node.size()!=1){
			int a1=node.top();
			node.pop();
     		int a2=node.top();
     		node.pop();
			int tot=a1+a2;
			sum+=tot;
     		node.push(tot);
		 }
		cout<<sum<<endl;
	}
} 