#include <iostream>
#include<string>
#include <vector>
using namespace std;
int main(){
	int m,n,word;
	int search=0;
	int jud=false;
	vector<int> memory;
	int arr[1000];
	cin>>m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>word;
		arr[i]=word;
	}
	for(int i=0;i<n;i++){
		jud=false;
		for(int j=0;j<memory.size();j++){
			if(arr[i]==memory[j]){
				jud=true;
				break;
			}
			else{
				continue;
			}
		}
		if(jud==false){
			search++;
			memory.push_back(arr[i]);
			if(memory.size()>m){
				vector<int>::iterator k=memory.begin();
   				memory.erase(k);
			}
		}
	}
	cout<<search<<endl;
}