#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
	int length;
	long long C;
	while(cin>>length){
		cin>>C;
		long long pairs=0;
		vector<int> prep_sort;//create a vector for sorting 
		for(int i=0;i<length;i++){
			long long num;
			cin>>num;
			prep_sort.push_back(num);
		}
		sort(prep_sort.begin(),prep_sort.end());
		map<long long, long long> dic;
		int count=1;
		for(int i=0;i<prep_sort.size();i++){
			if(i==prep_sort.size()-1){
				if(prep_sort[i]==prep_sort[i-1]){
					dic[prep_sort[i]]=count;
				}
				else{
					dic[prep_sort[i]]=1;
				}
			}
			if(prep_sort[i]==prep_sort[i+1]){
    			count++;
    		}
    		else{
    			dic[prep_sort[i]]=count;
    			count=1;
			}
		}
		map<long long,long long>::iterator iter;
		for(iter=dic.begin();iter!=dic.end(); iter++){
			auto it=dic.find((iter->first)+C);
			if(it!=dic.end()){
				pairs+=(iter->second)*(it->second);
			}
			else{
				continue;
			}	
		} 
		cout<<pairs<<endl;
	}
}