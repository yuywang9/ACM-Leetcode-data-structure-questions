#include <iostream>
#include <vector>
#include <iterator> 
#include <algorithm>
using namespace std;
bool check(vector<int>& vec){
	for(int i=1;i<vec.size();i++){
		if(vec[0]>=vec[i]){
			continue;
		}
		else{
			return false;
		}
	}
	return true;
}
int main(){
	int times,jobs,position;
	cin>>times;
	for(int i=0;i<times;i++){
		int pop=0;
		int temp;
		int jud=true;
		cin>>jobs;
		cin>>position;
		vector<int> kris(jobs);
		vector<int> sorted(jobs);
		for(auto& i : kris){
			cin>>(i);
		}
		sorted=kris;
		sort(sorted.rbegin(),sorted.rend());
		while(sorted!=kris){
			while(check(kris)){
				kris.erase(kris.begin());
				pop++;
				if(position==0){
					jud=false;
					break;
				}
				else{
					position--;
				}
				sorted.erase(sorted.begin());
			}
			if(jud==false){
				break;
			}
			temp=kris[0];
			kris.erase(kris.begin());
			kris.push_back(temp);
			if(position==0){
				position=kris.size()-1;
			}
			else{
				position--;
			}
		}
		if(jud==false){
			if(i==times-1){
				cout<<pop<<endl;
			}
			else{
				cout<<pop<<endl;
			}
		}
		else{
			if(i==times-1){
				cout<<position+pop+1<<endl;
			}
			else{
				cout<<position+pop+1<<endl;
			}
		}
	}	
}
