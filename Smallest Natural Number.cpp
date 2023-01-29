#include <iostream>
#include <cstring>
using namespace std;
int arr[1000000];
int main(){
	int nums;
	while(cin>>nums){
		memset(arr, 0, sizeof(arr));
		bool flag=false;
		int tempt;
		for(int i=1;i<=nums;i++){
			cin>>tempt;
			if(tempt>1000000-1){
				continue;
			}//999999999 < 10^9
			else{
				if(tempt==0){
					flag=true;
				}
				arr[tempt]=tempt;
			}
		}
		if(flag==false){
			cout<<0<<endl;
			continue;
		}
		else{
			for(int i=1;i<=1000000-1;i++){
				if(arr[i]==0){
					cout<<i<<endl;
					break;
				}
			}
		}
	}
}