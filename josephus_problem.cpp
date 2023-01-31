#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n,m;
	cin>>n;
	cin>>m;
	vector<int> vect;
	int index_limit=n-1;
	int index=0;
	for(int i=0;i<=index_limit;i++){
		vect.push_back(i+1);
	}
	while(vect.size()!=0){
		if(vect.size()==1){
			cout<<vect.at(0);
			break;
		}
		index+=m-1;
		if(index>index_limit){
			while(index>index_limit){
				index=index-index_limit-1;
			}
			cout<<vect.at(index)<<" ";
			vect.erase(begin(vect)+index);
			index_limit--;
			continue;
		}
		else{
			cout<<vect.at(index)<<" ";
			vect.erase(begin(vect)+index);
			index_limit--;
			continue;
		}	
	}
	cout<<endl;
}