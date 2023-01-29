#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	int test;
	cin>>test;
	for(int i=0;i<test;i++){//each test case
		if(i!=0){
			cout<<"\n";
		}
		else{
			int f=1222222;//bullshithaha
		}
		char max;
		cin>>max;
		int size=max-'A'+1;
		int sub[size];
		for(int i=0;i<size;i++){
			sub[i]=i;
		}
		string connect;
		getline(cin, connect);
		while(getline(cin, connect)&&connect!=""){//each operation
			int big;
			int small;
			if(sub[connect[0]-'A']>sub[connect[1]-'A']){
				big=sub[connect[0]-'A'];
				small=sub[connect[1]-'A'];
			}
			else{
				big=sub[connect[1]-'A'];
				small=sub[connect[0]-'A'];
			}
			for(int j=0;j<size;j++){
				if(sub[j]==small){
					sub[j]=big;
				}
			}
		}
		int jud[size];
		int num=0;
		for(int z=0;z<size;z++){
			jud[z]=-1;
		}
		for(int k=0;k<size;k++){
			jud[sub[k]]=sub[k];	
		}
		for(int k=0;k<size;k++){
			if(jud[k]!=-1){
				num++;
			}
		}
		cout<<num<<endl;
	}
}