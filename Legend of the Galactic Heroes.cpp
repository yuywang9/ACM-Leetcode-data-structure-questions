#include <iostream>
#include <vector>
using namespace std;
vector<int> father;
vector<int> Ddistance;
vector<int> num_element;
int find(int fc){
	if(fc!=father[fc]){
		int f=father[fc];
		Ddistance[fc]+=Ddistance[f];
		father[fc]=find(father[fc]);
	}
	return father[fc];
}
int main(){
	for(int i=0;i<=30005;i++){
		father.push_back(i);
		num_element.push_back(1);
		Ddistance.push_back(0);
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		char cmd;
		int a;
		int b;
		cin>>cmd>>a>>b;
		if(cmd=='M'){
			int x=find(a);
			int y=find(b);
			Ddistance[x]+=num_element[y];
			father[x]=y;
			num_element[y]+=num_element[x];
    		num_element[x]=0;
		}
		else{
			if(find(a)==find(b)){
				if(Ddistance[a]>Ddistance[b]){
					cout<<Ddistance[a]-Ddistance[b]-1<<endl;
				}
				else{
					cout<<Ddistance[b]-Ddistance[a]-1<<endl;
				}
			}
			else{
				printf("-1\n");
			}
		}
	}
}